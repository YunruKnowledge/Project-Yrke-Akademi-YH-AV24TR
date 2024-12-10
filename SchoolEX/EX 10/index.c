#include "queue.h"


int main(void)
{
    enqueueValIntoQueue(10);
    enqueueValIntoQueue(20);
    enqueueValIntoQueue(30);
    enqueueValIntoQueue(40);
    enqueueValIntoQueue(50);

    dequeueValFromQueue();
    displayQueueContent();

    enqueueValIntoQueue(60);
    displayQueueContent();

    deleteCurrentQueue();

    return 0;
}