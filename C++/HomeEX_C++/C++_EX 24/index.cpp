#include <iostream>
#include <cassert>
#include "stackList.h"

bool testPush(Stack &stack); 
bool testPop(Stack &stack);  

int main(void)
{
    Stack stack; 

    if (testPush(stack))
    {
        std::cout << "Push Test Complete!" << std::endl;
        std::cout << stack << std::endl;
    }

    if (testPop(stack))
    {
        std::cout << "Pop Test Complete!" << std::endl;
        std::cout << stack << std::endl;
    }

    std::cout << "Stack size after testing: " << stack.getAmountOfItems() << std::endl;
    stack.peek();

    return 0;
}

bool testPush(Stack &stack)
{
    bool status{false};

    // Test push method with assertions
    assert(stack.push(10));
    assert(stack.push(20));
    assert(stack.push(30));

    status = true;

    return status;
}

bool testPop(Stack &stack)
{
    bool status{false};

    // Test pop method with assertions
    assert(stack.pop());
    assert(stack.pop());

    status = true;

    return status;
}
