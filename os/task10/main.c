#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

int main(int argc, char** argv) {
    pid_t p;
    if (argc >= 2) {
        switch (p = fork()) {
            case 0:
                execvp(argv[1], argv + 1);
                perror("Error");
        		return errno;
            default: {
                int status = 0;
                waitpid(p, &status, 0);
                printf("child process(%d) return code: %d\n", p, status);
                break;
            }
        }
    } else {
        printf("using: %s <command> [args] \n", argv[0]);
    }
    return 0;
}
