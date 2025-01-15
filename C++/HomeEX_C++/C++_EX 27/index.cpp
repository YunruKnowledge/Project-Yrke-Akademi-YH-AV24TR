#include <iostream>
#include <assert.h>
#include "queueListTemplate.h"

void testEnqueue(Queue<int> &queue);
void testDequeue(Queue<int> &queue);

int main(void)
{
    Queue<int> q{3};

    std::cout << q << std::endl;

    testEnqueue(q);
    std::cout << "---------------" << std::endl;
    std::cout << "Enqueue test passed!" << std::endl;
    std::cout << q << std::endl;
    std::cout << "---------------" << std::endl;

    testDequeue(q);
    std::cout << "---------------" << std::endl;
    std::cout << "Dequeue test passed!" << std::endl;
    std::cout << q << std::endl;
    std::cout << "---------------" << std::endl;

    std::cout << "Clearing The Queue!" << std::endl;
    q.clear();
    std::cout << "Queue after clear: " << q << std::endl;

    return 0;
}

void testEnqueue(Queue<int> &queue)
{
    assert(queue.enqueue(10));          // Test enqueue
    assert(queue.enqueue(20));          // Test enqueue
    assert(queue.enqueue(30));          // Test enqueue
    assert(queue.enqueue(40) == false); // Test fail enqueue
}

void testDequeue(Queue<int> &queue)
{
    assert(queue.dequeue()); // Test dequeue
    std::cout << "Top Item after dequeue: " << queue.getTopValue() << std::endl;
    assert(queue.dequeue()); // Test dequeue
    std::cout << "Top Item after dequeue: " << queue.getTopValue() << std::endl;
    assert(queue.dequeue());          // Test dequeue
    assert(queue.dequeue() == false); // Test fail dequeue
    std::cout << std::endl;
}