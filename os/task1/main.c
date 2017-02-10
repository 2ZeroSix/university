#include <stdlib.h>
#include <stdio.h>

#include <unistd.h>
#include <sys/types.h>

#include <getopt.h>
#include <ulimit.h>


typedef struct option option;


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
    fprintf(fout, "process id: %d; parent id: %d; process group: %d\n", getpid(), getppid(), getpgid(0));
}

int main(int argc, char **argv) {
    int opt;
    option longOptions[2] = {{"help", no_argument, NULL, 'h'}};
    while ((opt = getopt_long(argc, argv, "ispuU:cC:dvV:h", longOptions, NULL)) != -1) {
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
                break;
            case 'U':
                break;
            case 'c':
                break;
            case 'C':
                break;
            case 'd':
                break;
            case 'v':
                break;
            case 'V':
                break;
            case 'h':
                printUsage(stdout,argv[0]);
                return 1;
                break;
            default:
                return 1;
        }
    }
    return 0;
}