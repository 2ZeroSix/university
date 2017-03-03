#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
int lockOnWrite(int fd, short type) {
    struct stat st = {0};
    if(fstat(fd, &st) == -1) return -1;
    struct flock flk = {0};
    flk.l_type      = F_WRLCK;
    flk.l_whence    = SEEK_SET;
    flk.l_start     = 0;
    flk.l_len       = st.st_size;
    return fcntl(fd, type, &flk);
}

char* createCommandString(char* command, char* arguments) {
    size_t commandLen = strlen(command);
    size_t argumentsLen = strlen(arguments);
    char* commandWArgs = malloc(commandLen + 1 + argumentsLen + 1);
    if(commandWArgs == NULL) return NULL;
    strcpy(commandWArgs, command);
    commandWArgs[commandLen] = ' ';
    strcpy(commandWArgs + commandLen + 1, arguments);    
    return commandWArgs;
}

int main(int argc, char** argv) {
    char* fileName = argc == 2 ? argv[1] : "main.c";
    int fd = open(fileName, O_WRONLY);
    int retcode = 0;
    if (fd == -1) {
        retcode = errno;
        perror("Error: first argument must name a valid file");
    } else {
        if (lockOnWrite(fd, F_SETLKW) == -1) {
            retcode = errno;
            perror("Error: can't lock whole file on write");
        } else {
            char* command = createCommandString("vim", fileName);
            if(command == NULL) {
                retcode = errno;
                perror("Error: can't create command string");
            } else if (system(command) == -1) {
                retcode = errno;
                fprintf(stderr, "Error: can't open editor\n");
            } else {
                retcode = wait(NULL);
            }
            free(command);
        }
        close(fd);
    }
    return retcode;
}
