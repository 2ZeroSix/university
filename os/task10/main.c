#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

extern char** environ;

int main(int argc, char** argv, char* envp[]) {
    pid_t p;
    if (argc >= 2) {
        switch (p = fork()) {
            case 0: {
                fprintf(stderr, "error: %d", execve(argv[1], argv + 1, envp));
                perror(" ");
		break;
            }
            default: {
                int status;
                waitpid(p, &status, 0);
                printf("return code of a child process: %d\n", status);
                break;
            }
        }
    } else {
        printf("using: %s <command> [args] \n", argv[0]);
    }
    return 0;
}
