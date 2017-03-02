#ifndef _FIFO_H_
#define _FIFO_H_

#include <stdlib.h>
#include <stddef.h>
#include <string.h>

/**
 * structure of node of FIFO queue
 */
typedef struct FifoNode {
    void* val;
    struct FifoNode* next;
} FifoNode;

/**
 * initialize node of FIFO queue
 *
 * @param   val        pointer to a value that will be stored
 *                     if val==NULL then
 *                         value in node will be initialized by zeros
 * @param   sizeOfVal  size of value that will be stored
 * @param   next       next node (may be NULL)
 *
 * @return             initialized node
 */

FifoNode*   initFifoNode(const void* val, size_t sizeOfVal, FifoNode* next);
/**
 * free memory from node of FIFO queue
 *
 * @param   node  node that will be deleted
 */
void        freeFifoNode(FifoNode* node);


/**
 * structure of FIFO queue
 */
typedef struct Fifo {
    size_t sizeOfVal;
    FifoNode* head;
    FifoNode* tail;
} Fifo;

/**
 * macro for easy initialization of FIFO queue
 */
#define initFifo(TYPE) initFifoWithSize(sizeof(TYPE))

/**
 * initialize FIFO queue
 *
 * @param   sizeOfVal  size of values that queue will store
 *
 * @return             initialized queue
 */
Fifo*   initFifoWithSize(size_t sizeOfVal);

/**
 * push in FIFO queue
 *
 * @param   fifo  initialized FIFO queue
 * @param   val   pointer to a value that will be pushed
 *                if val==NULL then
 *                    value in node will be initialized by zeros  
 * 
 * @return        0x0 on success;
 *                bits of various errors:
 *                    0x1 on fifo == NULL;
 *                    0x8 on tail without head.
 */
int     FifoPush(Fifo* fifo, const void* val);

/**
 * peek in FIFO queue
 *
 * @param   fifo  initialized FIFO queue
 * @param   val   allocated memory for a copy of value
 *
 * @return        0x0 on success;
 *                bits of various errors:
 *                    0x1 on fifo == NULL;
 *                    0x2 on val == NULL;
 *                    0x4 on fifo->head == NULL;
 *                    0x8 on tail without head.
 */
int     FifoPeek(Fifo* fifo, void* val);

/**
 * peek in FIFO queue
 *
 * @param   fifo  initialized FIFO queue
 * @param   val   allocated memory for copy of value
 *
 * @return        0x0 on success;
 *                bits of various errors:
 *                    0x1 on fifo == NULL;
 *                    0x2 on val == NULL;
 *                    0x4 on fifo->head == NULL;
 *                    0x8 on tail without head.
 */
int     FifoPop(Fifo* fifo, void* val);

/**
 * free memory from FIFO queue
 *
 * @param   fifo  initialized FIFO queue
 */
void    freeFifo(Fifo* fifo);

#endif
