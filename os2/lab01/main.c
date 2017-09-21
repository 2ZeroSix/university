#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
void* routine(void* unused) {
    for (int i = 0; i < 10; ++i)
        write(1, "2\n", sizeof("2\n"));
    return NULL;
}

int main() {
    pthread_t thread;
    if(pthread_create(&thread, NULL, routine, NULL) != 0) {
        printf("Can't create thread\n");
        return 1;
    }
    for (int i = 0; i < 10; ++i)
        write(1, "1\n", sizeof("1\n"));
    pthread_exit(0);
}
