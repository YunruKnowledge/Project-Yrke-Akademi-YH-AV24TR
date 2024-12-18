#include <cstdlib>
#include <iostream>

using namespace std;

#define MAX_STACK_SIZE 3
#define START_VALUE 0

typedef struct Stack
{
    int top;
    int item;
    int size;
} stack_t;

stack_t *createStack(int size);

void pushToStack(stack_t *stack, int item);
void popFromStack(stack_t *stack);
void displayStackItems(stack_t *stack);

int getStackSize(stack_t *stack);

void clearStack(stack_t *stack);
void destroyStack(stack_t *stack);

bool isEmpty(stack_t *stack);
bool isFull(stack_t *stack);

int main(void)
{
    stack_t *stack = createStack(MAX_STACK_SIZE);

    pushToStack(stack, 10);
    pushToStack(stack, 20);
    pushToStack(stack, 30);

    displayStackItems(stack);

    popFromStack(stack);
    popFromStack(stack);
    displayStackItems(stack);

    cout << "Stack size is: " << getStackSize(stack) << endl;

    displayStackItems(stack);
    clearStack(stack);

    destroyStack(stack);

    return 0;
}

stack_t *createStack(int size)
{
    stack_t *newStack = (stack_t *)malloc(sizeof(stack_t) * size);

    if (newStack == NULL)
        exit(1);

    newStack->top = START_VALUE;
    newStack->size = MAX_STACK_SIZE;

    return newStack;
}

void pushToStack(stack_t *stack, int item)
{
    if (!isFull(stack))
    {
        stack[stack->top].item = item;
        stack->top++;
    }
}

void popFromStack(stack_t *stack)
{
    if (!isEmpty(stack))
    {
        stack->top--;
    }
}

void clearStack(stack_t *stack)
{
    stack->top = START_VALUE;
}

void destroyStack(stack_t *stack)
{
    if (stack != NULL)
    {
        free(stack);
        stack = NULL;
    }
}

int getStackSize(stack_t *stack)
{
    return stack->top;
}

void displayStackItems(stack_t *stack)
{
    if (!isEmpty(stack) && stack != NULL)
    {
        for (int i = 0; i < stack->top; i++)
        {
            cout << "Item number: " << i + 1 << " is: " << stack[i].item << endl;
        }
    }
    else
    {
        cout << "Stack is empty" << endl;
    }
}

bool isEmpty(stack_t *stack)
{
    return stack->top == START_VALUE;
}

bool isFull(stack_t *stack)
{
    return stack->top == stack->size;
}