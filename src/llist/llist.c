/*
* FileName: llist.c
* Author: Dong Xia
* This is source file of linked list.
* The linked list here is a double linked 
* list.
*
* Change Records:
*      >> (18/Fev/2018): 
*
*/

/********************************************
* Include 
********************************************/
#include "llist.h"
#include "../src/Error/error.h"
#include "../src/type.h"

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
llist_t * LlistCreate(eb_t *eb)
{
    llist_t * list = (llist_t *)malloc(sizeof(llist_t));
    if(list == NULL) {
        eb->type = EB_TYPE_ERROR;
        eb->code = MEMORY_ALLOC_ERR;
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    eb->type = EB_TYPE_NOERROR;
    return list;
}

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
void * LlistDel(llist_t * llist, node_t * curr)
{
    node_t *next, *prev;
    next = curr->next;
    prev = curr->prev;

    if(next == NULL)
        //curr is a tail node
        llist->tail = prev;
    else
        next->prev = prev;

    if(prev == NULL)
        //curr is a head node
        llist->head = next;
    else
        prev->next = next;

}

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
void LlistInsertBefore(llist_t * list, node_t * curr, node_t * new_node)
{
    node_t * prev = curr->prev;

    new_node->prev = prev;
    new_node->next = curr;
    curr->prev = new_node;
    
    //if new node is added to head
    if(prev == NULL)
        list->head = new_node;
    else 
        prev->next = new_node;
}


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
void LlistInsertAfter(llist_t * list, node_t * curr, node_t * new_node)
{
    node_t *next;
    
    next = curr->next;

    curr->next = new_node;
    new_node->next = next;
    if(next == NULL)
        list->tail = new_node;
    else
        next->prev = new_node;
    new_node->prev = curr;
}



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
node_t * NodeCreate(void * data, eb_t * eb)
{
    node_t * node = (node_t *)malloc(sizeof(node_t));

    if(node == NULL){
        eb->type = EB_TYPE_ERROR;
        eb->code = MEMORY_ALLOC_ERR;
        return NULL;
    }
    node->data = data;
    eb->type = EB_TYPE_NOERROR;
    return node;
}

