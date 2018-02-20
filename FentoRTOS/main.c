#include <stdio.h>
#include <stdlib.h>
#include "src/queue/queue.h"

/*   Teste para queue */
int main()
{
    uint8_t data[10];
    uint32_t cnt = 0;
    uint8_t *val;
    eb_t eb;
    queue_t queue = QueueCreate(&eb);


//    for(cnt = 0; cnt < 10; cnt++)
//        data[cnt] = cnt;

//    for(cnt = 0; cnt < 2; cnt++)
//    {
//        Enqueue(queue,&data[cnt%10],&eb);
//        if(eb.type == EB_TYPE_ERROR)
//            printf("ERROR!\n");
//    }
    Enqueue(queue,&data[2],&eb);
//    printf("head: %d, tail: %d\n",queue->head, queue->tail);
    Enqueue(queue,&data[6],&eb);
//   printf("head: %d, tail: %d\n",queue->head, queue->tail);
//    Enqueue(queue,&data[8],&eb);
//    printf("head: %d, tail: %d\n",queue->head, queue->tail);
//    printf("DEQUEUE: %d -- ",*(uint8_t *)Dequeue(queue,&eb));
//    printf("head: %d, tail: %d\n",queue->head, queue->tail);
    //printf("DEQUEUE: %d -- ",*(uint8_t *)Dequeue(queue,&eb));
    //printf("head: %d, tail: %d\n",queue->head, queue->tail);


    for(cnt = 0; cnt < 100000; cnt++)
    {
        Enqueue(queue,data,&eb);
        //printf("Enqueue--> head: %d, tail: %d\n",queue->head, queue->tail);
        Dequeue(queue,&eb);
        //printf("Dequeue--> head: %d, tail: %d\n",queue->head, queue->tail);
        //if(eb.type == EB_TYPE_ERROR)
        //    printf("ERROR!\n");
    }
//    for(cnt = 0; cnt < 20; cnt++)
//    {
//        Enqueue(queue,&data[6],&eb);
//        //printf("Enqueue--> head: %d, tail: %d\n",queue->head, queue->tail);
//    }

    return 0;
}
