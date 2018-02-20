
/*
* FileName: queue.h
* Author: Dong Xia
* This is head file of queue.
*
* Change Records:
*      >> (19/Fev/2018): Creation of file
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
/*------------------------------------------------
* FuncName: QueueCreate
* Descriptions: Allocate the memory for queue
* and initilate the data structure of queue.
* Paras:
*  >> eb_t *: error block
* Return:
*  >> queue_t: queue handle
* Change Records:
*  >> (18/Fev/2018): Create the function
*----------------------------------------------*/
queue_t QueueCreate(eb_t * eb);

/*------------------------------------------------
* FuncName: Enqueue
* Usage: Enqueue
* Paras:
*  >> queue: queue structure
*  >> void *: queue element that to be added to queue
*     should be the address of the element of the queue
*  >> eb_t *: error block
* Return:
*  >> 
* Change Records:
*  >> (18/Fev/2018): Create the function
*----------------------------------------------*/
void Enqueue(queue_t queue, void * ele, eb_t * eb);

/*------------------------------------------------
* FuncName: Dequeue
* Usage: Dequeue
* Paras:
*  >> queue: queue structure
*  >> eb_t *: error block
* Return:
*  >> void *: queue element that to be added to queue
*     should be the address of the element of the queue
* Change Records:
*  >> (18/Fev/2018): Create the function
*----------------------------------------------*/
void *Dequeue(queue_t queue, eb_t * eb);

/*------------------------------------------------
* FuncName: IsEmpty
* Usage: Check if the queue is empty
* Paras:
*  >> queue: queue structure
* Return:
*  >> bool_t: true for empty; false for not empty
* Change Records:
*  >> (18/Fev/2018): Create the function
*----------------------------------------------*/
bool_t IsEmpty(queue_t queue);

/*------------------------------------------------
* FuncName: IsFull
* Usage: Check if the queue is full
* Paras:
*  >> queue: queue structure
* Return:
*  >> bool_t: true for full; false for not full
* Change Records:
*  >> (18/Fev/2018): Create the function
*----------------------------------------------*/
bool_t IsFull(queue_t queue);

#endif /* _FENTORTOS_SRC_QUEUE_QUEUE_H_ */

