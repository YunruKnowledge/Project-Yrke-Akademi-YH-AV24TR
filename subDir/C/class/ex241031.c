// goal:
// int only
// ask numbers
// ask operator
// result

#include <stdio.h>
#define INPUT_BUFFER 2

int addition(const int _value1, const int _value2);
int subtraction(const int _value1, const int _value2);
int multiplication(const int _value1, const int _value2);
int division(const int _value1, const int _value2);

int main(void) {
  int inputNumber_1, inputNumber_2, result;
  char inputOperatorType;
  int (*operatorType)(int, int);

  (void)printf("Basic calculator (Whole numbers only, and two intakes)\n");

  // Ask for two values.
  (void)printf(
      "Please enter the two numbers. (Sepration with space or enter.)\n");
  while (scanf("%i %i", &inputNumber_1, &inputNumber_2) != 2) {
    (void)printf("Invalid values.\n");
    int bufferChar;
    while ((bufferChar = getchar()) != '\n' && bufferChar != EOF)
      ;
  }

  (void)printf("DEBUG: first -> %i | second -> %i\n", inputNumber_1,
               inputNumber_2);

  // Get operator for calc.
  (void)printf("Select your operator. (+, -, *, /.)\n");
  do {
    scanf(" %c", &inputOperatorType);
    if (inputOperatorType == '+') {
      operatorType = addition;
      break;
    } else if (inputOperatorType == '-') {
      operatorType = subtraction;
      break;
    } else if (inputOperatorType == '*') {
      operatorType = multiplication;
      break;
    } else if (inputOperatorType == '/') {
      operatorType = division;
      break;
    } else {
      (void)printf("Invalid operator: %c\n", inputOperatorType);
    }
  } while (1);

  (void)printf("DEBUG: op -> %c\n", inputOperatorType);

  // Run and print.
  result = operatorType(inputNumber_1, inputNumber_2);
  (void)printf("The result is: %i\n", result);

  return 0;
}

int addition(const int _value1, const int _value2) {
  return (_value1 + _value2);
}
int subtraction(const int _value1, const int _value2) {
  return (_value1 - _value2);
}
int multiplication(const int _value1, const int _value2) {
  return (_value1 * _value2);
}
int division(const int _value1, const int _value2) {
  return (_value1 == 0 || _value2 == 0) ? 0 : (_value1 / _value2);
}