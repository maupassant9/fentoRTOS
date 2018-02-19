#include <stdio.h>
#include <stdlib.h>
#include "src/llist/llist.h"
/*   Teste para Linked list */
int main()
{
    llist_t *list;
    eb_t eb;
    node_t *curr;
    char cnt = 0, num[200];

    list = LlistCreate(&eb);
    curr = list->head;
    for(cnt = 0; cnt < 100; cnt++){
        num[cnt] = cnt;
        LlistInsertAfter(list, curr, NodeCreate(&num[cnt],&eb));
        curr = list->tail;
    }
    num[100] = 100;
    curr = list->head;
    LlistInsertBefore(list, curr, NodeCreate(&num[100],&eb));
    for(cnt = 0; cnt < 3; cnt++)
    {
        curr = curr->next;
    }
    printf("curr value = %d", *(char*)curr->data);
    LlistDel(list,curr);

    for(curr = list->head; curr != NULL; curr = curr->next)
    {
        printf("-- %d --", *(char*)curr->data);
    }
    printf("\n");
    for(curr = list->tail;curr !=NULL; curr = curr->prev)
    {
        printf("-- %d --", *(char*)curr->data);
    }
    return 0;
}
