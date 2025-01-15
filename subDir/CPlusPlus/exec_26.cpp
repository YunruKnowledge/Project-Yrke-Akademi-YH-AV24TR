#include <iostream>

template <typename Type> void print(const Type &_val) {
  std::cout << _val << std::endl;
}

template <typename Type> void print(const Type *_ptr, const size_t _size) {
  for (size_t i = 0; i < _size; i++) {
    std::cout << _ptr[i] << std::endl;
  }
}

int main(void) {
  print(22);
  print(2.2f);
  print(22.2222222);

  int array[3]{1, 2, 3};
  print(array, 3);

  return 0;
}