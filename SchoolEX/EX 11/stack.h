#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 5

static int stack[MAX_STACK_SIZE];
static int amount = 0;

void push(int item);
void pop(void);
void peek(void);
void clearStack(void);
void printStack(void);

bool isFull(void);
bool isEmpty(void);

#include "stack.c" // Just for easier testing

#endif // !STACK_H