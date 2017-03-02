#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <errno.h>

#include <sys/select.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>

long PageSize = 0;

off_t* createOffsetTable(int fd, size_t* tableSize) {
    if (!tableSize) {
        errno = EINVAL;
        return NULL;
    }
    *tableSize = 255;
    struct stat st;
    if (fstat(fd, &st) == -1) return NULL;
    off_t* table = calloc(*tableSize, sizeof(off_t));
    if(table == NULL) return NULL;
    off_t line = 1;

    char* fileMap;
    if((fileMap = mmap(NULL, st.st_size, PROT_READ, MAP_SHARED, fd, 0))
        != MAP_FAILED) {
        for (off_t i = 0; i < st.st_size; ++i) {
            if(fileMap[i] == '\n') {
                table[line] = i + 1;
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
    } else {
        free(table);
        return NULL;
    }
    table[line] = st.st_size + 1;
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
    struct stat st;
    fstat(fd, &st);
    ssize_t len;
    for (size_t offset = 0; offset < st.st_size; offset += PageSize) {
        len = st.st_size - offset - PageSize > 0
            ? PageSize
            : st.st_size - offset;
        char* fileMap = mmap(NULL, len, PROT_READ, MAP_SHARED, fd, offset);
        if(fileMap == MAP_FAILED)           return -1;
        if (write(0, fileMap, len) < len)   return -1;
    }
    return 0;
}

int main(int argc, char** argv) {
    PageSize = sysconf(_SC_PAGESIZE);
    int fd = open(argc == 2 ? argv[1] : "main.c" , O_RDONLY);
    if(fd == -1) {
        perror("Error: first argument must name a valid file");
        return errno;
    }

    printf("Creating offset table: ");
    size_t tableSize;
    off_t* table = createOffsetTable(fd, &tableSize);
    if (table == NULL) {
        perror("Error: can't create offset table");
        return errno;
    }
    printf("Complete\n");

    switch (waitForInput((struct timeval){(time_t)5,(suseconds_t)0})) {
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

    size_t line;
    while(scanf("%zu", &line) > 0) {
        if (line-- == 0) {
            break;
        } else if (line >= tableSize-1) {
            printf("Warning: Last line is %zu\n", tableSize-1);
            continue;
        } else if(lseek(fd, table[line], SEEK_SET) == (off_t)-1) {
            perror("Error: can't change position");
            break;
        }
        size_t length = table[line + 1] - table[line] - 1;
        off_t addOffset = table[line] % PageSize;
        off_t offset    = table[line] - addOffset;
        char* fileMap = mmap(NULL, length + addOffset,
                            PROT_READ, MAP_SHARED,
                            fd, offset);
        if (fileMap == MAP_FAILED) {
            perror("Error: can't read file");
            break;
        } else if (write(0, fileMap + addOffset, length) == -1
            || putc('\n', stdout) == EOF) {
            perror("Error: can't write line");
            break;
        }
    }
    free(table);
    close(fd);
    return errno;
}