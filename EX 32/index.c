#include <stdbool.h>
#include <stdio.h>
#include "../Librarys/GRN.h"
#include "../Librarys/sortArray.h"
#include "../Librarys/colors.h"


#define NUM_OF_RANDOM_NUM 20
#define MAX_RANDOM_NUM 99
#define MIN_RANDOM_NUM 0

#define ROW 3
#define COLUMNS 3

#define NUM_OF_CHANGED_VAL 2

void printArray(int *array)
{
    printf("{");
    for (int i = 0; i < NUM_OF_RANDOM_NUM; i++)
    {
        printf("%d", array[i]);
        if (i != (NUM_OF_RANDOM_NUM - 1))
            printf(", ");
    }
    printf("}\n");
}

void changeArrayVal(int *array, int minNum, int maxNum, int amountOfChanges, int numOfArrayNum)
{
    for (int i = 0; i < amountOfChanges; i++)
    {
        int *newNum = getArrayOfRandomNumbers(minNum, maxNum, amountOfChanges);
        int *randomNumPlace = getArrayOfRandomNumbers(minNum, numOfArrayNum, amountOfChanges);
        array[randomNumPlace[i] - 1] = newNum[i];
    }
}

int main()
{
    int *arr = getArrayOfRandomNumbers(MIN_RANDOM_NUM, MAX_RANDOM_NUM, NUM_OF_RANDOM_NUM);
    SetTextHighIntenstyColor(yellow);
    printArray(arr);

    SetTextHighIntenstyColor(green);
    changeArrayVal(arr, MIN_RANDOM_NUM, MAX_RANDOM_NUM, NUM_OF_CHANGED_VAL, NUM_OF_RANDOM_NUM);
    printArray(arr);

    sortArray(arr, NUM_OF_RANDOM_NUM, ascending);
    SetTextHighIntenstyColor(blue);
    printArray(arr);

    shuffleNum(arr, NUM_OF_RANDOM_NUM);
    SetTextHighIntenstyColor(red);
    printArray(arr);

    ResetColors();
    return 0;
}