/**
 * @file exec_18.cpp
 * @author Khanh Tran (88000687+YunruKnowledge@users.noreply.github.com)
 * @brief bruh
 * @version 0.1
 * @date 2024-12-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <cassert>
#include <iostream>

// Header file. (Here for CompileRun extension.)
#ifndef MODULE_STACK_H
#define MODULE_STACK_H

constexpr int ARR_SIZE{10};
typedef struct Stack stack_t;

/**
 * @brief Creates and returns a stack instance.
 *
 * @return Returns the adress of a new stack instance - `stack_t*`
 */
stack_t *stackCreate(void);

/**
 * @brief Pushes a value into the stack instance.
 *
 * @param _stack Adress of a stack instance.
 * @param _value A size_t to apply into stack.
 */
void stackPush(stack_t *_stack, const size_t _value);

/**
 * @brief Returns amount of data/layers in a stack instance.
 *
 * @param _stack Adress of a stack instance.
 * @return Amount - `size_t`
 */
size_t stackAmount(stack_t *_stack);

/**
 * @brief Reads and removes top layer of the stack instance.
 *
 * @param _stack Adress of a stack instance.
 * @return Returns the popped value - `size_t`
 */
size_t stackPop(stack_t *_stack);

/**
 * @brief Resets stack instance's amount count.
 *
 * @param _stack Adress of a stack instance.
 */
void stackClear(stack_t *_stack);

/**
 * @brief Deteles stack instance from memory.
 *
 * @param _stack Adress of a stack instance.
 */
void stackDelete(stack_t *_stack);

#endif

// Source file. (Here for CompileRun extension.)
typedef struct Stack {
  int _stack[ARR_SIZE];
  size_t _amount;
} stack_t;

stack_t *stackCreate(void) {
  stack_t *_stack = new stack_t;
  _stack->_amount = 0;
  return _stack;
}

void stackPush(stack_t *_stack, const size_t _value) {
  _stack->_stack[_stack->_amount] = _value;
  _stack->_amount += 1;
}

size_t stackAmount(stack_t *_stack) { return _stack->_amount; }

size_t stackPop(stack_t *_stack) {
  size_t _temp{0};
  if (_stack->_amount > 0) {
    _stack->_amount -= 1;
    _temp = _stack->_stack[_stack->_amount];
  } else {
    std::cout << "WARNING:" << __LINE__ << ":EMPTY STACK:" << _stack->_amount
              << std::endl;
  }
  return _temp;
}

void stackClear(stack_t *_stack) { _stack->_amount = 0; }

void stackDelete(stack_t **_stack) {
  delete *_stack;
  *_stack = nullptr;
  _stack = nullptr;
}

// Misc. / index file.
/**
 * @brief Assert test.
 */
int main(void) {
  // Init
  stack_t *_temp{stackCreate()};
  stack_t *_temp2{stackCreate()};
  size_t _itemp{0};

  // Push
  stackPush(_temp, 21);
  stackPush(_temp, 4);
  stackPush(_temp, 125);

  stackPush(_temp2, 11);
  stackPush(_temp2, 22);
  stackPush(_temp2, 33);

  // Checking amount
  assert(stackAmount(_temp) == 3);
  assert(stackAmount(_temp2) == 3);
  std::cout << "Print->" << stackAmount(_temp) << std::endl;
  std::cout << "Print->" << stackAmount(_temp2) << std::endl;

  // Pop
  _itemp = stackPop(_temp);
  assert(_itemp == 125);
  std::cout << "POP->" << _itemp << std::endl;

  _itemp = stackPop(_temp);
  assert(_itemp == 4);
  std::cout << "POP->" << _itemp << std::endl;

  _itemp = stackPop(_temp2);
  assert(_itemp == 33);
  std::cout << "POP->" << _itemp << std::endl;

  _itemp = stackPop(_temp2);
  assert(_itemp == 22);
  std::cout << "POP->" << _itemp << std::endl;

  _itemp = stackPop(_temp2);
  assert(_itemp == 11);
  std::cout << "POP->" << _itemp << std::endl;

  _itemp = stackPop(_temp2);
  assert(_itemp == 0);
  std::cout << "POP->" << _itemp << std::endl;

  // Clear & Pop
  stackClear(_temp);
  _itemp = stackPop(_temp);
  assert(_itemp == 0);
  std::cout << "POP->" << _itemp << std::endl;

  // Delete
  stackDelete(&_temp);
  stackDelete(&_temp2);
  assert(_temp == nullptr);
  assert(_temp2 == nullptr);

  return 0;
}
