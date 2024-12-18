#include "stack.h"
#include <cstdlib>

#define STACK_START 0

struct stack_t
{
    int size;
    int top;
    int *item;
};

stack_t *Stack::create(int size)
{
    return new (std::nothrow) stack_t{size, 0, new (std::nothrow) int(size)};
}

bool Stack::isFull(stack_t *stack)
{
    return stack->size == stack->top;
}

bool Stack::isEmpty(stack_t *stack)
{
    return stack->top == STACK_START;
}

bool Stack::insert(stack_t *stack, int value)
{
    bool status{false};

    if (stack != nullptr)
    {
        if (!isFull(stack))
        {
            stack->item[stack->top] = value;
            stack->top++;
            status = true;
        }
    }

    return status;
}

bool Stack::pop(stack_t *stack)
{
    bool status{false};

    if (stack != nullptr)
    {
        if (!isEmpty(stack))
        {
            stack->top--;
            status = true;
        }
    }

    return status;
}

int Stack::getSize(stack_t *stack)
{
    int size{0};

    if (stack != nullptr)
    {
        size = stack->top;
    }

    return size;
}

void Stack::clearStack(stack_t *stack)
{
    if (stack != nullptr)
    {
        stack->top = STACK_START;
    }
}

void Stack::destroyStack(stack_t *&stack)
{
    if (stack != nullptr)
    {
        delete stack;
        stack = nullptr;
    }
}

void Stack::printStack(stack_t *stack)
{
    if (stack != nullptr)
    {
        if (!isEmpty(stack))
        {
            for (size_t i = STACK_START; i < stack->top; i++)
            {
                std::cout << "Item [" << i << "] is: " << stack->item[i] << std::endl;
            }
        }
        else
        {
            std::cout << "Stack is empty" << std::endl;
        }
    }
    else
    {
        std::cout << "Stack is null" << std::endl;
    }
}

void Stack::peek(stack_t *stack)
{
    if (stack != nullptr)
    {
        if (!isEmpty(stack))
        {
            std::cout << "Peeked value is: " << stack->item[stack->top] << std::endl;
        }
        else
        {
            std::cout << "Stack is empty" << std::endl;
        }
    }
    else
    {
        std::cout << "Stack is null" << std::endl;
    }
}