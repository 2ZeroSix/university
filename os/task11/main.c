#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

extern char **environ;

int execvpe(const char* file, char *const argv[], char *const envp[]) {
    char** tmp  = environ;
    environ     = (char** volatile)envp;
    int retval  = execvp(file, argv);
    environ     = tmp;
    return retval;
}

int main(int argc, char** argv) {
    if (argc >= 2) {
        return execvpe(argv[1], argv + 1, (char**){NULL});
    } else {
        printf("using: %s <command> [args]\n", argv[0]);
    }
    return 0;
}
