#include "stack.h"

void push(int item)
{
    if (!isFull())
    {
        stack[amount] = item;
        amount++;
    }
    else
        (void)printf("Stack is already full! \n");
}

void pop(void)
{
    if (!isEmpty())
        amount--;
    else
        (void)printf("Stack is empty! \n");
}

void peek(void)
{
    if (!isEmpty())
        (void)printf("Peeked item is: %d \n", stack[amount - 1]);
    else
        (void)printf("Stack is empty! \n");
}

void printStack(void)
{
    if (!isEmpty())
    {
        for (size_t i = 0; i < amount; i++)
        {
            (void)printf("Item[%zu] is: %d\n", i, stack[i]);
        }
    }
    else
        (void)printf("Stack is empty! \n");
}

void clearStack(void)
{
    amount = 0;
}

bool isFull(void)
{
    return amount >= MAX_STACK_SIZE;
}

bool isEmpty(void)
{
    return amount == 0;
}