#include "queueList.h"

bool Queue::enqueue(int item)
{
    Node *newNode = new Node(item);
    bool status{true};

    if (!this->isFull())
    {
        if (this->isEmpty())
        {
            top = bottom = newNode;
        }
        else
        {
            bottom->next = newNode;
            bottom = newNode;
        }

        currentAmount++;
    }
    else
    {
        status = false;
    }

    return status;
}

bool Queue::dequeue(void)
{
    bool status{true};

    if (!this->isEmpty())
    {
        Node *temp = top;
        top = top->next;

        if (top == nullptr)
            bottom = nullptr;

        currentAmount--;
        delete temp;
    }
    else
    {
        status = false;
    }

    return status;
}