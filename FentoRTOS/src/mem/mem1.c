/*
* FileName: mem.c
* Author: Dong Xia
* This is source file of mem management.
* Realize a simple malloc function without
* the need to be freed.
*
* Change Records:
*      >> (20/Fev/2018): file created.
*
*/

/********************************************
* Include
********************************************/
#include <stdlib.h>
#include "llist.h"
#include "../Error/error.h"
#include "../type.h"

/********************************************
* Internal Function Declaration
********************************************/



/********************************************
* Internal Types and Variables
********************************************/
#define HEAP_SZ 340
#define BLOCK_SZ 32

#define TABLE_SZ (HEAP_SZ/BLOCK_SZ)/8 + 1

/********************************************
* External Variables
********************************************/
//memeory for heap size and table size
// the memory structure:
//   _______________________________________
//  | TABLE_SZ   |  HEAP MEM AREA           |
//  |____________|__________________________|
// Table:
//        XXXX XXXX....XXXX 1111* 
// block0_|               |_block N
//  -- bit = 0: free
//  -- bit = 1: ocupied
uint8_t _mem_heap[HEAP_SZ+TABLE_SZ];

/********************************************
* Functions
********************************************/
/*------------------------------------------------
* FuncName: LlistCreate
* Descriptions: Create a linked list structure.
* Paras:
*  >> eb_t *: error block, should be checked
* after calling this function.
* Return:
*  >> llist_t *: a created linked list
* Change Records:
*  >> (18/Fev/2018): Create the function
*----------------------------------------------*/



/*------------------------------------------------
* FuncName: FindBlock
* Descriptions: Find consecutive free block with the 
* size larger or equal than needed
* Paras:
*  >> eb_t *: error block, should be checked
* after calling this function.
* Return:
*  >> uint16_t: block number 0 - N
* Change Records:
*  >> (20/Fev/2018): Create the function
*----------------------------------------------*/
uint16_t FindBlock(uint16_t sz)
{
    uint16_t block_num = 0;
    uint16_t cnt;

    for(cnt = 0; cnt < TABLE_SZ; cnt++)
    {
        for(bit = 0x01; bit != 0; bit = bit << 1)
        {
            if(!(_mem_heap[cnt]&bit)) block_num++;
            else block_num = 0;
            if(block_num == sz) break;
        }
        if(block_num == sz) break;
    }

    //how to calculate block number?
    block_num = (cnt << 3);
    cnt = 0;
    while((bit = bit >> 1) == 0x00)
    {
        cnt++;
    }
    block_num += cnt;
    return block_num -1;
}