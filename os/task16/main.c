#include <termios.h>
#include <unistd.h>
#include <stdio.h>

static struct termios stored_settings;

int setByKeyInput(void) {
    struct termios new_settings;
    if (tcgetattr(0, &stored_settings) == -1) {
        return -1;
    }
    new_settings            = stored_settings;
    new_settings.c_lflag    &= (~ICANON);
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

int main(int argc, char** argv) {
    if (setByKeyInput() == -1) {
        perror("Error: can't set terminal configuration");
        return -1;
    }
    int c = -1;
    do {
        printf("%spress any character: ",
                c == -1 ? "" : "\n");
    } while ((c = fgetc(stdin)) != -1);
    if (resetByKeyInput() == -1) {
        perror("Error: can't reset terminal configuration");
        return -1;
    }
    return 0;
}
