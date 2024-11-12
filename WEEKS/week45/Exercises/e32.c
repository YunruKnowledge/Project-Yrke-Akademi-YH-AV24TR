#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 9
// bir type yaptim, compare t atinda bir pointer.
typedef bool (*compare_t)(int a, int b);

// void sort_array(int *arr, compare_t compare); !!OG!!
void sort_array(int *arr, compare_t compare);

void fillRndm(int *arr);
void consolePrint(int *arr);
void swpvars(int *a, int *b);
// void cmprNum(int *a, int *b);

bool compare_asc(int a, int b) { return a > b; };
bool compare_des(int a, int b) { return a < b; };

int main(void)
{
    int nArr[N];

    fillRndm(nArr);
    sort_array(nArr, compare_asc);
    consolePrint(nArr);

    return 0;
}

void fillRndm(int *arr)
{
    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        arr[i] = rand() % 100;
    }
}

void consolePrint(int *arr)
{
    printf("\n");
    for (int i = 0; i < N; i++)
    {
        printf(" %i ", arr[i]);
    }
    printf("\n");
}

void swpvars(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_array(int *arr, compare_t compare)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)//J tam sayidan az oldugunca
        {
            if (compare(arr[j], arr[j + 1]) == 0) // if a > b
            {
                swpvars(&arr[j], &arr[j + 1]);
            }
        }
    }
}