#include <iostream>

template <typename Type, size_t Size> void print(const Type *_array) {
  for (size_t i = 0; i < Size; i++) {
    std::cout << _array[i] << ">";
  };
  std::cout << std::endl;
}

template <typename T, size_t SIZE> using func_t = void (*)(const T[SIZE]);

template <typename T> struct array {};

template <typename T, size_t SIZE> struct array<T[SIZE]> {
  using elem_type = T;
  static constexpr size_t size{SIZE};
};

int main(void) {
  int arr[3]{1, 2, 3};

  using type = array<decltype(arr)>::elem_type;
  constexpr size_t size{array<decltype(arr)>::size};

  func_t<type, size> pptr{print<type, size>};

  pptr(arr);
  return 0;
}