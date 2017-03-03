#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char** argv, char* envp[]) {
    pid_t p;
    switch (p = fork()) {
        case 0: {
            char* file          = argc == 2 ? argv[1] : "main.c";
            char* command       = "/bin/cat";
            fprintf(stderr, "error: %d", execl(command, command, file, NULL));
            perror(" ");
        }
        default: {
            waitpid(p, NULL, 0);
            printf("Hello from parent process\n");
            return 0;
        }
    }
}
