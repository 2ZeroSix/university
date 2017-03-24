#define _POSIX_C_SOURCE 200112L
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <wctype.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <wchar.h>
typedef int (*handler)(int terminal, wchar_t wc, wchar_t* curStr, size_t* strWidth, size_t maxStrWidth);
typedef struct termios termios;

termios* setTerminalAttr(int terminal) {
    termios *newAttr = (termios*)calloc(1, sizeof(termios));
    if (newAttr == NULL)                                            return NULL;
    if (tcgetattr(terminal, newAttr) == -1)         {free(newAttr); return NULL;}
    newAttr->c_lflag     &= ~(ICANON | ECHO);
    newAttr->c_cc[VTIME] = 0;
    newAttr->c_cc[VMIN]  = 1;
    if (tcflush(terminal, TCIFLUSH) == -1)          {free(newAttr); return NULL;}
    if (tcsetattr(terminal, TCSANOW, newAttr) == -1){free(newAttr); return NULL;}
    return newAttr;
}

int endOfRead(int terminal, wchar_t wc, wchar_t* curStr, size_t* strWidth, size_t maxStrWidth) {
    if (*curStr == 0) {
        return 1;
    } else {
        return 0;
    }
}

int eraseLine(int terminal, wchar_t wc, wchar_t* curStr, size_t* strWidth, size_t maxStrWidth) {
    if (write(terminal, "\r", strlen("\r")) == -1) return -1;
    for (size_t i = 0; i < *strWidth; ++i)
        if (write(terminal, " ", strlen(" ")) == -1) return -1;
    if (write(terminal, "\r", strlen("\r")) == -1) return -1;
    wmemset(curStr, L'\0', *strWidth);
    *strWidth = 0;
    return 0;
}

int eraseWord(int terminal, wchar_t wc, wchar_t* curStr, size_t* strWidth, size_t maxStrWidth) {
    size_t len = wcslen(curStr);
    size_t wordLen;
    for (wordLen = 0; wordLen < len; ++wordLen)
        if (!iswspace(curStr[len - wordLen - 1])) break;
    for (; wordLen < len; ++wordLen)
        if (iswspace(curStr[len - wordLen - 1])) break;
    for (size_t i = 0; i < wordLen; ++i) {
        for (int j = 0; j < wcwidth(curStr[len - i - 1]); ++j) 
            if (write(terminal, "\b \b", strlen("\b \b")) == -1) return -1;
        *strWidth -= wcwidth(curStr[len - i - 1]);
        curStr[len - i - 1] = 0;
    }
    return 0;
}

int eraseWchar(int terminal, wchar_t wc, wchar_t* curStr, size_t* strWidth, size_t maxStrWidth) {
    size_t len = wcslen(curStr);
    for (int i = 0; i < wcwidth(curStr[len ? len - 1 : len]); ++i)
        if (write(terminal, "\b \b", strlen("\b \b")) == -1) return -1;
    *strWidth -= wcwidth(curStr[len ? len - 1 : 0]);
    curStr[len ? len - 1 : 0] = 0;
    return 0;
}

int printNewLine(int terminal, wchar_t wc, wchar_t* curStr, size_t* strWidth, size_t maxStrWidth) {
    if (write(terminal, "\n", strlen("\n")) == -1) return -1;
    wmemset(curStr, 0, *strWidth);
    *strWidth = 0;
    return 0;
}

int printHorn(int terminal, wchar_t wc, wchar_t* curStr, size_t* strWidth, size_t maxStrWidth) {
    if (write(terminal, "\007", strlen("\007")) == -1) return -1;
    return 0;
}

int printWchar(int terminal, wchar_t wc, wchar_t* curStr, size_t* strWidth, size_t maxStrWidth) {
    size_t len = wcslen(curStr);
    if (*strWidth + wcwidth(wc) > maxStrWidth) {

        size_t lastWordLen = 0;
        if (!iswspace(wc))
            for (lastWordLen = 0; lastWordLen < len; ++lastWordLen)
                if (iswspace(curStr[len - 1 - lastWordLen])) break;
        size_t lastWordWidth = wcswidth(curStr + len - lastWordLen, lastWordLen);

        if (lastWordWidth < maxStrWidth) {

            for (size_t i = 0; i < lastWordWidth; ++i)
                if (write(terminal, "\b \b", strlen("\b \b")) == -1) return -1;
            
            for (size_t i = 0; i < lastWordLen; ++i) curStr[i] = curStr[i + len - lastWordLen];
            wmemset(curStr + lastWordLen, L'\0', maxStrWidth - lastWordLen);

            *strWidth = 0;
            if (printNewLine(terminal, wc, curStr, strWidth, maxStrWidth) == -1) return -1;
            
            *strWidth = len = lastWordWidth;
            if (write(terminal, curStr, len*sizeof(wchar_t)) == -1) return -1;

        } else {
            if (printNewLine(terminal, wc, curStr, strWidth, maxStrWidth) == -1) return -1;
            len = 0;
        }
    }
    
    if (write(terminal, &wc, sizeof(wchar_t)) == -1) return -1;
    
    curStr[len] = wc;
    *strWidth += wcwidth(wc);
    return 0;

}

handler getHandler(wint_t wc,  termios* attributes) {
    if      (btowc(attributes->c_cc[VERASE]) == wc) return eraseWchar;
    else if (btowc(attributes->c_cc[VKILL])  == wc) return eraseLine;
    else if (L'\27'                          == wc) return eraseWord;
    else if (btowc(attributes->c_cc[VEOF])   == wc) return endOfRead;
    else if (L'\n'                           == wc) return printNewLine;
    else if (!iswprint(wc))                         return printHorn;
    else                                            return printWchar;
}

int editor(int terminal, size_t maxStrWidth, const char* locale) {
    setlocale(LC_ALL, locale ? locale : "");
    termios oldAttr, *attr;

    if (tcgetattr(terminal, &oldAttr) == -1) {
        perror("Error: can't save old configuration");
        return -1;
    }
    if ((attr = setTerminalAttr(terminal)) == NULL) {
        perror("Error: can't set terminal configuration");
        return -1;
    }

    wchar_t wc = 0;
    wchar_t *curStr = (wchar_t*)calloc(maxStrWidth + 1, sizeof(wchar_t));
    size_t strWidth = 0;

    // main loop
    while (read(terminal, &wc, sizeof(wchar_t)) > 0) {
        int handleRet = getHandler(wc, attr)(terminal, wc, curStr, &strWidth, maxStrWidth);

        if(handleRet == -1) {

            perror("Error in handler");
            free(attr);
            if (tcflush(terminal, TCIFLUSH) == -1)
                perror("Error: can't flush terminal");
            if (tcsetattr(terminal, TCSANOW, &oldAttr) == -1)
                perror("Error: can't reset attributes");
            return -1;

        } else if (handleRet == 1) {
            break;
        }

        wc = 0;
    }

    if (tcflush(terminal, TCIFLUSH) == -1) {
        perror("Error: can't flush terminal");
        free(attr);
        return -1;
    }
    if (tcsetattr(terminal, TCSANOW, &oldAttr) == -1) {
        perror("Error: can't reset attributes");
        free(attr);
        return -1;
    }

    return 0;
}


int main(int argc, char** argv) {
    int terminal = open("/dev/tty", O_RDWR);
    if (terminal == -1) {
        perror("Open not terminal");
        close(terminal);
        return -1;
    }
    setlocale(LC_ALL, "UTF-8");
    return editor(terminal, 40, NULL);
}
