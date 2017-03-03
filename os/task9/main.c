#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

int main(int argc, char** argv) {
    pid_t p;
    switch (p = fork()) {
        case 0: {
            char* command   = "cat";
            char* file      = (argc == 2) ? argv[1] : "main.c";
            execlp(command, command, file, NULL);
            perror("Error");
            return errno;
        }
        default: {
            waitpid(p, NULL, 0);
            printf("Hello from parent process\n");
            return 0;
        }
    }
}
