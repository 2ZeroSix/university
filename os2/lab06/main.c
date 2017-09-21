#define _POSIX_C_SOURCE 200809L
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

#define CPD_WRONG_SPATH 1
#define CPD_WRONG_DPATH 2
#define CPD_CAN_NOT_READ_DIR 3

int copy_dir(DIR* src, DIR* dst) {
    struct dirent* direntry = malloc(sizeof(struct dirent) + fpathconf(dirfd(src), _PC_NAME_MAX));
    struct dirent* result;
    if (readdir_r(src, direntry, &result) != 0)
        return CPD_CAN_NOT_READ_DIR;
    while (result != NULL) {
        switch (direntry.d_type) {
            case: DT_
        }
        if (readdir_r(src, direntry, &result) != 0)
            return CPD_CAN_NOT_READ_DIR;
    }
    free(direntry);
    return 0;
}

int copy_dir_path(char* src, char* dst) {
    DIR* srcD = opendir(src);
    if (srcD == NULL) {
        return CPD_WRONG_SPATH;
    }
    DIR* dstD = opendir(dst);
    if (dstD == NULL) {
        closedir(srcD);
        return CPD_WRONG_DPATH;
    }
    return copy_dir(srcD, dstD);
}

int main(int argc, char** argv) {
    if (argc == 2) {
        switch(copy_dir(argv[1], argv[2])) {
            case 0:
                return EXIT_SUCCESS;
            case CPD_WRONG_SPATH:
                perror("Wrong source path");
                return 1;
            case CPD_WRONG_DPATH:
                perror("Wrong destination path");
                return 1;
            default:
                perror("Unknown error")
                return 2;
        }
    }
}