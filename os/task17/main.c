#include <termios.h>
#include <unistd.h>
#include <wctype.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
typedef int (*handler)(int terminal, wint_t wc, ssize_t wcLen, size_t* curStrLen, size_t maxStrLen);
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

int endOfRead(int terminal, wint_t wc, ssize_t wcLen, size_t* curStrLen, size_t maxStrLen) {
    if (*curStrLen == 0) {
        return 1;
    } else {
        return 0;
    }
}

// int eraseLine(int terminal, wint_t wc, ssize_t wcLen, size_t* curStrLen, size_t maxStrLen) {
//     if (write(terminal, "\r", strlen("\r")) == -1) {
//         return -1;
//     }
//     for (size_t i = 0; i < maxStrLen; ++i) {
//         if (write(terminal, " ", strlen(" ")) == -1) {
//             return -1;
//         }
//     }
//     if (write(terminal, "\r", strlen("\r")) == -1) {
//         return -1;
//     }
//     *curStrLen = 0;
//     return 0;
// }

int eraseLine(int terminal, wint_t wc, ssize_t wcLen, size_t* curStrLen, size_t maxStrLen) {
    if (write(terminal, "\r", strlen("\r")) == -1) {
        return -1;
    }
    for (size_t i = 0; i < maxStrLen; ++i) {
        if (write(terminal, " ", strlen(" ")) == -1) {
            return -1;
        }
    }
    if (write(terminal, "\r", strlen("\r")) == -1) {
        return -1;
    }
    *curStrLen = 0;
    return 0;
}

int eraseChar(int terminal, wint_t wc, ssize_t wcLen, size_t* curStrLen, size_t maxStrLen) {
    if (write(terminal, "\b \b", strlen("\b \b")) == -1) {
        return -1;
    }
    --*curStrLen;
    return 0;
}

int printNewLine(int terminal, wint_t wc, ssize_t wcLen, size_t* curStrLen, size_t maxStrLen) {
    if (write(terminal, "\n", strlen("\n")) == -1) {
        return -1;
    }
    *curStrLen = 0;
    return 0;
}

int printHorn(int terminal, wint_t wc, ssize_t wcLen, size_t* curStrLen, size_t maxStrLen) {
    if (write(terminal, "\007", strlen("\007")) == -1) {
        return -1;
    }
    return 0;
}

int printWchar(int terminal, wint_t wc, ssize_t wcLen, size_t* curStrLen, size_t maxStrLen) {
    if (*curStrLen == maxStrLen) {
        printNewLine(terminal, wc, wcLen, curStrLen, maxStrLen);
    }
    if (write(terminal, &wc, wcLen) == -1) {
        return -1;
    }
    ++*curStrLen;
    return 0;

}

handler getHandler(wint_t wc,  termios* attributes) {
    if (0) ;
    else if (btowc(attributes->c_cc[VKILL]) == wc) return eraseLine;
    else if (btowc(attributes->c_cc[VEOF]) == wc) return endOfRead;
    else if (btowc(attributes->c_cc[VERASE]) == wc) return eraseChar;
    else if (L'\n' == wc) return printNewLine;
    else if (!iswprint(wc)) return printHorn;
    return printWchar;
}

int editor(int terminal, size_t maxStrLen, const char* locale) {
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
    wint_t wc = 0;
    ssize_t wcLen = 0;
    size_t curStrLen = 0;
    while ((wcLen = read(terminal, &wc, sizeof(wint_t))) > 0) {
        int handleRet = getHandler(wc, attr)(terminal, wc, wcLen, &curStrLen, maxStrLen);
        if(handleRet == -1) {
            perror("Error in handler");
            free(attr);
            if (tcflush(terminal, TCIFLUSH) == -1) {
                perror("Error: can't flush terminal");
                return -1;
            }
            if (tcsetattr(terminal, TCSANOW, &oldAttr) == -1) {
                perror("Error: can't reset attributes");
                return -1;
            }
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
    return editor(0, 40, NULL);
}