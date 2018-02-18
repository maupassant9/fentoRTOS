
/* 
* FileName: list.h
* Author: Dong Xia 
* This is head file of list.h
* 
* Change Records: 
*      >> (29/Dec/2017): Creation of file 
* 
*/

#ifndef  _FENTORTOS_SRC__LLIST_LLIST_H_
#define _FENTORTOS_SRC_LLIST_LLIST_H_
/********************************************
* Include 
********************************************/


/********************************************
* Macro 
********************************************/

#define LLIST_LOCK()
#define LLIST_UNLOCK()
/********************************************
* Type definition 
********************************************/
//node structure for linked list
typedef struct node_t{
    node_t * next;
    node_t * prev;
    void * data; // a pointer to some data
} node_t;

//linked list structure
typedef struct llist_t{
    node_t * head;
    node_t * tail;
    void * lock;
} llist_t;
/********************************************
* Function prototype 
********************************************/

#endif /* _FENTORTOS_SRC_LLIST_LLIST_H_ */

