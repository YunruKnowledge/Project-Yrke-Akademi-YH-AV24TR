#include <stdio.h>

#define SIZE 3

void multiply_constant(int matrix[SIZE][SIZE], const int x);
void add_constant(int matrix[SIZE][SIZE], const int x);
void transpose_matrix(int matrix[SIZE][SIZE]);

// enum funcs
// {
//     addition,
//     muliply,
//     transpose
// };

int main(void)
{
    // enum funcs operation;
    // printf("enumFuncsOperation: %i", operation);

    // matrix array kendinden bir pointer, Asterisk koymaya gerek yok.
    //  Yani ilk brackets aslinda sadece bir *.
    int matrixArr[SIZE][SIZE] = {{10, 20, 30}, {50, 60, 70}, {90, 100, 110}};
    const int theX = 5;

    int choice = 0;
    printf("pick a number for operation:\n0: addition\n1: multiply\n2: transpose");
    scanf(" %i", &choice);
    printf("choice: %i", choice);

    void (*twoArgFuncArr[])(int[SIZE][SIZE], const int) = {
        multiply_constant,
        add_constant
    };

    //a pointer array that is holds the functions
    void (*oneArgFuncArr[])(int[SIZE][SIZE]) = { transpose_matrix};

    if (choice == 0)
    {
        twoArgFuncArr[choice](matrixArr, theX);
    }
    else if (choice == 1)
    {
        twoArgFuncArr[1](matrixArr, theX);
    }
    else if (choice == 2)
    {
        oneArgFuncArr[0](matrixArr);
    }
    else
    {
        printf("Invalid input!");
    }

    // multiply_constant(matrixArr, theX);
    // add_constant(matrixArr, theX);
    // transpose_matrix(matrixArr);

    return 0;
}

void multiply_constant(int matrix[SIZE][SIZE], const int x)
{
    printf("\nMultiplacation:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("-");
        for (int j = 0; j < SIZE; j++)
        {
            matrix[i][j] *= x;
            printf(" %i ", matrix[i][j]);
        }
        printf("-");
        printf("\n");
    }
    printf("\n");
}

// Take a const and add to the array.
void add_constant(int matrix[SIZE][SIZE], const int x)
{
    printf("\naddition:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("-");
        for (int j = 0; j < SIZE; j++)
        {
            matrix[i][j] += x;
            printf(" %i ", matrix[i][j]);
        }
        printf("-");
        printf("\n");
    }
    printf("\n");
}

void transpose_matrix(int matrix[SIZE][SIZE])
{
    printf("\nTranspose:\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {

            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }

        for (int k = 0; k < SIZE; k++)
        {
            printf(" %i ", matrix[i][k]);
        }
        printf("\n");
    }
}

// use function pointer to combine all the functions
/*
our task is to write a program that performs various operations on a square matrix. The program should include the following functions using function pointer:

multiply_constant: multiplies a matrix by a constant
add_constant: adds a constant to a matrix
transpose_matrix: transposes a matrix
display_matrix: displays a matrix
The program should also include a main function that allows the user to choose which operation to perform on the matrix.
*/
