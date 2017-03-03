#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

extern char **environ;

int execvpe(const char* file, char *const argv[], char *const envp[]) {
    if (envp) {
        for(size_t i = 0;; ++i) {
            if (envp[i] == NULL) break;
            environ[i] = envp[i];
        }
    } else {
        environ[0] = NULL;
    }

    int retval  = execvp(file, argv);
    return retval;
}

int main(int argc, char** argv) {
    printf("%p\n", environ);
    if (argc >= 2) {
        return execvpe(argv[1], argv + 1, NULL);
    } else {
        printf("using: %s <command> [args] \n", argv[0]);
    }
    return 0;
}
