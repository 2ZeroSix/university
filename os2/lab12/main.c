#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
pthread_mutex_t mutex;
volatile int thread_n;
void* routine(void* unused) {
    for (int i = 0; i < 10; ++i) {
        while (thread_n != 1);
        // pthread_mutex_lock(&mutex);
        write(1, "2\n", sizeof("2\n"));
        thread_n = 0;
        // pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK);
    pthread_mutex_init(&mutex, &attr);
    if(pthread_create(&thread, NULL, routine, NULL) != 0) {
        printf("Can't create thread\n");
        return 1;
    }
    for (int i = 0; i < 10; ++i) {
        while (thread_n != 0);
        write(1, "1\n", sizeof("1\n"));
        thread_n = 1;
    }
    pthread_exit(0);
}
