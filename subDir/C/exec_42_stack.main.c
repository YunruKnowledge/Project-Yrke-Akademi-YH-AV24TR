#include "exec_42_stack.h"
#include <stdio.h>
#include <assert.h>

int main() {
  int _temp = 0;
  size_t _length = 0;


  (void)printf("DEBUG: Creating stack...\n");
  (void)printf("DEBUG: Stack 1.\n");
  stack_t *_test1 = stackCreate(24);
  (void)printf("DEBUG: Stack 2.\n");
  stack_t *_test2 = stackCreate(4);
  assert(_test1 != NULL);
  assert(_test2 != NULL);
  (void)printf("DEBUG: Creating complete.\n");


  (void)printf("DEBUG: Pushing values...\n");
  (void)printf("DEBUG: Stack 1.\n");
  stackPush(_test1, 22);
  stackPush(_test1, 66);
  _length = stackRead(_test1);
  assert(_length == 2);

  (void)printf("DEBUG: Stack 2.\n");
  stackPush(_test2, 24);
  stackPush(_test2, 66);
  stackPush(_test2, 33);
  stackPush(_test2, 77);
  stackPush(_test2, 99);
  stackPush(_test2, 10);
  _length = stackRead(_test2);
  assert(_length == 4);
  (void)printf("DEBUG: Pushing values complete.\n");


  (void)printf("DEBUG: Popping stacks...\n");
  (void)printf("DEBUG: Stack 1.\n");
  stackPop(_test1, &_temp);
  (void)printf("Popped: %u\n", _temp);
  assert(_temp == 66);
  stackRead(_test1);

  (void)printf("DEBUG: Stack 2.\n");
  stackPop(_test2, &_temp);
  (void)printf("Popped: %u\n", _temp);
  assert(_temp == 77);
  stackRead(_test2);
  (void)printf("DEBUG: Popping stacks complete.\n");


  (void)printf("DEBUG: Freeing stacks from memory...\n");
  stackFree(_test1);
  stackFree(_test2);
  (void)printf("DEBUG: Freed stacks complete.\n");


  return 0;
}