#include <iostream>
#include <ostream>
#include "stackArray.h"

int main(void)
{
    try
    {
        Stack<int> stack{5};

        stack.push(10);
        stack.push(20);

        stack.pop();
        stack.push(20);

        std::cout << stack;
    }
    catch (std::string error)
    {
        std::cerr << error << '\n';
    }

    return 0;
}