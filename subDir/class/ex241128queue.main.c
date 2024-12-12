#include "ex241128queue.h"
#include <stdbool.h>
#include <stdio.h>

int main(void) {

  (void)printf("\n\n*** Init ***\n");
  isEmpty(true);
  isFull(true);
  printQueue();

  (void)printf("\n\n*** Enqueue ***\n");
  enqueue(25);
  enqueue(33);
  enqueue(77);
  (void)printf("Enqueued x3\n");
  printQueue();
  isEmpty(true);
  isFull(true);

  (void)printf("\n\n*** Full Enqueue ***\n");
  enqueue(99);
  enqueue(165);
  enqueue(128);
  (void)printf("Enqueued x3\n");
  printQueue();
  isEmpty(true);
  isFull(true);

  (void)printf("\n\n*** Dequeue ***\n");
  dequeue();
  dequeue();
  (void)printf("Dequeued x2\n");
  printQueue();

  (void)printf("\n\n*** Dequeue All ***\n");
  dequeue();
  dequeue();
  dequeue();
  dequeue();
  (void)printf("Dequeued x4\n");
  isEmpty(true);
  isFull(true);
  printQueue();

  return 0;
}