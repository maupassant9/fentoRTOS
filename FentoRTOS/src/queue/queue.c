/*
* FileName: queue.c
* Author: Dong Xia
* This is source file of queue.
* A queue is a data structure that realize
* the dequeue and enqueue using a simple array.
* The maximum size of Queue can be 256.
*
* Change Records:
*      >> (18/Fev/2018):
*
*/

/********************************************
* Include
********************************************/
#include "../type.h"

#define CIR_ADD(data, max_val) {data++; if(data>=max_val) data = 0;}
/********************************************
* Internal Function Declaration
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
typedef qmem_t * queue_t;

/********************************************
* Internal Types and Variables
********************************************/

/********************************************
* External Variables
********************************************/


/********************************************
* Functions
********************************************/
queue_t QueueCreate(eb_t * eb){
    queue_t queue = (queue)malloc(sizeof(qmem_t));
    if(queue == NULL){
        eb->type = EB_TYPE_ERROR;
        eb->code = MEMORY_ALLOC_ERR;
        return;
    }
    queue->mem = malloc(sizeof(QUEUE_DATA_TYPE)*QUEUE_LENGTH);
    if(queue->mem == NULL)
    {
        eb->type = EB_TYPE_ERROR;
        eb->code = MEMORY_ALLOC_ERR;
        free(queue);
        return;
    }
    queue->head = 0;
    queue->tail = 0;
    queue->status = QUEUE_STATUS_EMPTY;

    eb->type = EB_TYPE_NOERROR;
    return queue;
}

//ele: should be the address of the element of the queue
//for example: for an pointer to point to structure, this
// should be the address of this pointer: &ptr_str;
void Enqueue(queue_t queue, void * ele, eb_t * eb)
{
    QUEUE_DATA_TYPE *data;

    //if it is full
    if(queue->status == QUEUE_STATUS_FULL){
        eb->type = EB_TYPE_ERROR;
        eb->code = MEMORY_FULL_ERR;
        return NULL;
    }
    data = (QUEUE_DATA_TYPE *)queue->mem;
    data[tail] = *(QUEUE_DATA_TYPE *)ele;
    eb->type = EB_TYPE_NOERROR;
    //if not full
    CIR_ADD(tail,QUEUE_LENGTH);
    if(head == tail) queue->status = QUEUE_STATUS_FULL;
    else queue->status == QUEUE_STATUS_NOT_FULL_NOT_EMPTY;
}

//return the address of the element
void * Dequeue(queue_t queue, eb_t * eb)
{
    void * return_val;
    //if it is empty.
    if(queue->status == QUEUE_STATUS_EMPTY)
    {
        eb->type = EB_TYPE_ERROR;
        eb->code = MEMORY_EMPTY_ERR;
        return NULL;
    }

    data = (QUEUE_DATA_TYPE *)queue->mem;
    return_val = (void *)&data[head];

    CIR_ADD(head,QUEUE_LENGTH);
    if(head == tail) queue->status = QUEUE_STATUS_EMPTY;
    else queue->status = QUEUE_STATUS_NOT_FULL_NOT_EMPTY;
    eb->type = EB_TYPE_NOERROR;
    return return_val;
}

boot_t IsEmpty(queue_t queue)
{
    if(queue->status == QUEUE_STATUS_EMPTY)
    {
        return TRUE;
    }
    return FALSE;
}

bool_t IsFull(queue_t queue)
{
    if(queue->status == QUEUE_STATUS_FULL)
    {
        return TRUE;
    }
    return FALSE;
}

