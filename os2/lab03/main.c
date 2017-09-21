#include<pthread.h>
#include<stdio.h>
void* routine(void* cstr) {
    for (int i = 0; i < 10; ++i)
        printf("%s\n", (char*)cstr);
    return NULL;
}

int main() {
    pthread_t threads[4];
    pthread_create(&threads[0], NULL, routine, "1");
    pthread_create(&threads[1], NULL, routine, "2");
    pthread_create(&threads[2], NULL, routine, "3");
    pthread_create(&threads[3], NULL, routine, "4");
    for (int i = 0; i < 4; ++i) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}
