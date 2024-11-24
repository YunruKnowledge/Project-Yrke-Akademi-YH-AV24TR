#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../Librarys/colors.h"

#define RANDOM_STRING "Hello My World!"
#define MIN 0
#define MAX 255
#define ARRAY_LENGTH 10

typedef union binary
{
    float f;
    unsigned int uf;
} newBinary;

int calculateString(const char *string);
void swapVal(int *a, int *b);
void toBinary(uint8_t number);
void bubbleSorting(int *arr, int n);
void printArray(int *arr, int n);
int* mergeArray(int *arrOne, int *arrTwo, int n);

int main(void)
{
    int numA = 10, numB = 5, *a = &numA, *b = &numB;
    unsigned int userInput;
    int array[ARRAY_LENGTH] = {7, 5, 3, 9, 6, 8, 1, 4, 2, 10};
    
    // Number Swap
    (void)printf("Size of string is: %d \n\n", calculateString(RANDOM_STRING));

    (void)printf("Normal Number A: %d \nNormal Number B: %d \n\n", *a, *b);
    swapVal(a, b);
    (void)printf("Swap Number A: %d \nSwap Number B: %d \n\n", *a, *b);

    // Binary Converter
    (void)printf("Input a number[0-255]: ");
    scanf("%u", &userInput);

    if (userInput < MIN || userInput > MAX)
        (void)ShowErrorMessage("Wrong Input!");
    else
        toBinary(userInput);

    // Array Sorting!
    (void)printf("\nUnsorted array: \t");
    printArray(array, ARRAY_LENGTH);
    bubbleSorting(array, ARRAY_LENGTH);
    (void)printf("\nSorted array: \t\t");
    printArray(array, ARRAY_LENGTH);
    (void)printf("\n");

    // Merge Arrays
    int *mergedArray = mergeArray(array, array, ARRAY_LENGTH);
    (void)printf("Merged Array: \t\t");
    printArray(mergedArray, 2 * ARRAY_LENGTH);
    bubbleSorting(mergedArray, 2 * ARRAY_LENGTH);
    (void)printf("\nSorted Merged Array: \t");
    printArray(mergedArray, 2 * ARRAY_LENGTH);
    (void)printf("\n");

    return 0; // The end
}

int calculateString(const char *string)
{
    int i = 0;
    while (string[i])
    {
        if (string[i] == '\0')
            break;
        else
            i++;
    }
    return i;
}

void swapVal(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void toBinary(uint8_t number)
{
    uint8_t mask = 0b10000000;
    for (int i = 0; i < 8; i++)
    {
        (void)putchar(number & mask >> i ? '1' : '0');
    }
    (void)printf("\n");
}

void bubbleSorting(int *arr, int n)
{
    int i, j;
    bool swapped;

    for (i = 0; i < n; i++)
    {
        swapped = false;
        for (j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swapVal(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}

void printArray(int *arr, int n)
{
    (void)printf("{");
    for (int i = 0; i < n; i++)
    {
        (void)printf("%d", arr[i]);

        if (i != n - 1)
            (void)printf(", ");
    }
    (void)printf("}");
}

int* mergeArray(int *arrOne, int *arrTwo, int n)
{
    int *merged = (int *)malloc((n + n) * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        merged[i] = arrOne[i];
        merged[n + i] = arrTwo[i];
    }

    return merged;
}