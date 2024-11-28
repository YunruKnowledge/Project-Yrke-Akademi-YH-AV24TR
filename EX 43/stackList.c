#include "stackList.h"
#include <stdio.h>
#include <stdlib.h>

void stackList_initializeStack(stack_t *stack);

static size_t available = 0;
static size_t _maxAmountOfNodes = 0;

static node_t *head = NULL;

node_t *stackList_createNode(int newData)
{
    node_t *newNode = (node_t *)malloc(sizeof(node_t));

    newNode->data = newData;
    newNode->next = NULL;

    available++;

    return newNode;
}

stack_t *stackList_createStack(int maxAmountOfNodes)
{
    stack_t *newNode = (stack_t *)malloc(sizeof(stack_t));
    stackList_initializeStack(newNode);

    _maxAmountOfNodes = maxAmountOfNodes;

    return newNode;
}

void stackList_initializeStack(stack_t *stack)
{
    stack->head = NULL;
}

bool stackList_isEmpty(stack_t *stack)
{
    return ((stack->head == NULL) && (available == 0));
}

bool stackList_isFull(stack_t *stack)
{
    return ((available <= _maxAmountOfNodes));
}

bool stackList_push(stack_t *stack, int newData)
{
    bool returnVal;
    node_t *newNode = stackList_createNode(newData);

    if (!newNode)
    {
        (void)printf("Failed to alloced memory! \n");
        free(newNode);
        returnVal = false;
    }
    else if (!stackList_isFull(stack))
    {
        (void)printf("Failed to push [%d]! Stack is already full \n", newData);
        free(newNode);
        returnVal = false;
    }
    else
    {
        newNode->next = stack->head;
        stack->head = newNode;

        returnVal = true;
    }

    return returnVal;
}

bool stackList_pop(stack_t *stack)
{
    bool returnVal;

    if (stackList_isEmpty(stack))
    {
        (void)printf("Failed to pop value! Stack is already empty! \n");
        returnVal = false;
    }
    else if (stack == NULL)
    {
        (void)printf("Failed to pop value! Stack doesent exist! \n");
        returnVal = false;
    }
    else
    {
        node_t *temp = stack->head;
        stack->head = stack->head->next;

        free(temp);
        temp = NULL;

        returnVal = true;
    }

    return returnVal;
}

bool stackList_peek(stack_t *stack)
{
    bool returnVal;
    if (stackList_isEmpty(stack))
    {
        (void)printf("Stack is empty! \n");
        returnVal = true;
    }
    else if (stack == NULL)
    {
        (void)printf("Failed to pop value! Stack doesent exist! \n");
        returnVal = false;
    }
    else
    {
        (void)printf("Peeked value is [%d] \n", stack->head->data);
        returnVal = true;
    }

    return returnVal;
}

bool stackList_getNumberOfData(stack_t *stack)
{
    bool returnVal;
    int tempNumberOfData = 0;

    node_t *cursor;

    if (stack == NULL)
    {
        (void)printf("Failed to load stack! Stack doesent exist! \n");
        returnVal = false;
    }
    else
    {
        cursor = stack->head;
        while ((cursor != NULL))
        {
            cursor = cursor->next;
            tempNumberOfData++;
        }

        (void)printf("Number of data in stack is: [%d]! \n", tempNumberOfData);
        returnVal = true;
    }

    return returnVal;
}

bool stackList_clearStack(stack_t *stack)
{
    bool returnVal;

    if (stack != NULL)
    {
        node_t *cursor = stack->head;

        while (stack->head)
        {
            cursor = stack->head->next;
            free(stack->head);
            stack->head = cursor;
        }
        free(stack);
        returnVal = true;
    }
    else
    {
        (void)printf("Failed to clear stack! Stack doesent exist! \n");
        returnVal = false;
    }

    return returnVal;
}