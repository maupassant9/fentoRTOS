#include <stdio.h>
#include <stdlib.h>
#include "src/queue/queue.h"

/*   Teste para Linked list */
int main()
{
    uint8_t data[10], cnt;
    uint8_t *val;
    eb_t eb;
    queue_t queue = QueueCreate(&eb);


    for(cnt = 0; cnt < 10; cnt++)
        data[cnt] = cnt;

    for(cnt = 0; cnt < 12; cnt++)
    {
        Enqueue(queue,&data[cnt%10],&eb);
        if(eb.type == EB_TYPE_ERROR)
            printf("ERROR!\n");
    }
    Enqueue(queue,&data[2],&eb);
    printf("head: %d, tail: %d\n",queue->head, queue->tail);
    Enqueue(queue,&data[6],&eb);
    printf("head: %d, tail: %d\n",queue->head, queue->tail);
    Enqueue(queue,&data[8],&eb);
    printf("head: %d, tail: %d\n",queue->head, queue->tail);
    printf("DEQUEUE: %d -- ",*(uint8_t *)Dequeue(queue,&eb));
    printf("head: %d, tail: %d\n",queue->head, queue->tail);
    printf("DEQUEUE: %d -- ",*(uint8_t *)Dequeue(queue,&eb));
    printf("head: %d, tail: %d\n",queue->head, queue->tail);
    for(cnt = 0; cnt < 100; cnt++)
    {
        val = (uint8_t *)Dequeue(queue,&eb);
        if(val != NULL) printf("DEQUEUE: %d -- ",*val);
        else printf("DEQUEUE: -- ");
        printf("head: %d, tail: %d\n",queue->head, queue->tail);
        if(eb.type == EB_TYPE_ERROR)
            printf("ERROR!\n");
    }
    return 0;
}
