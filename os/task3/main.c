#include <stdio.h>

#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>

int main() {
    FILE* fin;
    printf("uid: %s; euid: %s\n", getpwuid(getuid())->pw_name, getpwuid(geteuid())->pw_name);
    fprintf(stderr, "trying to open on reading: ");
    if ((fin = fopen("in.txt", "r")) == NULL) {
        perror("");
    } else {
        printf("Success\n");
        fclose(fin);
    }
    fprintf(stderr, "trying to open on writing: ");
    if ((fin = fopen("in.txt", "w")) == NULL) {
        perror("");
    } else {
        printf("Success\n");
        fclose(fin);
    }
    setuid(getuid());
    printf("uid: %s; euid: %s\n", getpwuid(getuid())->pw_name, getpwuid(geteuid())->pw_name);
    fprintf(stderr, "trying to open on reading: ");
    if ((fin = fopen("in.txt", "r")) == NULL) {
        perror("");
    } else {
        printf("Success\n");
        fclose(fin);
    }
    fprintf(stderr, "trying to open on writing: ");
    if ((fin = fopen("in.txt", "w")) == NULL) {
        perror("");
    } else {
        printf("Success\n");
        fclose(fin);
    }
}
