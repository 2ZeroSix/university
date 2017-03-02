#include "lifo.h"


LifoNode* initLifoNode(const void* val, size_t sizeOfVal, LifoNode* next) {
    LifoNode* lifo = malloc(sizeof(LifoNode));
    lifo->val = calloc(1, sizeOfVal);
    if (val) memcpy(lifo->val, val, sizeOfVal);
    lifo->next = next;
    return lifo;
}

void freeLifoNode(LifoNode* node) {
    free(node->val);
    free(node);
}



Lifo* initLifoWithSize(size_t sizeOfVal) {
    Lifo* lifo = calloc(1, sizeof(Lifo));
    lifo->sizeOfVal = sizeOfVal;
    return lifo;
}

int LifoPush(Lifo* lifo, const void* val) {
    int err = 0;
    if (!lifo)  err |= 0x1;
    if (err)    return err;

    lifo->head = initLifoNode(val, lifo->sizeOfVal, lifo->head);
    return 0;
}

int LifoPeek(Lifo* lifo, void* val) {
    int err = 0;
    if (!lifo)              err |= 0x1;
    else if (!lifo->head)   err |= 0x4;
    if (!val)               err |= 0x2;
    if (err)                return err;

    memcpy(val, lifo->head->val, lifo->sizeOfVal);
    return 0;    
}

int LifoPop(Lifo* lifo, void* val) {
    int err = 0;
    if (!lifo)              err |= 0x1;
    else if (!lifo->head)   err |= 0x4;
    if (!val)               err |= 0x2;
    if (err)                return err;

    memcpy(val, lifo->head->val, lifo->sizeOfVal);
    LifoNode* buf = lifo->head;
    lifo->head = lifo->head->next;
    freeLifoNode(buf);
    return 0;
}

void freeLifo(Lifo* lifo) {
    if(!lifo) return;

    LifoNode* cur = lifo->head;
    while(cur) {
        LifoNode* buf = cur;
        cur = cur->next;
        freeLifoNode(buf);
    }
    free(lifo);
}