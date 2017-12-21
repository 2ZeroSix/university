#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc, char* argv[]) {
    pthread_t thread;
    pid_t pid;
    if ((pid = fork()) == 0) {
        sem_t* sem[2];
        sem[0] = sem_open("/os1", O_CREAT, O_RDWR, 1);
        if (sem[0] == SEM_FAILED) {
            perror("10");
            exit(1);
        }
        sem[1] = sem_open("/os2", O_CREAT, O_RDWR, 0);
        if (sem[1] == SEM_FAILED) {
            perror("11");
            exit(1);
        }
        for (int i = 0; i < 10; ++i) {
            if (sem_wait(sem[1])) {
                perror(NULL);
                exit(1);
            }
            write(1, "2\n", sizeof("2\n"));
            if (sem_post(sem[0])) {
                perror(NULL);
                exit(1);
            }
        }
        if (sem_close(sem[0]) || sem_close(sem[1])) {
            perror(NULL);
        }
    } else if (pid != -1) {
        sem_t* sem[2];
        sem[0] = sem_open("/os1", O_CREAT, O_RDWR, 1);
        if (sem[0] == SEM_FAILED) {
            perror("00");
            exit(1);
        }
        sem[1] = sem_open("/os2", O_CREAT, O_RDWR, 0);
        if (sem[1] == SEM_FAILED) {
            perror("01");
            exit(1);
        }
        for (int i = 0; i < 10; ++i) {
            if (sem_wait(sem[0])) {
                perror(NULL);
                exit(1);
            }
            write(1, "1\n", sizeof("1\n"));
            if (sem_post(sem[1])) {
                perror(NULL);
                exit(1);
            }
        }
    }
}
