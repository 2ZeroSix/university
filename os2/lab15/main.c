#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc, char* argv[]) {
    pthread_t thread;
    pid_t pid;
    if ((pid = fork()) == 0) {
        sem_t* sem[2];
        sem[0] = sem_open("/os1", O_CREAT, S_IRWXU, 1);
        if (sem[0] == SEM_FAILED) {
            perror("10");
            exit(1);
        }
        sem[1] = sem_open("/os2", O_CREAT, S_IRWXU, 0);
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
            exit(2);
        }
        if (sem_unlink("/os1") || sem_unlink("/os2")) {
            perror(NULL);
            exit(3);
        }
    } else if (pid != -1) {
        sem_t* sem[2];
        sem[0] = sem_open("/os1", O_CREAT, S_IRWXU, 1);
        if (sem[0] == SEM_FAILED) {
            perror("00");
            exit(1);
        }
        sem[1] = sem_open("/os2", O_CREAT, S_IRWXU, 0);
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
        if (sem_close(sem[0]) || sem_close(sem[1])) {
            perror(NULL);
            exit(2);
        }
    }
    return 0;
}
/*
int shm;
sem_t * mutex;

if ((shm = shm_open("myshm", O_RDWR | O_CREAT, S_IRWXU))   0) {
    perror("shm_open");
    exit(1);
}

if (ftruncate(shm, sizeof(sem_t)) < 0 ) {
    perror("ftruncate");
    exit(1);
}

if ((mutex = mmap(NULL, sizeof(sem_t), PROT_READ | PROT_WRITE, MAP_SHARED, shm, 0)) == MAP_FAILED) {
    perror("mmap");
    exit(1);
}

if (sem_init(mutex, 1, 1) < 0) {
    perror("semaphore initialization");
    exit(1);
}
 */