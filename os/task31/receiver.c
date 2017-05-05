#include "msg_const.h"

int sendInit(int msqid) {
    struct {long mtype; long mid;} msg = {MSG_RECV_TYPE, (long)getpid()};
    return msgsnd(msqid, &msg, MSG_RECV_SIZE, 0);
}

int sendFinalize(int msqid) {
    struct {long mtype; union { long mid; char mtext[MSG_DATA_SIZE];} d;} msg = {MSG_RECV_TYPE, {-(long)getpid()}};
    int retval = msgsnd(msqid, &msg, MSG_RECV_SIZE, 0);
    while(msgrcv(msqid, &msg, MSG_DATA_SIZE, getpid(), IPC_NOWAIT) != -1);
    return retval;
}

int main(int argc, char* argv[]) {
    int retval = 0;
    int count = argc >= 2 ? atoi(argv[1]) : 10;
    int key = geteuid();
    int msqid = msgget(key, IPC_CREAT | MSG_PERMISSIONS);
    if (msqid == -1)            return perror("can't get queue"), 1;
    if (sendInit(msqid) == -1)  return perror("can't send init"), 2;
    long id = getpid();
    struct {long msize; char mtext[MSG_DATA_SIZE];} msg = {0};
    for (int i = 0; i < count; ++i) {
        if (msgrcv(msqid, &msg, MSG_DATA_SIZE, id, 0) <= 0) {
            if (errno == EIDRM) break;
            perror("can't receive message");
            retval = 3;
            break;
        }
        if (printf("%s: %s", argv[0], msg.mtext) < 0) {
            perror("can't print message");
            retval = 4;
            break;
        }
    }
    sendFinalize(msqid);
    return retval;
}
