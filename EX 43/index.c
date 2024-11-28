#include "stackList.h"

int main(void)
{
    stack_t *newStack = stackList_createStack(STACK_LIST_MAX_LIST_AMOUNT);
    stackList_push(newStack, 10);
    stackList_push(newStack, 20);
    stackList_push(newStack, 30);
    stackList_push(newStack, 40);
    stackList_push(newStack, 50);
    stackList_push(newStack, 60);

    stackList_peek(newStack);
    stackList_clearStack(newStack);

    return 0;
}