#include <stdio.h>

unsigned long long int charBinaryToDecimal(const char *binary, const int length) {
  unsigned long long int returnDecimal = 0;

  for (int i = 0; i < length; i++) {
    printf("\nchar_%c ", binary[i]);
    printf("uint_%u ", (unsigned int)(binary[i] - '0'));
    returnDecimal <<= 1;
    printf("retur_%u ", returnDecimal);
    if ((binary[i] - '0') == 1)
      returnDecimal += (binary[i] - '0');
  }

  return returnDecimal;
}

int main(void) {
  char cArr[] = "0100100001100101011011000110110001101111";
  printf("Bin: %s\n", cArr);
  printf("Deci: %llu", charBinaryToDecimal(cArr, 40));

  return 0;
}
