/*
Description

1) Make a function to fill an array of type int with random numbers.

2) Make a function to print an array of type int to the output.

3) Make a function to print a 2D array of type int to the output.



* To handle the arrays use only pointers
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 8
void fillWrandomNums(int *arr);
void consoleLog(int *arr);
void console2dArray(int arr[N][N]);

int main(void)
{
    int numArr[N];
    int numArr2d[N][N] = {{1, 2, 3, 4, 5, 7, 8}, {1, 2, 3, 4, 5, 6, 7, 8}, {1, 2, 3, 4, 5, 7, 8}, {1, 2, 3, 4, 5, 6, 7, 8}, {1, 2, 3, 4, 5, 7, 8}, {1, 2, 3, 4, 5, 6, 7, 8}, {1, 2, 3, 4, 5, 7, 8}, {1, 2, 3, 4, 5, 6, 7, 8}};

    fillWrandomNums(numArr);
    consoleLog(numArr);
    console2dArray(numArr2d);

    return 0;
}

void fillWrandomNums(int *arr)
{
    srand(time(NULL));
    printf("fillRandom\n");

    for (int i = 0; i < N; i++)
    {
        arr[i] = rand() % 10;
    }
    printf("\n");
}

void consoleLog(int *arr)
{
    printf("PrintConsole\n");
    for (int i = 0; i < N; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
}

void console2dArray(int arr[N][N])
{

    for (int i = 0; i < N; i++)
    {
        printf("Row: %i\n", (i + 1));
        printf("Collumn:");
        for (int j = 0; j < i; j++)
        {
            printf("-%i-", arr[i][j]);
        }
        printf("\n");
    }
}
