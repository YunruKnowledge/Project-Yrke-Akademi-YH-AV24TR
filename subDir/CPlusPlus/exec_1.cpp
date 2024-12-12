#include <cstdio>
#include <iostream>

// g++ -DNUMBER=16 .\index.cpp -o ./output/temp; .\output\temp.exe

#ifndef NUMBER
#error "Error while quering for number."
#elif NUMBER != 8 && NUMBER != 16
#error "Must be 8 or 16"
#endif

int main(void) {
  (void)printf("[%i] Success!", NUMBER);
  std::cout << " In your dreams... \n";
  return 0;
}
