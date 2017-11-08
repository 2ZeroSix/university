#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<fcntl.h>

int main(int argc, char* argv[]) {
    sem_t* sem[2];
    sem[0] = sem_open("os2.first", O_CREAT);
    if (sem[0] == SEM_FAILED) {
        perror(NULL);
    }
    sem[1] = sem_open("os2.second", O_CREAT);
    if (sem[1] == SEM_FAILED) {
        perror(NULL);
    }
    pthread_t thread;
    pid_t pid;
    if ((pid = fork()) == 0) {
            for (int i = 0; i < 10; ++i) {
            if (sem_wait(sem[1])) {
                perror(NULL);
            }
            write(1, "2\n", sizeof("2\n"));
            if (sem_post(sem[0])) {
                perror(NULL);
            }
        }
        if (sem_close(sem[0]) || sem_close(sem[1])) {
            perror(NULL);
        }
    } else if (pid != -1) {
        for (int i = 0; i < 10; ++i) {
            if (sem_wait(sem[0])) {
                perror(NULL);
            }
            write(1, "1\n", sizeof("1\n"));
            if (sem_post(sem[1])) {
                perror(NULL);
            }
        }
    } else {
        if (sem_close(sem[0]) || sem_close(sem[1])) {
            perror(NULL);
        }
    }
}
