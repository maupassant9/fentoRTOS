/*
* FileName: queue.c
* Author: Dong Xia
* This is source file of queue.
* A queue is a data structure that realize
* the dequeue and enqueue using a simple array.
* The maximum size of Queue can be 256.
*
* Change Records:
*      >> (18/Fev/2018):file created
*      >> (19/Fev/2018):add more comments
*
*/

/********************************************
* Include
********************************************/
#include <stdlib.h>
#include "../Error/error.h"
#include "../type.h"
#include "queue.h"

#define CIR_ADD(data,max_val) {data++; if(data>=max_val) {data = 0;}}
/********************************************
* Internal Function Declaration
********************************************/


/********************************************
* Internal Types and Variables
********************************************/

/********************************************
* External Variables
********************************************/


/********************************************
* Functions
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
queue_t QueueCreate(eb_t *eb)
{
    queue_t queue = (queue_t)malloc(sizeof(qmem_t));
    if(queue == NULL){
        eb->type = EB_TYPE_ERROR;
        eb->code = MEMORY_ALLOC_ERR;
        return NULL;
    }
    queue->mem = malloc(sizeof(QUEUE_DATA_TYPE)*QUEUE_LENGTH);
    if(queue->mem == NULL)
    {
        eb->type = EB_TYPE_ERROR;
        eb->code = MEMORY_ALLOC_ERR;
        free(queue);
        return NULL;
    }
    queue->head = 0;
    queue->tail = 0;
    queue->status = QUEUE_STATUS_EMPTY;

    eb->type = EB_TYPE_NOERROR;
    return queue;
}


/*------------------------------------------------
* FuncName: Enqueue
* Descriptions: Enqueue
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
    data[queue->tail] = *(QUEUE_DATA_TYPE *)ele;
    eb->type = EB_TYPE_NOERROR;
    //if not full
    CIR_ADD(queue->tail,QUEUE_LENGTH);
    if(queue->head == queue->tail) queue->status = QUEUE_STATUS_FULL;
    else queue->status = QUEUE_STATUS_NOT_FULL_NOT_EMPTY;
}

/*------------------------------------------------
* FuncName: Dequeue
* Descriptions: Dequeue
* Paras:
*  >> queue: queue structure
*  >> eb_t *: error block
* Return:
*  >> void *: queue element that to be added to queue
*     should be the address of the element of the queue
* Change Records:
*  >> (18/Fev/2018): Create the function
*----------------------------------------------*/
void * Dequeue(queue_t queue, eb_t * eb)
{
    void * return_val;
    QUEUE_DATA_TYPE *data;
    //if it is empty.
    if(queue->status == QUEUE_STATUS_EMPTY)
    {
        eb->type = EB_TYPE_ERROR;
        eb->code = MEMORY_EMPTY_ERR;
        return NULL;
    }

    data = (QUEUE_DATA_TYPE *)queue->mem;
    return_val = (void *)&data[queue->head];

    CIR_ADD(queue->head,QUEUE_LENGTH);
    if(queue->head == queue->tail) queue->status = QUEUE_STATUS_EMPTY;
    else queue->status = QUEUE_STATUS_NOT_FULL_NOT_EMPTY;
    eb->type = EB_TYPE_NOERROR;
    return return_val;
}


/*------------------------------------------------
* FuncName: IsEmpty
* Descriptions: Check if the queue is empty
* Paras:
*  >> queue: queue structure
* Return:
*  >> bool_t: true for empty; false for not empty
* Change Records:
*  >> (18/Fev/2018): Create the function
*----------------------------------------------*/
bool_t IsEmpty(queue_t queue)
{
    if(queue->status == QUEUE_STATUS_EMPTY)
    {
        return TRUE;
    }
    return FALSE;
}

/*------------------------------------------------
* FuncName: IsFull
* Descriptions: Check if the queue is full
* Paras:
*  >> queue: queue structure
* Return:
*  >> bool_t: true for full; false for not full
* Change Records:
*  >> (18/Fev/2018): Create the function
*----------------------------------------------*/
bool_t IsFull(queue_t queue)
{
    if(queue->status == QUEUE_STATUS_FULL)
    {
        return TRUE;
    }
    return FALSE;
}

