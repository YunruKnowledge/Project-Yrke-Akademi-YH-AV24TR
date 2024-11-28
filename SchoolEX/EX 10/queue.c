#include <stdio.h>
#include "queue.h"

void enqueueValIntoQueue(int val)
{
    if (isFull())
        (void)printf("Queue is full! \n");
    else
    {
        queue[count] = val;
        count++;
    }
}

void dequeueValFromQueue(void)
{
    if (isEmpty())
        (void)printf("Queue is empty! \n");
    else
    {
        for (size_t i = 0; i < count; i++)
        {
            int temp = queue[i];
            queue[i - 1] = temp;
        }
        count--;
    }
}

void displayQueueContent()
{
    for (size_t i = 0; i < (count); i++)
        (void)printf("Queue[%zu]: %d \n", i, queue[i]);
    (void)printf("\n");
}

void deleteCurrentQueue(void)
{
    count = COUNT_START;
}

bool isFull(void)
{
    return count >= MAX_ARRAY_LENGTH;
}

bool isEmpty(void)
{
    return count == 0;
}
