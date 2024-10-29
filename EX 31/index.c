#include <stdio.h>
#include "../Librarys/GRN.h"

#define NUM_OF_RANDOM_NUM 20
#define MAX_RANDOM_NUM 99
#define MIN_RANDOM_NUM 0

#define ROW 3
#define COLUMNS 3

int main()
{
    int *arr = getArrayOfRandomNumbers(MIN_RANDOM_NUM, MAX_RANDOM_NUM, NUM_OF_RANDOM_NUM);
    int numbers[ROW][COLUMNS];
    int arrNum = 0;

    int(*numberPointer)[COLUMNS] = numbers;

    for (int row = 0; row < ROW; row++)
    {
        for (int colum = 0; colum < COLUMNS; colum++)
        {
            numberPointer[row][colum] = arr[arrNum++];
        }
    }

    for (int row = 0; row < ROW; row++)
    {
        for (int colum = 0; colum < COLUMNS; colum++)
        {
            printf("\t{%03d}", numberPointer[row][colum]);
        }
        printf("\n");
    }

    return 0;
}
