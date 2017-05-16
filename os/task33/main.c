#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/select.h>

int waitForInput(struct timeval tv) {
    fd_set fd_s;
    FD_ZERO(&fd_s);
    FD_SET(0, &fd_s);
    switch (select(1, &fd_s, NULL, NULL, &tv)) {
        case -1:    return -1;
        case  0:    return  1;
        default:    return  0;
    }
}

int main(int argc, char* argv[]) {
    pid_t p = fork();
    struct sembuf sops[2];
    sops[0].sem_num = 0;
    sops[0].sem_op = 1;
    sops[0].sem_flg = 0;
    sops[1].sem_num = 0;
    sops[1].sem_op = -1;
    sops[1].sem_flg = 0;

    switch(p) {
        case -1: return -1;
        case 0: {
            int module1 = semget(getpid(), 1, IPC_CREAT | 0660);
            switch(p = fork()) {
                case -1: return -1;
                case 0: {
                    int detailA = semget(getpid(), 1, IPC_CREAT | 0660);
                    while(1) {
                        sleep(2);
                        printf("detail A: complete\n");
                        fflush(stdout);
                        if (semop(detailA, sops, 1) != 0) break;
                    }
                    return 0;
                }
                default: {
                    int detailA = semget(p, 1, IPC_CREAT | 0660);
                    switch(p = fork()) {
                        case -1: return -1;
                        case 0: {
                            int detailB = semget(getpid(), 1, IPC_CREAT | 0660);
                            while(1) {
                                sleep(3);
                                printf("detail B: complete\n");
                                fflush(stdout);
                                if (semop(detailB, sops, 1) != 0) break;
                            }
                            return 0;                    
                        }
                        default: {
                            int detailB = semget(p, 1, IPC_CREAT | 0660);
                            while(semop(detailA, sops + 1, 1) == 0 && semop(detailB, sops + 1, 1) == 0) {
                                printf("Module 1: complete\n");
                                fflush(stdout);
                                if (semop(module1, sops, 1) != 0) break;
                            }
                            semctl(detailA, 0, IPC_RMID);
                            semctl(detailB, 0, IPC_RMID);
                            return 0;                    
                        }
                    }
                }
            }
        }
        default: {
            int module1 = semget(p, 1, IPC_CREAT | 0660);
            switch(p = fork()) {
                case -1: return -1;
                case 0: { // detail C
                    int detailC = semget(getpid(), 1, IPC_CREAT | 0660);
                    while(1) {
                        sleep(4);
                        printf("detail C: complete\n");
                        fflush(stdout);
                        if(semop(detailC, sops, 1) != 0) break;
                    }
                    return 0;
                }
                default: { // Widget
                    int detailC = semget(p, 1, IPC_CREAT | 0660);
                    while(semop(module1, sops + 1, 1) == 0 && semop(detailC, sops + 1, 1) == 0 && waitForInput((struct timeval){0}) == 1) {
                        printf("Widget : complete\n");
                        fflush(stdout);
                    }
                    semctl(module1, 0, IPC_RMID);
                    semctl(detailC, 0, IPC_RMID);
                    return 0;
                }
            }
        }
    }
}