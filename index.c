#include <stdbool.h>
#include <stdio.h>

int main() {
  unsigned int userInputNum;
  bool isPrime = false;

  do {
    printf("Input a number between 2 and 10000: \n");
    scanf("%i", &userInputNum);
    unsigned int count = 0;

    if (userInputNum >= 2 && userInputNum <= 10000) {
      for (int i = 1; i <= userInputNum; i++) {
            if (userInputNum % i == 0)
                count++;
        }
        
        if (count > 2)
            printf("Your number [%d] is not a PRIME number! \n", userInputNum);
        else{
            printf("Your number [%d] is a PRIME number! \n", userInputNum);
            isPrime = true;
        }
    }
  } while (!isPrime);

  return 0;
}   