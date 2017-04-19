#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/select.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MPR_BUF_SIZE 256 // size of buffer for every file in multiplexRead
#define TIME_OUT 5

int waitForInput(int fd, struct timeval tv) {
    fd_set fd_s;
    FD_ZERO(&fd_s);
    FD_SET(fd, &fd_s);
    switch (select(fd + 1, &fd_s, NULL, NULL, &tv)) {
        case -1:    return -1;
        case  0:    return  1;
        default:    return  0;
    }
}

int multiplexRead(int fileCount, char** filenames) {
    int* files = (int*)calloc(fileCount, sizeof(int));
    if (files == NULL) {
        perror("can't allocate array of file descriptors");
        return -1;
    }

    for (int i = 0; i < fileCount; ++i) {
        files[i] = open(filenames[i], O_RDONLY);
        if (files[i] == -1) {
            fprintf(stderr, "Can't open file. ");
            perror(filenames[i]);
            --i;
            --fileCount;
            errno = 0;
        }
    }

    size_t* bufOffset = (size_t*)calloc(fileCount, sizeof(size_t));

    char** buffers = (char**)calloc(fileCount, sizeof(char*));
    for (int i = 0; i < fileCount; ++i) 
        buffers[i] = (char*) calloc(MPR_BUF_SIZE, sizeof(char));

    int check = 1;
    while (check) {
        check = 0;
        for (int i = 0; i < fileCount; ++i) {
            if(files[i] == -1) continue;
            check = 1;

            switch (waitForInput(files[i], (struct timeval){(time_t)TIME_OUT,(suseconds_t)0})) {
                case -1:
                    close(files[i]);
                    files[i] = -1;
                    free(buffers[i]);
                    continue;
                case 0:
                    break;
                default:
                    continue;
            }

            if (bufOffset[i] == 0) {
                int retval = read(files[i], buffers[i], MPR_BUF_SIZE - 1);
                if (retval <= 0) {
                    close(files[i]);
                    files[i] = -1;
                    free(buffers[i]);
                    continue;
                }
                buffers[i][retval] = '\0';
            }

            char* curPos = buffers[i] + bufOffset[i];
            char* newLinePos = strchr(curPos, '\n');

            if (newLinePos == NULL) {
                size_t len = strlen(curPos);
                write(1, curPos, len);
                bufOffset[i] = 0;
                --i;
                continue;
            } else {
                size_t len = (size_t)(newLinePos - (buffers[i] + bufOffset[i]) + 1);
                write(1, curPos, len);
                bufOffset[i] += len;
                bufOffset[i] %= MPR_BUF_SIZE - 1;
            }
        }
    }

    free(bufOffset);
    free(buffers);
    free(files);

    return 0;
}

int main(int argc, char** argv) {
    return multiplexRead(argc - 1, argv + 1) ? 1 : 0;
}
