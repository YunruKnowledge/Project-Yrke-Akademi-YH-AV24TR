#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#define MAX_QUEUE_LENGTH 30

typedef struct queue Queue;

Queue *queue_initializeQueue(int maxQueueLength);

bool queue_isQueueFull(Queue *queue);
bool queue_isQueueEmpty(Queue *queue);

void queue_deleteCurrentQueue(Queue *queue);
void queue_printQueue(Queue *queue);

bool queue_enqueueValIntoQueue(Queue *queue, int val);
bool queue_denqueueVaFromQueue(Queue *queue, int *denqueueVal);

#include "queue.c" // Just for quick dest -- Delete Later -- 

#endif // !QUEUE_H