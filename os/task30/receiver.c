#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <stdio.h>
#define STR_SIZE 256

int main() {
    int retval = 0;
    int key = geteuid();
    int msqid = msgget(key, IPC_CREAT | 0660);
    if (msqid == -1) return 2;
    struct {long msize; char mtext[STR_SIZE];} msg = {0};
    while(1) {
        if (msgrcv(msqid, &msg, STR_SIZE, 0, 0) <= 0)   {retval = 0; break;}
        if (fputs(msg.mtext, stdout) == EOF)            {retval = 1; break;}
    }
    return retval;
}
