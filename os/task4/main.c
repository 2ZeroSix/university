#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _QueueNode {
    char* data;
    struct _QueueNode* next;
} QueueNode;

typedef struct _Queue {
    QueueNode* head;
    QueueNode* tail;
} Queue;

Queue* initQueue() {
    return (Queue*)calloc(1, sizeof(Queue));
}

void pushQueue(Queue* que, char* data) {
    if (!que)       return;
    if (!que->head) {
        que->head = que->tail = (QueueNode*)calloc(1, sizeof(QueueNode));
    } else {
        que->tail = que->tail->next = (QueueNode*)calloc(1, sizeof(QueueNode));
    }
    que->tail->data = data;
}

char* popQueue(Queue* que) {
    if (!que)       return NULL;
    if (!que->head) return NULL;
    char* retVal = que->head->data;
    QueueNode* tmp = que->head;
    if (que->head == que->tail) que->tail = NULL;
    que->head = que->head->next;
    free(tmp);
    return retVal;
}

void freeQueue(Queue** que) {
    if (!que)       return;
    if (!*que)       return;
    QueueNode *cur = (*que)->head;
    while(cur) {
        QueueNode *tmp = cur;
        cur = cur->next;
        free(tmp->data);
        free(tmp);
    }
    free(*que);
}


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
            length = length * 3 / 2;
            str = realloc(str, length);
        } else {
            if (str[realLength - 1] == '\n') str[realLength - 1] = '\0';
            break;
        }
    }
    return str;
}

int main(int argc, char** argv) {
    Queue* queue = initQueue();
    char* str;
    while((str = readString(stdin))) {
        if(str[0] == '.') break;
        pushQueue(queue, str);
    }
    while((str = popQueue(queue)) != NULL) {
        printf("%s\n", str);
        free(str);
    }
    freeQueue(&queue);
    return 0;
}
