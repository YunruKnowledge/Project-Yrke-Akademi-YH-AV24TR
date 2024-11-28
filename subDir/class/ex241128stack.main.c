
#include "ex241128stack.h"
#include <stdio.h>

int main(void) {

  (void)printf("\n\n*** Init check ***\n");
  isEmpty();
  isFull();

  (void)printf("\n\n*** Push ***\n");
  push(8);
  push(0);
  push(-5);
  push(0);
  printStack();

  (void)printf("\n\n*** Pop ***\n");
  pop();
  printStack();
  pop();
  printStack();
  isEmpty();

  (void)printf("\n\n*** Push ***\n");
  push(2);
  push('a');
  push(4);
  printStack();
  isFull();

  (void)printf("\n\n*** Push over max ***\n");
  push(111);
  printStack();
  isFull();

  (void)printf("\n\n*** POP ALL ***\n");
  pop();
  pop();
  pop();
  pop();
  pop();
  printStack();
  isEmpty();
  isFull();

  return 0;
}