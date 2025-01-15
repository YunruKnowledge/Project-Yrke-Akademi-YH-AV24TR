#include <iostream>

template <typename Type> void print(const Type *_array, const size_t _size) {
  for (size_t i = 0; i < _size; i++) {
    std::cout << _array[i] << ">";
  };
  std::cout << std::endl;
}

template <typename Type, typename FunctionType>
void ptrPrint(const Type *_array, const size_t _size, FunctionType _function) {
  _function(_array, _size);
}

int main(void) {
  int array[3]{1, 2, 3};
  ptrPrint(array, 3, print<int>);

  return 0;
}