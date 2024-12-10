#include <iostream>
#include <random>

using namespace std;

int main(void) {

  unsigned int _array[10]{0};
  random_device dev;
  mt19937 rng(dev());
  uniform_int_distribution<mt19937::result_type> dist6(0, 100);

  for (size_t i = 0; i < 10; i++) {
    _array[i] = dist6(rng);
    cout << " [" << i << "]=" << _array[i];
  }
  cout << endl;

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

  for (size_t i = 0; i < 10; i++) {
    cout << " [" << i << "]=" << _array[i];
  }
  cout << endl;

  return 0;
}
