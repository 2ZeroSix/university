#include "fifo.h"


FifoNode* initFifoNode(const void* val, size_t sizeOfVal, FifoNode* next) {
    FifoNode* fifo = malloc(sizeof(FifoNode));
    fifo->val = calloc(1, sizeOfVal);
    if (val) memcpy(fifo->val, val, sizeOfVal);
    fifo->next = next;
    return fifo;
}

void freeFifoNode(FifoNode* node) {
    free(node->val);
    free(node);
}



Fifo* initFifoWithSize(size_t sizeOfVal) {
    Fifo* fifo = calloc(1, sizeof(Fifo));
    fifo->sizeOfVal = sizeOfVal;
    return fifo;
}

int FifoPush(Fifo* fifo, const void* val) {
    int err = 0;
    if (!fifo)                          err |= 0x1;
    else if (!fifo->head && fifo->tail) err |= 0x8;
    if (err)                            return err;

    FifoNode* node = initFifoNode(val, fifo->sizeOfVal, NULL);
    if (fifo->head) fifo->tail = fifo->tail->next   = node;
    else            fifo->tail = fifo->head         = node;
    return 0;
}

int FifoPeek(Fifo* fifo, void* val) {
    int err = 0;
    if (!fifo)                      err |= 0x1;
    else if (!fifo->head) {
                                    err |= 0x4;
        if (fifo->tail)             err |= 0x8;
    }
    if (!val)                       err |= 0x2;
    if (err)                        return err;

    memcpy(val, fifo->head->val, fifo->sizeOfVal);
    return 0;    
}

int FifoPop(Fifo* fifo, void* val) {
    int err = 0;
    if (!fifo)                      err |= 0x1;
    else if (!fifo->head) {
                                    err |= 0x4;
        if (fifo->tail)             err |= 0x8;
    }
    if (!val)                       err |= 0x2;
    if (err)                        return err;

    FifoNode* buf = fifo->head;
    fifo->head = fifo->head->next;
    memcpy(val, buf->val, fifo->sizeOfVal);
    freeFifoNode(buf);
    if (!fifo->head)    fifo->tail = NULL;
    return 0;
}

void freeFifo(Fifo* fifo) {
    if(!fifo) return;

    FifoNode* cur = fifo->head;
    while(cur) {
        FifoNode* buf = cur;
        cur = cur->next;
        freeFifoNode(buf);
    }
    free(fifo);
}