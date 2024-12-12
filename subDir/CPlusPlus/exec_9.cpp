#include <iostream>
#include <random>

// using namespace std;
void sortArray(unsigned int *_array);

int main(void) {

  unsigned int _array[10]{0};
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 99);

  unsigned int *_iptr{_array};

  for (size_t i = 0; i < 10; i++) {
    _iptr[i] = dist6(rng);
    std::cout << " [" << i << "]=" << _iptr[i];
  }
  std::cout << std::endl;

  sortArray(_iptr);

  for (size_t i = 0; i < 10; i++) {
    std::cout << " [" << i << "]=" << _iptr[i];
  }
  std::cout << std::endl;

  return 0;
}

void sortArray(unsigned int *_array) {
  bool _loop = true;
  while (_loop) {
    _loop = false;
    for (size_t i = 0; i < 10; i++) {
      if (_array[i] > _array[i + 1]) {
        unsigned int _temp = 0;
        _temp = _array[i];
        _array[i] = _array[i + 1];
        _array[i + 1] = _temp;

        _loop = true;
      }
    }
  }
}