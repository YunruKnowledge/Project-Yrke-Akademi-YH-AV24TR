#include <stdio.h>
#include "queue.h"

#define MAX 8

int main()
{

    // for (int i = 0; i < MAX; i++)
    // {
    //     // *(arrP + i) = i;
    //     arr[i] = i;
    // }

    enqueue(8);
    enqueue(7);
    enqueue(2);
    enqueue(2225);

    printQueue();

    // int *arr  = enqueue;

    // for (int j = 0; j < MAX; j++)
    // {
    //     printf("%i\n", arr[j]);
    //     // printf("%i\n", *(arrP + j));
    // }

    return 0;
}