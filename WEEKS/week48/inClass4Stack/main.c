#include <stdio.h>
#include <stdbool.h>

#define MAX 5

int array[MAX];
int top = 0, bottom = 0;

void push(int element)
{
    int limit = 0;
    if (limit <= MAX)
    {
        array[top] = element;
        top++;

        limit++;
    }
}
void pop()
{
    array[top] = 0;
    top--;
}
void printStack()
{

    for (int i = 0; i < top; i++)
    {
        printf("-%i-", array[i]);
    }
    printf("\n");
}

bool isEmpty()
{
    bool status = false; // NOT empty
    // if (!top) if its 0(false)
    if (top == 0)
    {
        status = true; // empty
    }

    return status;
}

bool isFull()
{
    bool status = false;

    if (!top == 0) // if it return 0
    {
        status = true; // NOT full
    }

    return status;
}

int main(void)
{
    (void)printf("\n\n*** Init check ***\n");
    isEmpty();
    isFull();

    (void)printf("\n\n*** Push ***\n");
    push(8);
    push(0);
    push(-5);
    push(0);
    printStack();

    (void)printf("\n\n*** Pop ***\n");
    pop();
    printStack();
    pop();
    printStack();
    isEmpty();

    (void)printf("\n\n*** Push ***\n");
    push(2);
    push('a');
    push(4);
    printStack();
    isFull();

    (void)printf("\n\n*** Push over max ***\n");
    push(111);
    printStack();
    isFull();

    (void)printf("\n\n*** POP ALL ***\n");
    pop();
    pop();
    pop();
    pop();
    pop();
    printStack();
    isEmpty();
    isFull();
    return 0;
}