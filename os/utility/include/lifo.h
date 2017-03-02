#ifndef _LIFO_H_
#define _LIFO_H_

#include <stdlib.h>
#include <stddef.h>
#include <string.h>

/**
 * structure of node of LIFO queue
 */
typedef struct LifoNode {
    void* val;
    struct LifoNode* next;
} LifoNode;

/**
 * initialize node of LIFO queue
 *
 * @param   val        pointer to a value that will be stored
 *                     if val==NULL then
 *                         value in node will be initialized by zeros
 * @param   sizeOfVal  size of value that will be stored
 * @param   next       next node (may be NULL)
 *
 * @return             initialized node
 */

LifoNode*   initLifoNode(const void* val, size_t sizeOfVal, LifoNode* next);
/**
 * free memory from node of LIFO queue
 *
 * @param   node  node that will be deleted
 */
void        freeLifoNode(LifoNode* node);


/**
 * structure of LIFO queue
 */
typedef struct Lifo {
    size_t sizeOfVal;
    LifoNode* head;
} Lifo;

/**
 * macro for easy initialization of LIFO queue
 */
#define initLifo(TYPE) initLifoWithSize(sizeof(TYPE))

/**
 * initialize LIFO queue
 *
 * @param   sizeOfVal  size of values that queue will store
 *
 * @return             initialized queue
 */
Lifo*   initLifoWithSize(size_t sizeOfVal);

/**
 * push in LIFO queue
 *
 * @param   lifo  initialized LIFO queue
 * @param   val   pointer to a value that will be pushed
 *                if val==NULL then
 *                    value in node will be initialized by zeros  
 * 
 * @return        0 on success;
 *                1 on lifo == NULL;
 */
int     LifoPush(Lifo* lifo, const void* val);

/**
 * peek in LIFO queue
 *
 * @param   lifo  initialized LIFO queue
 * @param   val   allocated memory for a copy of value
 *
 * @return        0x0 on success;
 *                bits of various errors:
 *                    0x1 on lifo == NULL;
 *                    0x2 on val == NULL;
 *                    0x4 on lifo->head == NULL.
 */
int     LifoPeek(Lifo* lifo, void* val);

/**
 * peek in LIFO queue
 *
 * @param   lifo  initialized LIFO queue
 * @param   val   allocated memory for copy of value
 *
 * @return        0x0 on success;
 *                bits of various errors:
 *                    0x1 on lifo == NULL;
 *                    0x2 on val == NULL;
 *                    0x4 on lifo->head == NULL.
 */
int     LifoPop(Lifo* lifo, void* val);

/**
 * free memory from LIFO queue
 *
 * @param   lifo  initialized LIFO queue
 */
void    freeLifo(Lifo* lifo);

#endif
