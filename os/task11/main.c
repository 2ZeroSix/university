#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

extern char **environ;

int execvpe(const char* file, char *const argv[], char *const envp[]) {
    char** tmp  = environ;
    environ     = (char**)envp;
    int retval  = execvp(file, argv);
    environ     = tmp;
    return retval;
}

int main(int argc, char** argv) {
    return execvpe("env", (char* []){"env", (char*)NULL}, argv + 1) ? 1 : 1;
}
