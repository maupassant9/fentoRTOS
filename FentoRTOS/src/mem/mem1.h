
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

/********************************************
* Type definition
********************************************/

/********************************************
* Function prototype
********************************************/
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
uint16_t FindBlock(uint16_t sz);

#endif /*  _FENTORTOS_SRC__MEM_MEM1_H_ */


