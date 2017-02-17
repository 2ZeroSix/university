#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

#include <sys/resource.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

#include <getopt.h>
#include <ulimit.h>


typedef struct option option;
extern char** environ;

void printUsage(FILE* fout, char* progName) {
    fprintf(fout, "Usage: %s [options]\n", progName);
}

void printOptions(FILE* fout) {
    fprintf(fout,   "Options:\n"
                    "-i             Печатает реальные и эффективные "
                                    "идентификаторы пользователя и группы.\n"
                    "-s             Процесс становится лидером группы.\n"
                    "-p             Печатает иидентификаторы процесса, "
                                    "процесса-родителя и группы процессов.\n"
                    "-u             Печатает значение ulimit\n"
                    "-Unew_ulimit   Изменяет значение ulimit.\n"
                    "-c             Печатает размер в байтах core-файла, "
                                    "который может быть создан.\n"
                    "-Csize         Изменяет размер core-файла\n"
                    "-d             Печатает текущую рабочую директорию\n"
                    "-v             Распечатывает переменные среды и их значения\n"
                    "-Vname=value   Вносит новую переменную в среду или "
                                    "изменяет значение существующей переменной.\n");
}
void printHelp(FILE* fout, char* progName) {
    printUsage(fout, progName);
    printOptions(fout);
}

void printUserID(FILE* fout) {
    uid_t uid = getuid();
    uid_t euid = geteuid();
    gid_t gid = getgid();
    gid_t egid = getegid();
    // int groupsCount = getgroups(0, NULL);
    // gid_t *groups = (gid_t*)malloc(groupsCount * sizeof(gid_t));
    // getgroups(groupsCount, groups);

    fprintf(fout,   "real id: %d(%s); effective id: %d(%s); group id: %d(%s); effective groupid: %d(%s)",
                    uid, getpwuid(euid)->pw_name,
                    euid, getpwuid(euid)->pw_name,
                    gid, getgrgid(gid)->gr_name,
                    egid, getgrgid(egid)->gr_name);
    // fprintf(fout, "groups:");
    // fprintf(fout, " %d(%s)", groups[0], getgrgid(groups[0])->gr_name);
    // for (size_t i = 1; i < groupsCount; ++i) {
    //     fprintf(fout, ", %d(%s)", groups[i], getgrgid(groups[i])->gr_name);
    // }
    fprintf(fout, "\n");
}

void printProcID(FILE* fout) {
    fprintf(fout,   "process id: %d; parent id: %d; process group: %d\n",
                    getpid(), getppid(), getpgid(0));
}

void printRlimit(FILE* fout, const char* name, int resource) {
    struct rlimit rlim;
    if (getrlimit(resource, &rlim) != -1) {
        fprintf(fout, "%s: %lu\n", name, rlim.rlim_cur);
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
        if (*cur) {
            char* val = getenv(*cur);
            fprintf(fout, " %s: %s", *cur, val ? val : "");
            ++cur;
        }
        while(*cur) {
            char* val = getenv(*cur);
            fprintf(fout, " %s: %s", *cur, val ? val : "");
            ++cur;
        }
        fprintf(stdout, "\n");
    }
}

// example of string "name=value"
void setEnvironmentVariable(char* varAssignValue) {
    size_t len = strlen(varAssignValue);
    size_t assignPos;
    for (assignPos = 0; assignPos < len && varAssignValue[assignPos] != '='; ++assignPos);
    varAssignValue[assignPos] = '\0';
    setenv(varAssignValue, varAssignValue + assignPos+1, 1);
}

int main(int argc, char **argv) {
    if (argc == 1) {
        printUsage(stdout, argv[0]);
        printf("write \"%s -h\" for help\n", argv[0]);
    } else {
        int opt;
        while((opt = getopt(argc, argv, "ispuU:cC:dvV:h")) != -1) {
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
                    printRlimit(stdout, "ulimit", RLIMIT_FSIZE);
                    break;
                case 'U':
                    setRlimit(RLIMIT_FSIZE, atol(optarg));
                    break;
                case 'c':
                    printRlimit(stdout, "max core-file size", RLIMIT_CORE);
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
                    printHelp(stdout,argv[0]);
                    return 0;
                case ':':
                    printf("missing option argument\n");
                    return 1;                    
                case '?':
                    printf("Unknown option: %c\n", optopt);
                    return 1;
                default:
                    perror("unexpected behaviour");
                    return 666;
            }
        }
    }
    return 0;
}