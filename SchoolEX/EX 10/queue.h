#ifndef QUEUE_H
#define QUEUE_H

#define MAX_ARRAY_LENGTH 5
#define COUNT_START 0;

#include <stdbool.h>

static int queue[MAX_ARRAY_LENGTH];
static int count = COUNT_START;

void enqueueValIntoQueue(int val);
void dequeueValFromQueue(void);

void deleteCurrentQueue(void);
void displayQueueContent(void);

bool isFull(void);
bool isEmpty(void);

#include "queue.c"

#endif // !QUEUE_H