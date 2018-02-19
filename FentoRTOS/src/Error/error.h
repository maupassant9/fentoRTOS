
/*
* FileName:
* Author: Dong Xia
* This is head file of
*
* Change Records:
*      >> (29/Dec/2017): Creation of file
*
*/

#ifndef  _FENTORTOS_SRC_ERROR_ERROR_H_
#define _FENTORTOS_SRC_ERROR_ERROR_H_
/********************************************
* Include
********************************************/
#include "../type.h"

/********************************************
* Macro
********************************************/
//error block type:
#define EB_TYPE_ERROR 0x01
#define EB_TYPE_WARNING 0x02
#define EB_TYPE_NOERROR 0x00
//Error block code for type error
#define MEMORY_ALLOC_ERR 0x01
#define MEMORY_FULL_ERR 0x02


/********************************************
* Type definition
********************************************/
typedef struct eb_t {
    uint8_t type;
    uint8_t code;
}eb_t;

/********************************************
* Function prototype
********************************************/

#endif /*_FENTORTOS_SRC_ERROR_ERROR_H_*/

