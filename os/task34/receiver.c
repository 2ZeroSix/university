#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int shmid = shmget(geteuid(), 256, IPC_CREAT | 0600);
    char* buf = shmat(shmid, NULL, SHM_RDONLY);
    int semid = semget(geteuid(), 2, IPC_CREAT | 0600);
    struct sembuf sops[2];

    sops[0].sem_num = 0;
    sops[0].sem_op  = -1;
    sops[0].sem_flg = 1;

    sops[1].sem_num = 1;
    sops[1].sem_op  = 1;
    sops[1].sem_flg = 0;

    while(semop(semid, sops, 1) == 0 && fputs(buf, stdout) >= 0 && semop(semid, sops + 1, 1) == 0);

    shmdt(buf);
    semctl(semid, 0, IPC_RMID);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
