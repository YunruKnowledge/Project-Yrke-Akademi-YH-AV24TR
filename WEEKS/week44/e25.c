/*
Description

Make a function to fill an array of type int with unique random numbers in the range of 1 and 99.

Make another function to print an array of type int to the output.

Example: An array filled with random numbers: {9, 3, 8, 13, 5, 2, 6, 7, 1, 4}
*/
#include <stdio.h>
#include <time.h>   //Time yani tabiki.
#include <stdlib.h> //Srand/rand function.

#define SIZE 99 // 9 ints
// prototype
int numFill(int *pArr);

int main(void)
{
    // loop through the array and check if there is a num twice, if it exists run main again.
    int arr[SIZE];
    int *pArrN = arr;
    srand(time(NULL));

    numFill(pArrN);

    printf("The nums: %i", numFill(pArrN));

    return 0;
}

// make random nums, fill into the array.
int numFill(int *pArr)
{
    for (int i = 0; i < SIZE; i++)
    {
        *(pArr + i) = (rand() % 99 + 1); // modulus by 99 to get 1 - 99 nums.
        printf("The int in pos %i is %i\n", i, *(pArr + i));

        // if arr[i] == arr[j]
        // 9 8 7 4 5
        for (int j = 0; j < i; j++)
        {
            if (*(pArr + i) != *(pArr + j))
            {
                continue; // Rerun the forLoop that is above if(), yani bu iteration skip olucak...
            }
            else
            {
                printf(" (%i/%i)NUM -> %i ", i, j, *(pArr + i));
                *(pArr + i) = (rand() % 99 + 1);
                printf("=> %i\n", *(pArr + i));
            }
        }
    }
    return 0;
}

/*

// ChatGPT
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 9

// Prototypes
void numFill(int *pArr);
void printArray(const int *pArr);

int main(void)
{
    int arr[SIZE];
    srand(time(NULL));

    numFill(arr);    // Fill array with unique random numbers
    printArray(arr); // Print the array

    return 0;
}

// Function to fill the array with unique random numbers in the range 1-99
void numFill(int *pArr)
{
    for (int i = 0; i < SIZE; i++)
    {
        int newNum;
        int isUnique;

        // Loop until a unique number is found
        do
        {
            newNum = (rand() % 99) + 1; // Generate number between 1 and 99
            isUnique = 1;               // Assume the number is unique

            // Check if the number is already in the array
            for (int j = 0; j < i; j++)
            {
                if (pArr[j] == newNum)
                {
                    isUnique = 0; // Not unique, repeat
                    break;
                }
            }
        } while (!isUnique); // Repeat if not unique

        pArr[i] = newNum; // Assign unique number to array
    }
}

// Function to print the array elements
void printArray(const int *pArr)
{
    printf("Array filled with unique random numbers: {");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d", pArr[i]);
        if (i < SIZE - 1)
            printf(", "); // Add commas between numbers
    }
    printf("}\n");
}
*/