#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void* routine(void* args) {
    pthread_mutex_t *mutex = (pthread_mutex_t*)args;
    for (int i = 0; i < 10; ++i) {
        write(1, "2\n", sizeof("2\n"));
        pthread_mutex_lock(&mutex[1]);
        pthread_mutex_unlock(&mutex[2]);
        pthread_mutex_lock(&mutex[0]);
        pthread_mutex_unlock(&mutex[1]);
        pthread_mutex_lock(&mutex[2]);
        pthread_mutex_unlock(&mutex[0]);
    }
    return NULL;
}

int main() {
    pthread_mutex_t mutex[3];
    pthread_t thread;
    {
        pthread_mutexattr_t attr;
        if (pthread_mutexattr_init(&attr)) {
            perror("error while init mutexattr");
            return 1;
        }
        if (pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK_NP)) {
            perror("error while set type");
            return 2;
        }
        for (int i = 0; i < 3; ++i)
            pthread_mutex_init(&mutex[i], &attr);
    }
    for (int i = 0; i < 2; ++i)
        pthread_mutex_lock(&mutex[i]);
    if(pthread_create(&thread, NULL, routine, mutex)) {
        printf("Can't create thread\n");
        return 3;
    }
    for (int i = 0; i < 10; ++i) {
        write(1, "1\n", sizeof("1\n"));
        pthread_mutex_lock(&mutex[1]);
        pthread_mutex_unlock(&mutex[2]);
        pthread_mutex_lock(&mutex[0]);
        pthread_mutex_unlock(&mutex[1]);
        pthread_mutex_lock(&mutex[2]);
        pthread_mutex_unlock(&mutex[0]);
    }
    pthread_mutex_unlock(&mutex[1]);
    pthread_exit(0);
}
