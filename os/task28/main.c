#include <libgen.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main() {
    srand(time(NULL));
    FILE* fd[2];
    if (p2open("sort -n", fd) == -1) return 1;
    for (int i = 0; i < 100; ++i) {
        fprintf(fd[0], "%d\n", rand()%100);
    }
    fclose(fd[0]);
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            int num;
            fscanf(fd[1], "%d", &num);
            fprintf(stdout, "%3d ", num);
        }
        fprintf(stdout, "\n");
    }
    p2close(fd);
    return 0;
}
