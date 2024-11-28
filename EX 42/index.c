#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_ARRAY_LENGTH 5

struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};

struct Stack *createStack(unsigned capacity);

void push(struct Stack *stack, uint8_t item);
void clearStack(struct Stack *stack);
void deleteStack(struct Stack *stack);

int pop(struct Stack *stack);
int peek(struct Stack *stack);
int getStackLength(struct Stack *stack);

bool isEmpty(struct Stack *stack);
bool isFull(struct Stack *stack);

int main(void)
{
    struct Stack *stack = createStack(MAX_ARRAY_LENGTH);

    push(stack, 10);
    push(stack, 5);
    push(stack, 13);
    push(stack, 20);
    pop(stack);

    (void)printf("Length of an stack array is [%d] \n", getStackLength(stack));

    clearStack(stack);

    (void)printf("Length of an stack array is [%d] \n", getStackLength(stack));

    deleteStack(stack);
    return 0;
}

struct Stack *createStack(unsigned capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

bool isFull(struct Stack *stack)
{
    return (stack->top == (stack->capacity - 1)) ? true : false;
}

bool isEmpty(struct Stack *stack)
{
    return (stack->top == -1) ? true : false;
}

void push(struct Stack *stack, uint8_t item)
{
    if (isFull(stack))
    {
        (void)printf("Error occurred! Couldn't push item[%d] because stack is full! \n", item);
        return;
    }
    stack->array[++stack->top] = item;
    (void)printf("Item [%d] is push to stack! \n", item);
}

int pop(struct Stack *stack)
{
    int returnVal;
    if (isEmpty(stack))
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

int peek(struct Stack *stack)
{
    int returnVal;
    if (stack == NULL || stack->array == NULL || isEmpty(stack))
    {
        (void)printf("Error occurred! Couldn't peek because stack is empty or deleted! \n");
        returnVal = 0;
    }
    else
        returnVal = stack->array[stack->top];

    return returnVal;
}

void clearStack(struct Stack *stack)
{
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
}

int getStackLength(struct Stack *stack)
{
    int arrayLength = 0;
    if (isEmpty(stack) || stack == NULL)
        arrayLength = 0;
    else
        for (size_t i = 0; i <= (stack->top); i++)
            arrayLength++;
    return arrayLength;
}

void deleteStack(struct Stack *stack)
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