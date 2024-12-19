#include <iostream>
#include <random>
#define NUM 10

void arrayPrint(int *_iptr, const size_t _size);
void arrayFillRandom(int *_iptr, const size_t _size);
//Make a function to swap values of -two int variables(?).
void arrayFlip(int *_iptr, const size_t _a, const size_t _b); 

using compare_t = bool (*)(int, int);
void sort_array(size_t length, int *arr, compare_t compare);
bool compare_asc(int a, int b);
bool compare_desc(int a, int b);

void intSwap(int &_a, int &_b); // Make a function to swap values of two int -variables(?).

int main(void) {
  int _array[NUM]{0};
  int *_iptr{_array};

  arrayPrint(_iptr, NUM);

  arrayFillRandom(_iptr, NUM);
  arrayPrint(_iptr, NUM);

  arrayFlip(_iptr, 2, 3);
  arrayPrint(_iptr, NUM);

  sort_array(NUM, _iptr, compare_asc);
  arrayPrint(_iptr, NUM);

  sort_array(NUM, _iptr, compare_desc);
  arrayPrint(_iptr, NUM);

  int a{1};
  int b{24};
  std::cout << "A&B->" << a << "/" << b << std::endl;
  intSwap(a, b);
  std::cout << "A&B->" << a << "/" << b << std::endl;

  return 0;
}

void arrayPrint(int *_iptr, const size_t _size) {
  std::cout << "Printing: ";
  for (size_t i = 0; i < _size; i++) {
    std::cout << _iptr[i];
    if (i < NUM - 1) {
      std::cout << ", ";
    }
  }
  std::cout << std::endl;
}

void arrayFillRandom(int *_iptr, const size_t _size) {
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 99);

  for (size_t i = 0; i < _size; i++) {
    _iptr[i] = dist6(rng);
  }
}

void arrayFlip(int *_iptr, const size_t _a, const size_t _b) {
  int _temp{_iptr[_a]};
  _iptr[_a] = _iptr[_b];
  _iptr[_b] = _temp;
}

void sort_array(size_t length, int *arr, compare_t compare) {
  while (true) {
    bool _swapped = false;
    for (size_t i = 0; i < length - 1; i++) {
      if (compare(arr[i], arr[i + 1])) {
        int _temp{arr[i]};
        arr[i] = arr[i + 1];
        arr[i + 1] = _temp;
        _swapped = true;
      }
    }
    if (!_swapped)
      break;
  }
}

bool compare_asc(int a, int b) { return (a > b); }

bool compare_desc(int a, int b) { return (a < b); }

void intSwap(int &_a, int &_b) {
  int _temp{_a};
  _a = _b;
  _b = _temp;
}