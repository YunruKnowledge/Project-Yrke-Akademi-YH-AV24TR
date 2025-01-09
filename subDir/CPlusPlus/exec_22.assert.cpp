#include "exec_22.hpp"
#include <cassert>
#include <iostream>

int Stack::array[];
int Stack::count;

int main(void) {

  std::cout << "Assert test" << std::endl;
  Stack _stack;
  Stack _stack2;
  assert(0 == _stack.getNumber());
  assert(true == _stack.push(64));
  assert(1 == _stack.getNumber());
  assert(true == _stack.push(128));
  assert(true == _stack.push(256));
  assert(true == _stack.push(512));
  assert(true == _stack.push(1024));
  assert(true == _stack.push(2048));
  assert(true == _stack.push(4096));
  assert(true == _stack.push(8192));
  assert(8 == _stack.getNumber());

  assert(false == _stack.push(9999)); // max-ed
  assert(8 == _stack.getNumber());

  int mila;
  _stack.pop(mila);
  assert(8192 == mila);
  assert(7 == _stack.getNumber());

  // stack 2
  _stack2.pop(mila);
  assert(4096 == mila);
  assert(6 == _stack.getNumber());

  _stack2.clear();
  assert(0 == _stack.getNumber());
  assert(false == _stack.pop(mila)); // min-ed
  std::cout << "Assert passed" << std::endl;

  return 0;
};