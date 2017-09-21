#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
void* routine(void* unused) {
    for (;;)
        write(1, "1", sizeof("1"));
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
