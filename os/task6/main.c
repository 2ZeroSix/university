#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <errno.h>

#include <sys/select.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

off_t* createOffsetTable(int fd, size_t* tableSize) {
    if (!tableSize) {
        errno = EINVAL;
        return NULL;
    }
    if (lseek(fd, 0, SEEK_SET) == (off_t)-1) return NULL;
    *tableSize = 255;
    off_t* table = calloc(*tableSize, sizeof(off_t));
    if(table == NULL) return NULL;
    off_t line = 1;

    char buf[255];
    ssize_t bufLen = 0;
    while((bufLen = read(fd, buf, 255)) > 0) {
        if (bufLen == -1) {
            free(table);
            return NULL;
        }
        for (ssize_t i = 0; i < bufLen; ++i) {
            if(buf[i] == '\n') {
                off_t pos = lseek(fd, 0, SEEK_CUR);
                if (pos == (off_t)-1) {
                    free(table);
                    return NULL;
                }
                table[line] = pos + i - bufLen + 1;
                if (++line == *tableSize) {
                    *tableSize = *tableSize*2 + 1;
                    off_t* bufTable = realloc(table,
                                            *tableSize * sizeof(off_t));
                    if (bufTable == NULL) {
                        free(table);
                        return NULL;
                    } else {
                        table = bufTable;
                    }
                }
            }
        }
    }
    off_t end = lseek(fd, 0, SEEK_END);
    if (end == (off_t)-1) {
        free(table);
        return NULL;
    }
    table[line] =  end + 1;
    *tableSize = line + 1;
    return table;
}

ssize_t maxLine(off_t* table, size_t tableSize) {
    ssize_t max = 0;
    for (size_t i = 1; i < tableSize; ++i)
        max = max >= table[i] - table[i - 1]
            ? max
            : table[i] - table[i - 1];
    return max;
}

int waitForInput(struct timeval tv) {
    fd_set fd_s;
    FD_ZERO(&fd_s);
    FD_SET(0, &fd_s);
    switch (select(1, &fd_s, NULL, NULL, &tv)) {
        case -1:    return -1;
        case  0:    return  1;
        default:    return  0;
    }
}

int printFile(int fd) {
    char buf[255];
    ssize_t len;
    lseek(fd, 0, SEEK_SET);
    while((len = read(fd, buf, 255)) > 0) {
        buf[len] = '\0';
        if (write(1, buf, len) < len) {
            return -1;
        }
    }
    if (len == -1) {
        return -1;
    }
    return 0;
}

int main(int argc, char** argv) {
    int fd = open(argc == 2 ? argv[1] : "main.c" , O_RDONLY);
    if(fd == -1) {
        perror("Error: first argument must name a valid file");
        return errno;
    }
    size_t tableSize;
    printf("Creating offset table: ");
    off_t* table = createOffsetTable(fd, &tableSize);
    if (table == NULL) {
        perror("Error: can't create offset table");
        return errno;
    }
    printf("Complete\n");
    fflush(stdout);
    switch (waitForInput((struct timeval){5,0})) {
        case -1:
            free(table);
            perror("Error: can't wait for console");
            return errno;
        case 0:
            break;
        default:
            free(table);
            if (printFile(fd) == -1) {
                perror("Error: can't print file");
                return errno;
            }
            return 0;
    }
    ssize_t bufLen = maxLine(table, tableSize);
    char* buf = calloc(bufLen, sizeof(char));
    if (buf == NULL) {
        free(table);
        perror("Error: can't create buffer");
        return errno;
    }
    size_t line;
    while(scanf("%zu", &line) > 0) {
        if (line-- == 0) break;
        else if (line >= tableSize-1) {
            printf("Warning: Last line is %zu\n", tableSize-1);
            continue;
        }
        else if(lseek(fd, table[line], SEEK_SET) == (off_t)-1) {
            perror("Error: can't change position");
            break;
        }
        size_t length = table[line + 1] - table[line] - 1;
        if (read(fd, buf, length) == -1) {
            perror("Error: can't read file");
            break;
        }
        buf[length] = '\0';
        printf("%s\n", buf);
    }
    free(table);
    free(buf);
    close(fd);
    return errno;
}
