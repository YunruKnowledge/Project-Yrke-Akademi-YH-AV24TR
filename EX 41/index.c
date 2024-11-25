#include <stdio.h>

#define MAX_ARRAY_LENGTH 10 

typedef struct
{
    int arr[MAX_ARRAY_LENGTH];
    int front;
    int back;
} queue;


void enqueueValIntoQueue(queue *queue, int val);
void dequeueValFromQueue(queue *queue);

void initializeQueue(queue *queue);
void deleteCurrentQueue(queue *queue);
void displayQueueContent(queue *queue);

int main(void)
{
    queue newQueue;
    initializeQueue(&newQueue);

    dequeueValFromQueue(&newQueue);

    enqueueValIntoQueue(&newQueue, 10);
    enqueueValIntoQueue(&newQueue, 5);
    enqueueValIntoQueue(&newQueue, 7);
    displayQueueContent(&newQueue);

    dequeueValFromQueue(&newQueue);
    displayQueueContent(&newQueue);

    deleteCurrentQueue(&newQueue);
    displayQueueContent(&newQueue);

    return 0;
}

void enqueueValIntoQueue(queue *queue, int val)
{
    if (queue->back < MAX_ARRAY_LENGTH)
    {
        queue->arr[queue->back] = val;
        queue->back++;
    }
    else
        (void)printf("Current queue is full!\n");
}

void dequeueValFromQueue(queue *queue)
{
    if (queue->front == queue->back - 1)
    {
        (void)printf("Current queue is empty!\n");
        return;
    }
    queue->front++;
}

void deleteCurrentQueue(queue *queue)
{
    while (queue->back != 0)
    {
        queue->arr[queue->back] = 0;
        queue->back--;
    }
    queue->front = 0;
    (void)printf("Queue is deleted!\n");
}

void displayQueueContent(queue *queue)
{
    (void)printf("Queue contents: ");
    for (size_t i = queue->front + 1; i < queue->back; i++)
    {
        (void)printf("%d ", queue->arr[i]);
    }
    (void)printf("\n");
}

void initializeQueue(queue *queue)
{
    queue->front = -1;
    queue->back = 0;
}