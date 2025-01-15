#include <iostream>
#include "queueList.h"

int main(void)
{
    Queue queue{5};

    queue.enqueue(5);
    queue.enqueue(10);
    queue.enqueue(15);
    queue.enqueue(20);
    queue.enqueue(25);

    queue.dequeue();
    queue.enqueue(30);

    std::cout << "Top val in queue is: " << queue.getTopItem() << std::endl;
    std::cout << "Bottom val in queue is: " << queue.getBottomItem() << std::endl;
    std::cout << "Current number of items in a queue is: " << queue.getNumberOfItems() << std::endl;

    std::cout << queue << std::endl;

    queue.clear();

    queue.enqueue(40);
    queue.enqueue(50);

    std::cout << "Top val in queue is: " << queue.getTopItem() << std::endl;
    std::cout << "Bottom val in queue is: " << queue.getBottomItem() << std::endl;
    std::cout << "Current number of items in a queue is: " << queue.getNumberOfItems() << std::endl;

    return 0;
}