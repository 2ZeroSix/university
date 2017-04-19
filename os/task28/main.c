#include <libgen.h>
#include <stdlib.h>
#include <time.h>


int main() {
    srand(time(NULL));
    FILE* fd[2];
    p2open("sort", fd);
    for (int i = 0; i < 100; ++i) {
        fprintf(fd[1], "%d\n", rand()%100);
    }
    p2close(fd);
    return 0;
}
