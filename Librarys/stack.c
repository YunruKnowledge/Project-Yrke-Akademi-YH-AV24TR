#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

Stack *stack_create(unsigned capacity)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

bool stack_isFull(Stack *stack)
{
    return (stack->top == (stack->capacity - 1)) ? true : false;
}

bool stack_isEmpty(Stack *stack)
{
    return (stack->top == -1) ? true : false;
}

void stack_push(Stack *stack, uint8_t item)
{
    if (stack_isFull(stack))
    {
        (void)printf("Error occurred! Couldn't push item[%d] because stack is full! \n", item);
        return;
    }
    stack->array[++stack->top] = item;
    (void)printf("Item [%d] is push to stack! \n", item);
}

int stack_pop(Stack *stack)
{
    int returnVal;
    if (stack_isEmpty(stack))
    {
        (void)printf("Error occurred! Couldn't pop because stack is empty! \n");
        returnVal = INT_MIN;
    }
    else
    {
        (void)printf("Item [%d] is successfully popped \n", stack->array[stack->top]);
        returnVal = stack->array[stack->top--];
    }

    return returnVal;
}

int stack_peek(Stack *stack)
{
    int returnVal;
    if (stack == NULL || stack->array == NULL || stack_isEmpty(stack))
    {
        (void)printf("Error occurred! Couldn't peek because stack is empty or deleted! \n");
        returnVal = 0;
    }
    else
        returnVal = stack->array[stack->top];

    return returnVal;
}

void stack_clear(Stack *stack)
{
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
}

int stack_getLength(Stack *stack)
{
    int arrayLength = 0;
    if (stack_isEmpty(stack) || stack == NULL)
        arrayLength = 0;
    else
        for (size_t i = 0; i <= (stack->top); i++)
            arrayLength++;
    return arrayLength;
}

void stack_delete(Stack *stack)
{
    if (stack == NULL)
        return;

    stack->top = -1;
    stack->capacity = 0;

    if (stack->array != NULL)
    {
        free(stack->array);
        stack->array = NULL;
    }

    free(stack);
    stack = NULL;

    (void)printf("Stack is successfully deleted! \n");
}