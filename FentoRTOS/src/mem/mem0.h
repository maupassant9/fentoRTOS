
/*
* FileName: list.h
* Author: Dong Xia
* This is head file of list.h
*
* Change Records:
*      >> (29/Dec/2017): Creation of file
*
*/

#ifndef  _FENTORTOS_SRC__MEM_MEM1_H_
#define  _FENTORTOS_SRC__MEM_MEM1_H_
/********************************************
* Include
********************************************/
#include "../Error/error.h"

/********************************************
* Macro
********************************************/
//The size of heap.
#define HEAP_SZ 340
//The type of size of heap that should
// be used to save the address. For example,
// when HEAP_SZ > 256 and < 65524, uint16_t
// should be used.
#define HEAP_MEM_SZ_TYPE uint32_t
//The type of mememory addr: for example
// am addr line of 8 bit should use uint8_t
#define MEM_ADDR_TYPE uint32_t

#define LOCK(lock) _NOP()//Semaphore_lock(lock)
#define UNLOCK(lock) _NOP()
/********************************************
* Type definition
********************************************/

/********************************************
* Function prototype
********************************************/
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
void* my_malloc(HEAP_MEM_SZ_TYPE sz);

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
void MemInit(void);

#endif /*  _FENTORTOS_SRC__MEM_MEM1_H_ */


