
/*
* FileName:
* Author: Dong Xia
* This is head file of
*
* Change Records:
*      >> (29/Dec/2017): Creation of file
*
*/

#ifndef  _FENTORTOS_SRC_QUEUE_QUEUE_H_
#define _FENTORTOS_SRC_QUEUE_QUEUE_H_
/********************************************
* Include
********************************************/
#include "../type.h"
#include "../Error/error.h"

/********************************************
* Macro
********************************************/
//The total size of the queue, should be no
// more than 256.
#define QUEUE_LENGTH 16
//The type of data supported is pointer, int
// char, long, short, float, double.
#define QUEUE_DATA_TYPE char

#define QUEUE_STATUS_EMPTY 0x01
#define QUEUE_STATUS_FULL 0x00
#define QUEUE_STATUS_NOT_FULL_NOT_EMPTY 0x02
/********************************************
* Type definition
********************************************/
//Data structure for queue structure
// only for internal use.
typedef struct qmem_t{
    //head position of queue
    uint8_t head;
    //tail position of queue
    uint8_t tail;
    //the memory buffer for queue
    void *mem;
    //a mark for empty or not
    uint8_t status;
}qmem_t;
typedef qmem_t* queue_t;

/********************************************
* Function prototype
********************************************/
queue_t QueueCreate(eb_t * eb);
void Enqueue(queue_t queue, void * ele, eb_t * eb);
void *Dequeue(queue_t queue, eb_t * eb);
bool_t IsEmpty(queue_t queue);
bool_t IsFull(queue_t queue);
#endif /* _FENTORTOS_SRC_QUEUE_QUEUE_H_ */

