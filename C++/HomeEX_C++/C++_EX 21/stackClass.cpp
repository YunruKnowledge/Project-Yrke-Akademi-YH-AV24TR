#include "stackClass.h"
#include <iostream>

bool Stack::push(int item)
{
    bool status{true};
    if (!isFull())
    {
        stackArr[currentSize] = item;
        currentSize++;
    }
    else
    {
        std::cout << "Stack is full!" << std::endl;
        status = false;
    }
    return status;
}

bool Stack::pop()
{
    bool status{true};

    if (!isEmpty())
    {
        currentSize--;
    }
    else
    {
        std::cout << "Stack is empty!" << std::endl;
        status = false;
    }

    return status;
}

void Stack::peek()
{
    if (!isEmpty())
    {
        std::cout << "Peeked value is: " << stackArr[currentSize - 1] << std::endl;
    }
    else
    {
        std::cout << "Stack is empty" << std::endl;
    }
}
