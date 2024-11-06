
#include <stdio.h>
#define SIZE 3
void display_matrix(int matrix[SIZE][SIZE]);
void multiply_constant(int matrix[SIZE][SIZE], int constant);
void add_constant(int matrix[SIZE][SIZE], int constant);
void transpose_matrix(int matrix[SIZE][SIZE]);

// Your task is to write a program that performs various operations on a square
// matrix.
//  The program should include the following functions using function pointer:

// multiply_constant: multiplies a matrix by a constant
// add_constant: adds a constant to a matrix
// transpose_matrix: transposes a matrix
// display_matrix: displays a matrix
// The program should also include a main function that
//  allows the user to choose which operation to perform on the matrix.

int main(void) {
  int matrixArr[SIZE][SIZE] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  void (*math_operators)(int[SIZE][SIZE], int);
  void (*singleInputOperators)(int[SIZE][SIZE]);
  int operatorTypeSingle = 0;

  (void)printf("Welcome, you have a\n");
  display_matrix(matrixArr);
  (void)printf("What would you like to do?\n");
  (void)printf("1. Multiply.\n"
               "2. Addition.\n"
               "3. Transpose rows and cols.\n4. "
               "Re-display matrix.\n");

  unsigned int input = 0;
  scanf("%u", &input);

  if (input == 0 || input > 4) {
    (void)printf("Invalid input.\n Exiting...\n");
  } else {
    switch (input) {
    case 1:
      math_operators = multiply_constant;
      break;
    case 2:
      math_operators = add_constant;
      break;
    case 3:
      singleInputOperators = transpose_matrix;
      operatorTypeSingle = 1;
      break;
    case 4:
      singleInputOperators = display_matrix;
      operatorTypeSingle = 1;
      break;

    default:
      printf("FATAL error... somehow input not matched in switch case.\n");
      break;
    }
  }

  if (operatorTypeSingle) {
    singleInputOperators(matrixArr);
    if (input != 4) {
      printf("Here's the result!\n");
      display_matrix(matrixArr);
    }
  } else {
    printf("Now enter a number.\n");
    scanf("%u", &input);
    math_operators(matrixArr, input);
    printf("Here's the result!\n");
    display_matrix(matrixArr);
  }

  return 0;
}

// Function Name: display_matrix

// void display_matrix(int matrix[SIZE][SIZE])

// Function Description:

// The display_matrix function should display the elements of a square matrix
//  in a readable format.
//  The function should take a 2D array matrix of size SIZE x SIZE as input,
//  where SIZE is a constant defined at the top of the program.

// Requirements:

// The function should display each element of the matrix on a separate line,
//  with each row of the matrix on a separate line.
// The function should use a space to separate each element in a row.
// The function should use a newline to separate each row of the matrix.
// The function should not return any value

void display_matrix(int matrix[SIZE][SIZE]) {
  for (int i = 0; i < (SIZE * SIZE); i++) {
    if ((i + 1) % SIZE == 0) {
      (void)printf("%i ", matrix[0][i]);
      (void)printf("\n");
    } else {
      (void)printf("%i ", matrix[0][i]);
    }
  }
}

// Matrix Multiplication by a Constant

// Your task is to write a function that multiplies a square matrix by a
//  constant.
//  The function should take a square matrix of size 3 x 3 and a constant as
//  input, and modify the matrix in-place to be the result of the multiplication

// void multiply_constant(int matrix[SIZE][SIZE], int constant)

// Function Description

// The multiply_constant function takes a square matrix of size 3 x 3 and a
//  constant as input,
//  and multiplies each element of the matrix by the constant.
//  The function should not return any value,
//  but instead modify the input matrix to be the result of the multiplication.

// Requirements:

// The function should use a nested loop structure to iterate over the elements
//  of the matrix. The function should multiply each element of the matrix by
//  the constant using the *= operator.
// The function should modify the input matrix in-place, without creating a new
//  matrix

void multiply_constant(int matrix[SIZE][SIZE], int constant) {
  for (int a = 0; a < SIZE; a++) {
    for (int b = 0; b < SIZE; b++) {
      matrix[a][b] *= constant;
    }
  }
}

// client change multiply into addition.
void add_constant(int matrix[SIZE][SIZE], int constant) {
  for (int a = 0; a < SIZE; a++) {
    for (int b = 0; b < SIZE; b++) {
      matrix[a][b] += constant;
    }
  }
}

// Transpose Matrix Function

// Your task is to write a function that transposes a square matrix.
// The transpose of a matrix is an operator
//  which can be thought of as "swapping" the rows and columns for a matrix.

// void transpose_matrix(int matrix[SIZE][SIZE]);

// Function Description

// The transpose_matrix function takes a square matrix of size 3 x 3 as input
// and transposes it in-place.
//  The function should not return any value, but instead modify the input
//  matrix to be its transpose.

// Requirements

// The function should use a nested loop structure to iterate over the elements
//  of the matrix.
// The function should use a temporary variable to swap the
//  elements of the matrix.
// The function should only transpose the upper
//  triangular part of the matrix, since the lower triangular part will be
//  automatically transposed as well.

void transpose_matrix(int matrix[SIZE][SIZE]) {
  for (int a = 0; a < SIZE; a++) {
    for (int b = a + 1; b < SIZE; b++) {
      int _temp = matrix[a][b];
      (void)printf("debug: %i\n", _temp);
      matrix[a][b] = matrix[b][a];
      matrix[b][a] = _temp;
    }
  }
}
