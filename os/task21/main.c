#define _POSIX_C_SOURCE 200112L
#include <termios.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

typedef void (*sighandler_t)(int);
// typedef struct sigaction sigaction;

static struct termios stored_settings;
size_t escapeCouter = 0;


int setByKeyInput(void) {
    struct termios new_settings;
    if (tcgetattr(0, &stored_settings) == -1) {
        return -1;
    }
    new_settings            = stored_settings;
    new_settings.c_lflag    &= ~(ICANON | ECHO);
    new_settings.c_lflag    |= ISIG;

    new_settings.c_cc[VTIME]= 0;
    new_settings.c_cc[VMIN] = 1;
    if (tcsetattr(0, TCSANOW, &new_settings) == -1) {
        return -1;
    }
    return 0;
}

int resetByKeyInput(void) {
    if(tcsetattr(0, TCSANOW, &stored_settings) == -1) {
        return -1;
    }
    return 0;
}

void finalize() {
    resetByKeyInput();
}

void onQuit(int param) {
    printf("Count of delete button presses: %zu\n", escapeCouter);
    finalize();
    exit(0);
}

int setQuitAction() {
    struct sigaction act = {{0}};
    act.sa_handler = onQuit;
    return sigaction(SIGQUIT, &act, NULL);
}

int main(int argc, char** argv) {
    setByKeyInput();
    if (setQuitAction() == -1) {
        perror("Error while setting SIGQUIT");
        return -1;
    }
    wint_t wc;
    while(read(0, &wc, sizeof(wc)) > 0) {
        // printf("%u\n", wc);
        if (wc == 2117294875) {
            putchar('\07');
            ++escapeCouter;
        }
    }
}
