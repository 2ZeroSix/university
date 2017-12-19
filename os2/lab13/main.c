#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
sem_t sem[2];
void* routine(void* unused) {
    for (int i = 0; i < 10; ++i) {
        sem_wait(&sem[1]);
        write(1, "2\n", sizeof("2\n"));
        sem_post(&sem[0]);
    }
    return NULL;
}

int main() {
    sem_init(&sem[0], 0, 1); 
    sem_init(&sem[1], 0, 0); 
    pthread_t thread;
    if(pthread_create(&thread, NULL, routine, NULL) != 0) {
        printf("Can't create thread\n");
        return 1;
    }
    for (int i = 0; i < 10; ++i) {
        sem_wait(&sem[0]);
        write(1, "1\n", sizeof("1\n"));
        sem_post(&sem[1]);
    }
    pthread_exit(0);
}
