#ifndef __MSG_CONST_H__
    #define __MSG_CONST_H__

    #include <sys/types.h>
    #include <sys/time.h>
    #include <sys/ipc.h>
    #include <sys/msg.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdio.h>
    #include <errno.h>
    #include <stdlib.h>

    #define MSG_PERMISSIONS 0660

    #define MSG_DATA_SIZE 256
    #define MSG_RECV_SIZE 1

    #define MSG_DATA_TYPE 1
    #define MSG_RECV_TYPE 2
    #define MSG_MAX_TYPE  2
#endif
