#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
pthread_mutex_t mutex;
pthread_cond_t cond;
int thread_n = 0;
void* routine(void* unused) {
    for (int i = 0; i < 10; ++i) {
        pthread_mutex_lock(&mutex);
        while (thread_n != 1)
            pthread_cond_wait(&cond, &mutex);
        pthread_mutex_unlock(&mutex);
        write(1, "2\n", sizeof("2\n"));
        thread_n = 0;
        pthread_mutex_lock(&mutex);
        pthread_cond_signal(&cond);
    }
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_cond_init(&cond, NULL);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK);
    pthread_mutex_init(&mutex, &attr);
    if(pthread_create(&thread, NULL, routine, NULL) != 0) {
        printf("Can't create thread\n");
        return 1;
    }
    for (int i = 0; i < 10; ++i) {
        pthread_mutex_lock(&mutex);
        while (thread_n != 0)
            pthread_cond_wait(&cond, &mutex);
        pthread_mutex_unlock(&mutex);
        write(1, "1\n", sizeof("1\n"));
        thread_n = 1;
        pthread_mutex_lock(&mutex);
        pthread_cond_signal(&cond);
    }
    pthread_mutex_unlock(&mutex);
    pthread_exit(0);
}
