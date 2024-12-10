#include "stack.h"

int main(void)
{
    push(10);
    push(20);

    printStack();
    peek();

    pop();
    peek();

    push(30);
    push(40);
    push(50);

    peek();
    printStack();

    clearStack();
    peek();
    printStack();

    return 0;
}