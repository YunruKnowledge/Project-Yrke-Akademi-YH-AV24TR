#include "stackList.h"

int Stack::amount{0};

bool Stack::push(int item)
{
    bool status{false};

    Node *node{new (std::nothrow) Node{item, top}};

    if (node != nullptr)
    {
        top = node;
        amount++;
        status = true;
    }

    return status;
}

bool Stack::pop()
{
    bool status{false};

    if (top != nullptr)
    {
        Node *temp{top};

        std::cout << "Popped item is: " << top->item << std::endl;
        top = top->next;

        delete temp;
        amount--;

        status = true;
    }

    return status;
}

bool Stack::peek() const
{
    bool status{false};

    if (top != nullptr)
    {
        std::cout << "Peeked item is: " << top->item << std::endl;
        status = true;
    }

    return status;
}

void Stack::clear()
{
    Node *current;

    while (top != nullptr)
    {
        current = top;
        top = top->next;
        delete current;
    }

    amount = 0;
}
