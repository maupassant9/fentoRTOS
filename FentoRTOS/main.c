#include <stdio.h>
#include <stdlib.h>
#include "src/queue/queue.h"
#include "src/mem/mem1.h"

/*   Teste para queue */
int main()
{
    int cnt;
    struct data_t{
        uint8_t data[340];
    } data, *ptr;


    MemInit();
    ptr = (struct data_t *)my_malloc(sizeof(data));
    for(cnt = 0; cnt < 340; cnt++)
    {
        ptr->data[cnt] = cnt;
    }
    return 0;
}
