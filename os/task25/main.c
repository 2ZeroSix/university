#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
#define BUF_LENGTH 256

void strtoupper(char* dest, const char* src) {
    for (size_t i = 0; src[i] != '\0'; ++i) {
        dest[i] = toupper(src[i]);
    }
}


int main() {
    int fd[2] = {0};
    if (pipe(fd) == -1) {
        perror("Can't create pipe");
        return 1;
    }
    switch(fork()) {
        case -1:
            perror("Can't fork process");
            return 2;
        case 0: {
            close(fd[1]);
            char str[BUF_LENGTH];
            ssize_t len;
            while((len = read(fd[0], str, BUF_LENGTH - 1)) > 0) {
                str[len] = 0;
                strtoupper(str, str);
                write(1, str, len);
            }
            close(fd[0]);
            return 0;
        }
        default: {
            close(fd[0]);
            char str[BUF_LENGTH];
            ssize_t len;
            while((len = read(0, str, BUF_LENGTH - 1)) > 0) {
                str[len] = 0;
                write(fd[1], str, len);
            }
            close(fd[1]);
            wait(NULL);
            return 0;
        }
    }
}
