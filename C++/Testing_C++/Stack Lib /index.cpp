#include "stack.h"

using namespace std;

int main(void)
{
    stack_t *newStack = Stack::create(5);

    Stack::insert(newStack, 10);
    Stack::insert(newStack, 20);
    Stack::insert(newStack, 30);

    Stack::insert(newStack, 40);
    Stack::pop(newStack);

    Stack::insert(newStack, 40);
    Stack::insert(newStack, 50);

    Stack::printStack(newStack);

    Stack::destroyStack(newStack);

    return 0;
}