
#include <iostream>

constexpr int ARRAY_SIZE{21};

class Stack {
  int array[ARRAY_SIZE];
  int count;

public:
  Stack() : array{0}, count{0} {};

  bool push(int _value) {
    bool status{false};
    if (count < ARRAY_SIZE) {
      array[count] = _value;
      count++;
      status = true;
    }
    return status;
  };

  int getNumber(void) { return count; };

  bool pop(int &_int) {
    int status{false};
    if (count > 0) {
      count--;
      _int = array[count];
      status = true;
    }
    return status;
  }

  bool checkFull(void) { return count == ARRAY_SIZE ? true : false; }

  bool checkEmpty(void) { return count == 0 ? true : false; }

  void clear(void) { count = 0; }
};

int main(void) {

  Stack _stack;
  std::cout << _stack.getNumber() << std::endl;
  _stack.push(64);
  std::cout << _stack.getNumber() << std::endl;
  _stack.push(128);
  _stack.push(256);
  _stack.push(512);
  _stack.push(1024);
  _stack.push(2048);
  _stack.push(4096);
  std::cout << _stack.getNumber() << std::endl;
  _stack.push(8192);
  std::cout << _stack.getNumber() << std::endl;

  int mila;
  _stack.pop(mila);
  std::cout << mila << std::endl;
  std::cout << _stack.getNumber() << std::endl;

  return 0;
};