#include <cctype>
#include <iostream>
#include <random>

using namespace std;

int main(void) {
  char _letter;
  cin >> _letter;
  cout << "Hi, " << _letter << endl;
  if (_letter == tolower(_letter)) {
    cout << "NEW LETTER: " << static_cast<char>(toupper(_letter)) << endl;
  } else {
    cout << "NEW LETTER: " << static_cast<char>(tolower(_letter)) << endl;
  }

  random_device dev;
  mt19937 rng(dev());
  uniform_int_distribution<mt19937::result_type> dist6(0, 4'000'000'000);

  cout << "Random number: " << dist6(rng) << " & " << dist6(rng) << endl;

  return 0;
}
