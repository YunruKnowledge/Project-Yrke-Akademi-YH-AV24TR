#include "singleton.h"

int Stack::stackArr[];
int Stack::currentSize{0};

int main(void)
{
    Stack stack;

    stack.push(10);
    stack.push(20);

    stack.peek();

    return 0;
}