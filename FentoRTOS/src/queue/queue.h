
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
#define QUEUE_STATUS_NOT_FULL_NOT_EMPTY
/********************************************
* Type definition
********************************************/

/********************************************
* Function prototype
********************************************/

#endif /* _FENTORTOS_SRC_QUEUE_QUEUE_H_ */

