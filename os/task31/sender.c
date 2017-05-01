#include "msg_const.h"

int updateReceivers(int msqid, size_t* receiversCount, int final) {
    struct {long msize; char mtext[MSG_RECV_SIZE];} msg;
    if(*receiversCount == 0 && !final) {
        if (msgrcv(msqid, &msg, MSG_RECV_SIZE, MSG_RECV_TYPE, 0) != -1) {
            switch(msg.mtext[0]) {
                case '+':   ++*receiversCount; break; 
                default :   return -2;
            }
        }
    }
    while ( *receiversCount > 0 && msgrcv(msqid, &msg, MSG_RECV_SIZE, MSG_RECV_TYPE, final ? 0 :IPC_NOWAIT) != -1 ) {
        switch(msg.mtext[0]) {
            case '+':
                ++*receiversCount;
                // msg.mtext[0] = *receiversCount; // TODO
                // if (msgsnd(msqid, &msg, MSG_RECV_SIZE, 0) == -1) --*receiversCount; 
                break;
            case '-':
                --*receiversCount;
                break;
            default :   return -2;
        }
    }
    if (errno == ENOMSG || *receiversCount == 0)    return 0;
    else                    return-1;
}

int sendData(int msqid, void* type_and_data, size_t size, size_t receiversCount) {
    for ( size_t i = 0; i < receiversCount; ++i) {
        if (msgsnd(msqid, type_and_data, size, 0) == -1) return -1;
    }
    return 0;
}

int waitForInput(int fd, struct timeval tv) {
    fd_set fd_s;
    FD_ZERO(&fd_s);
    FD_SET(fd, &fd_s);
    switch (select(fd + 1, &fd_s, NULL, NULL, &tv)) {
        case -1:    return -1;
        case  0:    return  1;
        default:    return  0;
    }
}

int main(int argc, char** argv) {

    int key = geteuid();
    int msqid = msgget(key, IPC_CREAT | MSG_PERMISSIONS);
    if (msqid == -1) return perror("can't get queue"), 1;

    struct {long msize; char mtext[MSG_DATA_SIZE];} msgstr = {MSG_DATA_TYPE};
    size_t receiversCount = 0;

    int retval = 0;
    while(retval == 0) {
        if (fgets(msgstr.mtext, MSG_DATA_SIZE, stdin) == NULL) break;
        if (updateReceivers(msqid, &receiversCount, 0) < 0) {
            perror("can't update receivers");
            retval = 2;
            break;
        }
        if (receiversCount == 0) break;
        if (sendData(msqid, &msgstr, MSG_DATA_SIZE, receiversCount) == -1)   {
            perror("can't send data");
            retval = 3;
            break;
        }
    }
    updateReceivers(msqid, &receiversCount, 1);
    msgctl(msqid, IPC_RMID, NULL);

    return retval;
}
