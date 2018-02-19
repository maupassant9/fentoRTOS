
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
#include "../Error/error.h"

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
    struct node_t * next;
    struct node_t * prev;
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
llist_t * LlistCreate(eb_t *eb);

/*------------------------------------------------
* FuncName: LlistDel
* Descriptions: Delete the node in the linked list
* Paras:
*  >> llist_t * : a linked list
*  >> node_t *: Node to be deleted.
* Return:
*  >>
* Change Records:
*  >> (18/Fev/2018): Create the function
*----------------------------------------------*/
void * LlistDel(llist_t * llist, node_t * curr);

/*------------------------------------------------
* FuncName: LlistInsertBefore
* Descriptions: Insert before a node
* Paras:
*  >> llist *: an linked list
*  >> node_t *: a node to be inserted before
*  >> node_t *: a node to insert
* Return:
*  >>
* Change Records:
*  >> (18/Fev/2018): Create the function
*----------------------------------------------*/
void LlistInsertBefore(llist_t * list, node_t * curr, node_t * new_node);

/*------------------------------------------------
* FuncName: LlistInsetAfter
* Descriptions: Insert after a node
* Paras:
*  >> llist *: an linked list
*  >> node_t *: a node to be inserted after
*  >> node_t *: a node to insert
* Return:
*  >>
* Change Records:
*  >> (18/Fev/2018): Create the function
*----------------------------------------------*/
void LlistInsertAfter(llist_t * list, node_t * curr, node_t * new_node);

/*------------------------------------------------
* FuncName: NodeCreate
* Descriptions: Create a node for linked list.
* Paras:
*  >> void * : a data structure
*  >> eb_t * : error block.
* Return:
*  >> node_t * : a created node
* Change Records:
*  >> (18/Fev/2018): Create the function
*----------------------------------------------*/
node_t * NodeCreate(void * data, eb_t * eb);

#endif /* _FENTORTOS_SRC_LLIST_LLIST_H_ */

