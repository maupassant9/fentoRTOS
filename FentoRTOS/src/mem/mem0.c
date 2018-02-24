/*
* FileName: mem.c
* Author: Dong Xia
* This is source file of mem management.
* Realize a simple malloc function without
* the need to be freed.
*
* Change Records:
*      >> (24/Fev/2018): file created.
*
*/

/********************************************
* Include
********************************************/
#include <stdlib.h>
#include <stdio.h>
#include "../llist/llist.h"
#include "../Error/error.h"
#include "../type.h"
#include "../mem/mem0.h"
/********************************************
* Internal Function Declaration
********************************************/


/********************************************
* Internal Types and Variables
********************************************/


/********************************************
* External Variables
********************************************/
//memeory for heap size and head size
// the memory structure:
//   _______________________________________
//  |  HEAD_SZ   |  HEAP MEM AREA           |
//  |____________|__________________________|
// Head: save the information of the heap mem.
typedef struct _mem_heap_t{
    struct head_t{
        //the offset of the head of next blk
        MEM_ADDR_TYPE next_blk_offset;
        void * lock;
    } head;
    uint8_t heap[HEAP_SZ];
} _mem_heap_t;
_mem_heap_t _mem_heap;

void _NOP() {}
/********************************************
* Functions
********************************************/
/*------------------------------------------------
* FuncName: MemInit
* Descriptions: Initiate memory block
* Paras:
*  >>
* Return:
*  >>
* Change Records:
*  >> (24/Fev/2018): Create the function
*----------------------------------------------*/
void MemInit(void)
{
    LOCK(_mem_heap.head.lock);
    _mem_heap.head.next_blk_offset = 0;
    UNLOCK(_mem_heap.head.lock);
}


/*------------------------------------------------
* FuncName: malloc
* Descriptions: malloc a piece of memory
* Paras:
*  >> HEAD_MEM_SZ_TYPE: sz of the heap
* after calling this function.
* Return:
*  >> void *: addr of the returned memory.
* Change Records:
*  >> (24/Fev/2018): Create the function
*----------------------------------------------*/
void* my_malloc(HEAP_MEM_SZ_TYPE sz)
{
    MEM_ADDR_TYPE hd_addr, tail_addr;

    hd_addr = (MEM_ADDR_TYPE)_mem_heap.heap + \
            _mem_heap.head.next_blk_offset;
    tail_addr = hd_addr + (MEM_ADDR_TYPE)sz - 1;

    //the tail addr meets the end of buffer
    if(tail_addr >= (MEM_ADDR_TYPE)_mem_heap.heap \
            + HEAP_SZ) return NULL;
    // an overflow happens
    if(tail_addr == 0) return NULL;

    LOCK(_mem_heap.head.lock);
    _mem_heap.head.next_blk_offset += sz;
    UNLOCK(_mem_heap.head.lock);
}
