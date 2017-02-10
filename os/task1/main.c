#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/resource.h>

#include <getopt.h>
#include <ulimit.h>


typedef struct option option;
extern char** environ;

void printUsage(FILE* fout, char* progName) {
    fprintf(fout,   "Usage: %s [options]\n"
                    "Options:\n"
                    "-i             Печатает реальные и эффективные"
                                    " идентификаторы пользователя и группы.\n"
                    "-s             Процесс становится лидером группы.\n"
                    "-p             Печатает иидентификаторы процесса,"
                                    " процесса-родителя и группы процессов.\n"
                    "-u             Печатает значение ulimit\n"
                    "-Unew_ulimit   Изменяет значение ulimit.\n"
                    "-c             Печатает размер в байтах core-файла,"
                                    " который может быть создан.\n"
                    "-Csize         Изменяет размер core-файла\n"
                    "-d             Печатает текущую рабочую директорию\n"
                    "-v             Распечатывает переменные среды и их значения\n"
                    "-Vname=value   Вносит новую переменную в среду или "
                                    "изменяет значение существующей переменной.\n",
                    progName);
}

void printUserID(FILE* fout) {
    int groupsCount = getgroups(0, NULL);
    gid_t *groups = (gid_t*)malloc(groupsCount * sizeof(gid_t));
    getgroups(groupsCount, groups);
    fprintf(fout, "real id: %d; effective id: %d; ", getuid(), geteuid());
    if (groupsCount > 0) {
        fprintf(fout, "groups:");
        for (size_t i = 0; i < groupsCount; ++i) {
            fprintf(fout, " %d,", groups[i]);
        }
    }
    fprintf(fout, "\b \b\n");
}

void printProcID(FILE* fout) {
    fprintf(fout,   "process id: %d; parent id: %d; process group: %d\n",
                    getpid(), getppid(), getpgid(0));
}

void printRlimit(FILE* fout, int resource) {
    struct rlimit rlim;
    if (getrlimit(resource, &rlim) != -1) {
        fprintf(fout, "ulimit: %lu\n", rlim.rlim_cur);
    }
}

void setRlimit(int resource, rlim_t new_rlim) {
    struct rlimit rlim;
    getrlimit(resource, &rlim);
    rlim.rlim_cur = new_rlim;
    setrlimit(resource, &rlim);
}

void printCWD(FILE* fout) {
    size_t dirsize = 255;
    char* dir = (char*)malloc(dirsize*sizeof(char));
    while(getcwd(dir, dirsize) == NULL) {
        dirsize = dirsize*2 + 1;
        free(dir);
        dir = (char*)malloc(dirsize*sizeof(char));
    }
    fprintf(fout, "current dir: %s\n", dir);
    free(dir);
}

void printEnvironment(FILE* fout) {
    if (environ) {
        fprintf(fout, "Variables:");
        char** cur = environ;
        while(*cur) {
            fprintf(fout, " %s: %s;", *cur, getenv(*cur));
            ++cur;
        }
        fprintf(stdout, "\b\b \n");
    }
}

// example of string "name=value"
void setEnvironmentVariable(const char* varAssignValue) {
    size_t len = strlen(varAssignValue);
    size_t assignPos;
    for (assignPos = 0; assignPos < len && varAssignValue[assignPos] != '='; ++assignPos);
    char* var = (char*)calloc(assignPos + 1, sizeof(char));
    char* val = (char*)calloc(len - assignPos + 1, sizeof(char));
    strncpy(var, varAssignValue, assignPos);
    strncpy(val, varAssignValue + assignPos + 1, len - assignPos);
    setenv(var, val, 1);
}

int main(int argc, char **argv) {
    if (argc == 1) {
        printUsage(stdout, argv[0]);
    } else {
        int opt;
        while ((opt = getopt(argc, argv, "ispuU:cC:dvV:h")) != -1) {
            switch(opt) {
                case 'i':
                    printUserID(stdout);
                    break;
                case 's':
                    setpgid(0, 0);
                    break;
                case 'p':
                    printProcID(stdout);
                    break;
                case 'u':
                    printRlimit(stdout, RLIMIT_FSIZE);
                    break;
                case 'U':
                    setRlimit(RLIMIT_FSIZE, atol(optarg));
                    break;
                case 'c':
                    printRlimit(stdout, RLIMIT_CORE);
                    break;
                case 'C':
                    setRlimit(RLIMIT_CORE, atol(optarg));
                    break;
                case 'd':
                    printCWD(stdout);
                    break;
                case 'v':
                    printEnvironment(stdout);
                    break;
                case 'V':
                    setEnvironmentVariable(optarg);
                    break;
                case 'h':
                    printUsage(stdout,argv[0]);
                    return 0;
                    break;
                default:
                    return 1;
            }
        }
    }
    return 0;
}