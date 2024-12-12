#include "exec_41_queue.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/**
 * @brief Copied from example, and edited.
 */
int main(void)
{
    queue_t *q1 = queueCreate();
    assert(q1 != NULL);
    assert(0 == queueCount(q1));

    queue_t *q2 = queueCreate();
    assert(q2 != NULL);
    assert(0 == queueCount(q2));
    (void)printf("Testing create... Passed!\n");

    assert(queueAdd(q1, 10));
    assert(1 == queueCount(q1));
    assert(queueAdd(q1, 20));
    assert(queueAdd(q1, 30));
    assert(3 == queueCount(q1));

    assert(queueAdd(q2, 100));
    assert(1 == queueCount(q2));
    assert(queueAdd(q2, 200));
    assert(queueAdd(q2, 300));
    assert(3 == queueCount(q2));
    (void)printf("Testing enqueue... Passed!\n");

    int value;
    assert(queueRead(q1, &value));
    assert(2 == queueCount(q1));
    assert(10 == value);

    assert(queueRead(q1, &value));
    assert(1 == queueCount(q1));
    assert(20 == value);

    assert(queueRead(q2, &value));
    assert(2 == queueCount(q2));
    assert(100 == value);

    assert(queueRead(q2, &value));
    assert(1 == queueCount(q2));
    assert(200 == value);
    (void)printf("Testing dequeue... Passed!\n");

    queueFree(&q1);
    assert(q1 == NULL);

    queueFree(&q2);
    assert(q2 == NULL);

    (void)printf("Testing destroy... Passed!\n");

    (void)printf("----------------------------\n");
    (void)printf("All the tests passed!\n");

    return 0;
}