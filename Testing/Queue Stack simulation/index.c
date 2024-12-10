#include "queue.h"
#include "stack.h"
#include "../../Librarys/GRN.h"
#include <stdbool.h>

void pushToStack(Queue *newQueue, Stack *newStack);

int main(void)
{
    Queue *newQueue = queue_initializeQueue(MAX_QUEUE_LENGTH);
    Stack *newStack = stack_initializeStack(MAX_STACK_LENGTH);

    queue_enqueueValIntoQueue(newQueue, getRandomNumber(0, 99));

    if (!queue_isQueueEmpty(newQueue))
        pushToStack(newQueue, newStack);

    return 0;
}

void pushToStack(Queue *newQueue, Stack *newStack)
{
    int *denqueueVal;

    queue_denqueueVaFromQueue(newQueue, denqueueVal);
    stack_enStackValIntoStack(newStack, *denqueueVal);
    
    queue_printQueue(newQueue);

    if (!queue_isQueueEmpty(newQueue))
        pushToStack(newQueue, newStack);
}