#ifndef STACK_LIST_H
#define STACK_LIST_H

#include <stdbool.h>

#define STACK_LIST_MAX_LIST_AMOUNT 5

typedef struct Node
{
    int data;
    struct Node *next;
} node_t;

typedef struct Stack
{
    node_t *head;
} stack_t;

stack_t *stackList_createStack(int maxAmountOfNodes);

bool stackList_isEmpty(stack_t *stack);
bool stackList_isFull(stack_t *stack);

bool stackList_push(stack_t *stack, int newData);
bool stackList_pop(stack_t *stack);
bool stackList_peek(stack_t *stack);
bool stackList_getNumberOfData(stack_t *stack);

bool stackList_clearStack(stack_t *stack);

#include "stackList.c" // To remove when done testing

#endif // !STACK_LIST_H