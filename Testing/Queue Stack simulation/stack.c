#include "stack.h"
#include <stdlib.h>

#define STACK_START 0;

typedef struct stack
{
    int *items;
    int stackCapacity;
    int topOfStack;
} Stack;

Stack *stack_initializeStack(int maxstackLength)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack *));

    stack->stackCapacity = maxstackLength;
    stack->items = (int *)malloc(stack->stackCapacity * sizeof(int *));

    stack->topOfStack = STACK_START;

    return stack;
}

bool stack_isStackFull(Stack *stack)
{
    return stack->topOfStack >= MAX_STACK_LENGTH;
}

bool stack_isStackEmpty(Stack *stack)
{
    return stack->topOfStack == STACK_START;
}

void stack_deleteCurrentstack(Stack *stack)
{
    stack->topOfStack = STACK_START;

    free(stack);
    free(stack->items);

    stack = NULL;
    stack->items = NULL;
}

bool stack_enStackValIntoStack(Stack *stack, int val)
{
    bool status;

    if (!stack_isStackFull(stack))
    {
        stack->items[stack->topOfStack] = val;
        stack->topOfStack++;
        status = true;
    }
    else
        status = false;

    return status;
}

bool stack_denStackVaFromStack(Stack *stack, int *denStackVal)
{
    bool status;

    if (!stack_isStackEmpty(stack))
    {
        stack->items[stack->topOfStack] = *denStackVal;
        stack->topOfStack--;
        status = true;
    }
    else
        status = false;

    return status;
}