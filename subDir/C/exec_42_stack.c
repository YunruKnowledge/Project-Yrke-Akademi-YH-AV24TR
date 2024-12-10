#include "exec_42_stack.h"
#include <stdio.h>

typedef struct STACK {
  uint8_t *stack;
  int layer;
  size_t length;
} stack_t;

stack_t *stackCreate(const size_t _length) {
  stack_t *_stack = (stack_t *)malloc(sizeof(stack_t));
  if (_stack) {
    _stack->stack = (uint8_t *)malloc(sizeof(uint8_t) * _length);
    _stack->layer = -1;
    _stack->length = _length;
  }

  return _stack;
}

bool stackPush(stack_t *_stack, const uint8_t _value) {
  bool _success = false;
  if (_stack->layer < (int64_t)_stack->length-1) {
    _stack->layer++;
    _stack->stack[_stack->layer] = _value;
    _success = true;
  }
  return _success;
}

bool stackPop(stack_t *_stack, int *_iptr) {
  int _success = false;
  if (_stack->layer > -1) {
    *_iptr = _stack->stack[_stack->layer];
    _stack->stack[_stack->layer] = 0;
    _stack->layer--;
    _success = true;
  }
  return _success;
}

size_t stackRead(stack_t *_stack) {
  if (_stack->layer != -1) {
    (void)printf("Layers: %i\n", _stack->layer + 1);
    for (int i = 0; i <= _stack->layer; i++) {
      (void)printf("[%i]: %u\n", i, _stack->stack[i]);
    }
  }
  return (_stack->layer == -1) ? 0 : (size_t)(_stack->layer + 1);
}

bool stackClear(stack_t *_stack) {
  bool _success = false;
  if (_stack->layer > -1) {
    for (int i = 0; i <= _stack->layer; i++) {
      _stack->stack[i] = 0;
    }
    _stack->layer = -1;
    _success = true;
  }
  return _success;
}

bool stackFree(stack_t *_stack) {
  if (_stack->layer > -1) {
    free(_stack->stack);
    _stack->stack = NULL;
    free(_stack);
    _stack = NULL;
  }
  return (_stack == NULL);
}
