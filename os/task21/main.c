#define _POSIX_C_SOURCE 200112L
#include <termios.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#define DEL_SEQUENCE 2117294875

static struct termios stored_settings;
size_t deleteCouter = 0;


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

void finalize(int retVal) {
    resetByKeyInput();
    exit(retVal);
}

void onQuit(int param) {
    printf("Count of delete button presses: %zu\n", deleteCouter);
    finalize(0);
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
    int c;
    int status = 0;
    while((c = fgetc(stdin)) != EOF) {
        switch(c) {
            case 27:
                status = 1;
                break;
            case 91:
                status = status == 1 ? 2 : 0;
                break;
            case 51:
                status = status == 2 ? 3 : 0;
                break;
            case 126:
                if (status == 3) {
                    write(1, "\a", sizeof("\a"));
                    ++deleteCouter;
                }
                status = 0;
                break;
            default: status = 0;
        }
    }
    finalize(1);
}
