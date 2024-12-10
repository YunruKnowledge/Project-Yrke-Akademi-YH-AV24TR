#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define MAX_STACK_LENGTH 10

typedef struct stack Stack;

Stack *stack_initializeStack(int maxstackLength);

bool stack_isStackFull(Stack *stack);
bool stack_isStackEmpty(Stack *stack);

void stack_deleteCurrentstack(Stack *stack);

bool stack_enStackValIntoStack(Stack *stack, int val);
bool stack_denStackVaFromStack(Stack *stack, int *denStackVal);

#include "stack.c" // Testing

#endif // !STACK_H