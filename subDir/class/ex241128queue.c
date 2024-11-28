
#include "ex241128queue.h"

static int QUEUE[QUEUE_BUFFER] = {0};
static size_t COUNT = 0;

void enqueue(int _element) {
  if (!isFull(false)) {
    QUEUE[COUNT] = _element;
    COUNT++;
  } else {
    (void)printf("Queue is full. Value [%i] dropped.\n", _element);
  }
}

void dequeue(void) {
  if (!isEmpty(false)) {
    for (size_t i = 0; i < COUNT; i++) {
      QUEUE[i] = QUEUE[i + NEXT];
    }
    COUNT--;
  } else {
    (void)printf("Dequeued empty queue. Ignored.\n");
  }
}

void printQueue(void) {
  (void)printf("Queue:");
  if (!isEmpty(false)) {
    for (size_t i = 0; i < COUNT; i++) {
      (void)printf(" %i ->", QUEUE[i]);
    }
    (void)printf(" END\n");
  } else {
    (void)printf(" EMPTY\n");
  }
}

bool isEmpty(const bool _verbose) {
  if (_verbose) {
    if (!COUNT) {
      (void)printf("It is empty.\n");
    } else {
      (void)printf("Not empty.\n");
    }
  }
  return (!COUNT);
}

bool isFull(const bool _verbose) {
  if (_verbose) {
    if (COUNT >= QUEUE_BUFFER) {
      (void)printf("It is full.\n");
    } else {
      (void)printf("Not full. %lu slots remaining.\n", (QUEUE_BUFFER - COUNT));
    }
  }
  return (COUNT >= QUEUE_BUFFER);
}