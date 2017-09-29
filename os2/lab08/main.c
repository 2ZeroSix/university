#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>


#define ITER_COUNT 1000000
#define ul unsigned long
#define ull unsigned long long

char flag = 1;

struct Task {
    ull offset;
    ull count_of_threads;
};

void* subpi(void* start_end) {
    struct Task task = *(struct Task*)start_end;
    double pi = 0;
    ull iteration = task.offset;
    while (flag)
        for (ull i = 0; i < ITER_COUNT; ++i) {
             pi += 1.0/(iteration*4.0 + 1.0);
             pi -= 1.0/(iteration*4.0 + 3.0);
             iteration += task.count_of_threads;
        }
    printf("%llu\n", iteration);
    double* p_pi = (double*)malloc(sizeof(double));
    *p_pi = pi;
    return p_pi;
}

void handler(int sig) {
    printf("\n");
    flag = 0;
}


int main(int argc, char** argv) {
    if (argc != 2) {
        printf("usage: ./name_of_prog <number of threads>\n");
        return 1;
    }
    struct sigaction sa;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sa.sa_handler = handler;
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("Can't set signal handler");
        return 2;
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