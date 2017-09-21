#include<unistd.h>
#include<stdio.h>
#include<pthread.h>

void cleanup_func(void* unused) {
    printf("dead\n");
}

void* routine(void* unused) {
    pthread_cleanup_push(cleanup_func, NULL);
    while(1)
        write(1, "1", sizeof("1"));
    pthread_cleanup_pop(0);
}

int main() {
    pthread_t thread;
    if(pthread_create(&thread, NULL, routine, NULL) != 0) {
        printf("Can't create thread\n");
        return 1;
    }
    sleep(2);
    if(pthread_cancel(thread) != 0) {
        printf("Can't cancel thread\n");
        return 2;
    }
    pthread_exit(0);
}
