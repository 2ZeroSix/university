#include "msg_const.h"

int sendInit(int msqid) {
    struct {long msize; char mtext[MSG_RECV_SIZE];} msg = {MSG_RECV_TYPE, {'+'}};
    if (msgsnd(msqid, &msg, MSG_RECV_SIZE, 0)                == -1) return -1;
    if (msgrcv(msqid, &msg, MSG_RECV_SIZE, MSG_RECV_TYPE, 0) == -1) return -1;
    return msg.mtext[0];
}

int sendFinalize(int msqid) {
    struct {long msize; char mtext[MSG_RECV_SIZE];} msg = {MSG_RECV_TYPE, {'-'}};
    return msgsnd(msqid, &msg, MSG_RECV_SIZE, 0);
}

int main(int argc, char* argv[]) {
    int retval = 0;
    int count = argc >= 2 ? atoi(argv[1]) : 10;
    int key = geteuid();
    int msqid = msgget(key, IPC_CREAT | MSG_PERMISSIONS);
    if (msqid == -1)            return perror("can't get queue"), 1;
    if (sendInit(msqid) == -1)  return perror("can't send init"), 2;

    struct {long msize; char mtext[MSG_DATA_SIZE];} msg = {MSG_DATA_TYPE};
    for (int i = 0; i < count; ++i) {
        if (msgrcv(msqid, &msg, MSG_DATA_SIZE, MSG_DATA_TYPE, 0) <= 0) {
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
    if (sendFinalize(msqid) == -1) {
        perror("can't send finalize");
        retval = retval ? retval : 5;
    }
    return retval;
}
