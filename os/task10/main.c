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
            size_t fileLen      = strlen(file);
            char* command       = argv[1];
            size_t commandLen   = strlen(command);
            char* commWithArg  = malloc((fileLen + 1 + commandLen + 1)*sizeof(char));
            strcpy(commWithArg, command);
            commWithArg[commandLen] = ' ';
            strcpy(commWithArg + commandLen + 1, file);
            fprintf(stderr, "error: %d", execve(argv[1], argv + 2, envp));
            perror(" ");
        }
        default: {
            printf("return code of a child process: %d\n", waitpid(p, NULL, 0));
            return 0;
        }
    }
}
