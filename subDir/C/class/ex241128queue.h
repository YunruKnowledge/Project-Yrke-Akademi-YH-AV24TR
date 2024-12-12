
#ifndef MODULE_EX241128
#define MODULE_EX241128

#define QUEUE_BUFFER 5
#define NEXT 1

#include <stdbool.h>
#include <stdio.h>

void enqueue(int _element);
void dequeue(void);
void printQueue(void);
bool isEmpty(const bool _verbose);
bool isFull(const bool _verbose);

#endif