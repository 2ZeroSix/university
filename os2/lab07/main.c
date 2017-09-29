#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ITER_COUNT 999999999
#define ul unsigned long
#define ull unsigned long long

struct Task {
    ull offset;
    ull count_of_threads;
};

void* subpi(void* start_end) {
    struct Task task = *(struct Task*)start_end;
    double pi = 0;
    ull i = task.offset;
    printf("%llu\n", i);
    fflush(stdout);
    for (; i < ITER_COUNT; i += task.count_of_threads) {
         pi += 1.0/(i*4.0 + 1.0);
         pi -= 1.0/(i*4.0 + 3.0);
    }
    printf("%llu\n", i);
    fflush(stdout);
    double* p_pi = (double*)malloc(sizeof(double));
    *p_pi = pi;
    return p_pi;
}



int main(int argc, char** argv) {
    if (argc != 2) {
        printf("usage: ./name_of_prog <number of threads>\n");
        return 1;
    }
    ul count_of_threads = strtoul(argv[1], NULL, 10);
    pthread_t* threads = (pthread_t*)malloc(sizeof(pthread_t) * count_of_threads);
    struct Task* task = (struct Task*)malloc(sizeof(struct Task) * count_of_threads);
    for (ul i = 0; i < count_of_threads; ++i) {
        task[i].offset = i;
        task[i].count_of_threads = count_of_threads;
    }
    for (ul i = count_of_threads - 1; i != -1UL; --i) {
        if(pthread_create(&threads[i], NULL, subpi, &task[i])) {
            perror("Can't create thread");
            exit(1);
        }
    }
    double pi;
    for (ul i = 0; i < count_of_threads; ++i) {
        double* tmp;
        pthread_join(threads[i], (void**)&tmp);
        pi += *tmp;
        free(tmp);
    }
    free(task);
    pi *= 4;
    printf("%.100lf\n", pi);
    return 0;
}