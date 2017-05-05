#include "msg_const.h"

RecvQueue* initQueue() {
    return (RecvQueue*)calloc(1, sizeof(RecvQueue));
}

void pushQueue(RecvQueue* que, long id) {
    if (!que)   return;
    if (!que->head) {
        que->head = que->tail = (RecvQueueNode*)calloc(1, sizeof(RecvQueueNode));
    } else {
        que->tail = que->tail->next = (RecvQueueNode*)calloc(1, sizeof(RecvQueueNode));
    }
    que->tail->id = id;
}

void removeIdQueue(RecvQueue* que, long id) {
    if (!que || (que->head) == NULL)   return;
    RecvQueueNode** indirect = &que->head;
    while((*indirect)->id != id && (indirect = &(*indirect)->next));
    free(*indirect);
    *indirect = (*indirect)->next;
}

// void printQueue(RecvQueue* que) {
//     for (RecvQueueNode* cur = que->head; cur != NULL; cur = cur->next) {
//         printf("%ld ", cur->id);
//     }
//     printf("\n");
// }

int isEmptyQueue(RecvQueue* que) {
    return !que || !que->head;
}

void freeQueue(RecvQueue* que) {
    if (!que)   return;
    RecvQueueNode *cur = que->head;
    while(cur) {
        RecvQueueNode *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    free(que);
}

int updateReceivers(int msqid, RecvQueue* recvs) {
    struct {long mtype; long mid;} msg;
    if(isEmptyQueue(recvs)) {
        if (msgrcv(msqid, &msg, MSG_RECV_SIZE, MSG_RECV_TYPE, 0) != -1) {
            if      (msg.mid >  MSG_MAX_TYPE)   pushQueue(recvs, msg.mid);
            else                                return -2;
        }
    }
    while (!isEmptyQueue(recvs) && msgrcv(msqid, &msg, MSG_RECV_SIZE, MSG_RECV_TYPE, IPC_NOWAIT) != -1) {
        if      (msg.mid >  MSG_MAX_TYPE)   pushQueue(recvs, msg.mid);
        else if (msg.mid < -MSG_MAX_TYPE)   removeIdQueue(recvs, -msg.mid);
        else                                return -2;
    }
    if (errno == ENOMSG || isEmptyQueue(recvs))    return 0;
    else                    return-1;
}

int sendData(int msqid, void* type_and_data, size_t size, RecvQueue* recvs) {
    RecvQueueNode* cur;
    for (cur = recvs ? recvs->head : NULL; cur != NULL; cur = cur->next) {
        *(long*)type_and_data = cur->id;
        if (msgsnd(msqid, type_and_data, size, 0) == -1) return -1;
    }
    return 0;
}

int main(int argc, char** argv) {
    int key = geteuid();
    int msqid = msgget(key, IPC_CREAT | MSG_PERMISSIONS);
    if (msqid == -1) return perror("can't get queue"), 1;

    struct {long mtype; char mtext[MSG_DATA_SIZE];} msgstr = {0};

    int retval = 0;
    RecvQueue* recvs = initQueue();
    while(retval == 0) {
        if (fgets(msgstr.mtext, MSG_DATA_SIZE, stdin) == NULL) break;
        if (updateReceivers(msqid, recvs) < 0) {
            perror("can't update receivers");
            retval = 2;
            break;
        }
        // printQueue(recvs);
        if (isEmptyQueue(recvs)) break;
        if (sendData(msqid, &msgstr, MSG_DATA_SIZE, recvs) == -1) {
            perror("can't send data");
            retval = 3;
            break;
        }
    }
    freeQueue(recvs);
    msgctl(msqid, IPC_RMID, NULL);

    return retval;
}
