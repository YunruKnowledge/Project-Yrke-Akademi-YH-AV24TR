#include <iostream>

#define MATRIX 3
// using namespace std;
void printMatrix(int _array[MATRIX][MATRIX]);

int main(void) {
  int _array[MATRIX][MATRIX]{0};
  int _input{0};

  printMatrix(_array);
  for (size_t a = 0; a < MATRIX; a++) {
    for (size_t b = 0; b < MATRIX; b++) {
      std::cout << "Input[" << a << "-" << b << "]: ";
      std::cin >> _input;
      _array[a][b] = _input;
    }
  }
  printMatrix(_array);

  return 0;
}

void printMatrix(int _array[MATRIX][MATRIX]) {
  for (size_t a = 0; a < MATRIX; a++) {
    for (size_t b = 0; b < MATRIX; b++) {
      std::cout << " [" << a << "-" << b << "]=" << _array[a][b];
    }
    std::cout << std::endl;
  }
}