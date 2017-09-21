#include<pthread.h>
#include<stdio.h>
void* routine(void* unused) {
    for (int i = 0; i < 10; ++i)
        printf("2\n");
    return NULL;
}

int main() {
    pthread_t thread;
    if (pthread_create(&thread, NULL, routine, NULL) != 0) {
        printf("Can't create thread\n");
        return 1;
    }
    if (pthread_join(thread, NULL) != 0) {
        printf("Can't join thread\n");
    }
    for (int i = 0; i < 10; ++i)
        printf("1\n");
    return 0;
}
