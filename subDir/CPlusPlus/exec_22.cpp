#include "exec_22.hpp"

static Stack &instance(void) {
  static Stack stack;
  return stack;
}

bool Stack::push(int _value) {
  bool status{false};
  if (count < ARRAY_SIZE) {
    array[count] = _value;
    count++;
    status = true;
  }
  return status;
};

int Stack::getNumber(void) { return count; };

bool Stack::pop(int &_int) {
  int status{false};
  if (count > 0) {
    count--;
    _int = array[count];
    status = true;
  }
  return status;
}

bool Stack::checkFull(void) { return count == ARRAY_SIZE ? true : false; }

bool Stack::checkEmpty(void) { return count == 0 ? true : false; }

void Stack::clear(void) { count = 0; }