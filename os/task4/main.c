#include <stdio.h>
#include <stdlib.h>
#include "fifo.h"
#include "lifo.h"

char* readString(FILE* fin) {
    size_t length = 255;
    size_t offset = 0;
    char* str = calloc(length, sizeof(char));
    while(1) {
        if (!fgets(str + offset, length - offset, fin))  {
            free(str);
            return NULL;
        }
        size_t realLength = strlen(str + offset) + offset;
        if ( realLength == length - 1 &&
             str[realLength - 1] != '\n' &&
             !feof(fin)) {
            offset = length-1;
            length = length*2 + 1;
            str = realloc(str, length);
        } else {
            if (str[realLength - 1] == '\n') str[realLength - 1] = '\0';
            break;
        }
    }
    return str;
}

#define Main(Queue, Init, Push, Pop, Free) {\
    Queue* queue = Init(char*);\
    char* str;\
    while((str = readString(stdin))) {\
        if(str[0] == '.') break;\
        Push(queue, &str);\
    }\
    while(Pop(queue, &str) == 0) {\
        printf("%s\n", str);\
        free(str);\
    }\
    Free(queue);\
}

int main(int argc, char** argv) {
    if (argc == 2 && strcmp(argv[1], "lifo") == 0) {
        Main(Lifo, initLifo, LifoPush, LifoPop, freeLifo);
    } else {
        Main(Fifo, initFifo, FifoPush, FifoPop, freeFifo);
    }
    return 0;
}
