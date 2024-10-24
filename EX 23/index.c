#include <stdio.h>
#include "../Librarys/GRN.h"
#include "../Librarys/colors.h"

#define NUM_OF_RANDOM_NUM 20
#define MAX_RANDOM_NUM 99
#define MIN_RANDOM_NUM 0
#define ROW 3
#define COLUMNS 3

int main()
{
    unsigned int *arr = getArrayOfRandomNumbers(MIN_RANDOM_NUM, MAX_RANDOM_NUM, NUM_OF_RANDOM_NUM);
    unsigned int numbers[ROW][COLUMNS];
    static int arrNum;

    for (int colum = 0; colum < COLUMNS; colum++)
    {
        for (int row = 0; row < ROW; row++)
        {
            numbers[row][colum] = arr[arrNum];
            arrNum++;
        }
    }

    for (int colum = 0; colum < COLUMNS; colum++)
    {
        for (int row = 0; row < ROW; row++)
        {
            printf("\t{%03d}", numbers[row][colum]);
        }
        printf("\n");
    }
}