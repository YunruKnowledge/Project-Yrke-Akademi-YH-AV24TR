#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

#define FRONT_OF_QUEUE 0
#define BACK_OF_QUEUE 0

typedef struct queue
{
    int *queuedItems;
    int queueCapacity;
    int frontOfQueue;
    int backOfQueue;
} Queue;

Queue *queue_initializeQueue(int maxQueueLength)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue *));

    queue->queueCapacity = maxQueueLength;
    queue->queuedItems = (int *)malloc(queue->queueCapacity * sizeof(int *));

    queue->frontOfQueue = FRONT_OF_QUEUE;
    queue->backOfQueue = BACK_OF_QUEUE;

    return queue;
}

bool queue_enqueueValIntoQueue(Queue *queue, int val)
{
    bool status;
    
    if (!queue_isQueueFull(queue))
    {
        queue->queuedItems[queue->backOfQueue] = val;
        queue->backOfQueue++;
        status = true;
    }
    else
        status = false;

    return status;
}

bool queue_denqueueVaFromQueue(Queue *queue, int *denqueueVal)
{
    bool status;
    
    if (!queue_isQueueEmpty(queue))
    {
        denqueueVal = &queue->queuedItems[queue->frontOfQueue];
        queue->frontOfQueue++;
        status = true;
    }
    else
        status = false;

    return status;
}

void queue_deleteCurrentQueue(Queue *queue)
{
    while (queue->backOfQueue != BACK_OF_QUEUE)
    {
        queue->backOfQueue--;
    }
    queue->frontOfQueue = FRONT_OF_QUEUE;

    free(queue);
    free(queue->queuedItems);

    queue = NULL;
    queue->queuedItems = NULL;
}

void queue_printQueue(Queue *queue)
{
    if (!queue_isQueueEmpty(queue))
    {
        for (int i = queue->frontOfQueue; i < queue->backOfQueue; i++)
        {
            (void)printf("%d -> ", queue->queuedItems[i]);
        }
        (void)printf("NULL \n");
    }
    else
        (void)printf("Queue is empty \n");
}

bool queue_isQueueFull(Queue *queue)
{
    return queue->backOfQueue == queue->queueCapacity;
}

bool queue_isQueueEmpty(Queue *queue)
{
    return queue->backOfQueue == queue->frontOfQueue;
}