#include <iostream>
#include <random>

void arrayPrint(int *_iptr, const size_t _size);
void arrayFillUnique(int *_iptr, const size_t _size);

int main(void) {
  int _array[98]{0};

  arrayPrint(_array, 98);
  arrayFillUnique(_array, 98);
  arrayPrint(_array, 98);

  return 0;
}

void arrayPrint(int *_iptr, const size_t _size) {
  std::cout << "Printing: ";
  for (size_t i = 0; i < _size; i++) {
    std::cout << _iptr[i];
    if (i < _size - 1) {
      std::cout << ", ";
    }
  }
  std::cout << std::endl;
}

void arrayFillUnique(int *_iptr, const size_t _size) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 99);
  int _rand{static_cast<int>(dist6(rng))};

  for (size_t i = 0; i < _size; i++) {
    while (true) {
      bool _isLooping{false};
      for (size_t i = 0; i < _size; i++) {
        if (_iptr[i] == 0) {
          break;
        } else if (_iptr[i] == _rand) {
          _rand = dist6(rng);
          _isLooping = true;
          break;
        }
      }
      if (!_isLooping)
        break;
    }
    _iptr[i] = _rand;
  }
}