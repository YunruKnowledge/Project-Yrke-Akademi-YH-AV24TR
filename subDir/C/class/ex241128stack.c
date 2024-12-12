

#include "ex241128stack.h"
#include <stdio.h>
#define STACK_BUFFER 5
#define COUNT_IN_ARRAY (COUNT - 1)

static int STACK[STACK_BUFFER] = {0};
static size_t COUNT = 0;

void push(int element) {
  if (COUNT < STACK_BUFFER) {
    STACK[COUNT] = element;
    COUNT++;
  }
}

void pop(void) {
  if (COUNT) {
    STACK[COUNT_IN_ARRAY] = 0;
    COUNT--;
  }
}

void printStack(void) {
  (void)printf("Stack:");
  if (COUNT) {
    for (size_t i = 0; i < COUNT; i++) {
      (void)printf(" %i ->", STACK[i]);
    }
    (void)printf(" END\n");
  } else {
    (void)printf(" EMPTY\n");
  }
};

void isEmpty(void) {
  if (!COUNT)
    (void)printf("It is empty.\n");
  else
    (void)printf("Is not empty.\n");
}

void isFull(void) {
  if (COUNT >= STACK_BUFFER)
    (void)printf("It is full.\n");
  else
    (void)printf("Is not full.\n");
}
