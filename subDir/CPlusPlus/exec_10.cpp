#include <iostream>
#include <random>

#define MATRIX 2
#define MATRIX_2 3
// using namespace std;
void printMatrix(int _array);

int main(void) {
  int _array[MATRIX][MATRIX_2]{0};
  int *_iptr{reinterpret_cast<int *>(_array)};
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 99);

  for (size_t i = 0; i < MATRIX * MATRIX_2; i++) {
    *(_iptr + i) = dist6(rng);
    std::cout << " [" << i << "]=" << *(_iptr + i);
    if ((i+1) % MATRIX_2 == 0 && i != 0) {
      std::cout << std::endl;
    }
  }
  std::cout << std::endl;

  return 0;
}
