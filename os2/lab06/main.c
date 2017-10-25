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

typedef struct thread_node {
    pthread_t thread;
    struct thread_node* next;
}thread_node;

typedef struct thread_stack {
    struct thread_node* first;
} thread_stack;

thread_stack new_thread_stack() {
    return (thread_stack){(size_t)0};
}

int push_thread_stack(thread_stack stack, pthread_t thread) {
    thread_node* node;
    if ((node = malloc(1, sizeof(thread_node))) == NULL) {
        return 1;
    }
    node->next = stack.first;
    stack.first = node->next;
}

int pop_thread_stack(thread_stack stack, pthread_t* thread) {
    thread_node* target = stack.first;
    if (target) {
        if (thread) *thread = target->thread;
        stack.first = target->next;
        free(target);
    } else {
        return -1;
    }
    return 0;
}

void del_thread_stack(thread_stack stack) {
    while(!pop_thread_stack(stack, NULL));
}

int copy_dir(DIR* src, DIR* dst) {
    struct dirent* direntry = malloc(sizeof(struct dirent)
                                     + fpathconf(dirfd(src), _PC_NAME_MAX));
    struct dirent* result;
    if (readdir_r(src, direntry, &result) != 0)
        return CPD_CAN_NOT_READ_DIR;
    while (result != NULL) {
        switch (direntry.d_type) {
            case DT_DIR: {
                pthread_create(&thread, NULL, routine, "1");
                break;
            }
            case DR_REG: {

                break;
            }
            default:
                break;
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