#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 20

typedef bool (*compare_t)(int a, int b);
typedef bool (*compare_asc)(int a, int b);
typedef bool (*compare_des)(int a, int b);

// void sort_array(int *arr, compare_t compare); !!OG!!
void sort_array(int *arr, compare_t compare, compare_asc ascend, compare_des descend);

void fillRndm(int *arr);
void consolePrint(int *arr);
void swpvars(int *a, int *b);
void cmprNum(int *a, int *b);

int main(void)
{
    int nArr[N];

    int choice = 0;
    //ASK user for choice!!!
    
    sort_array(nArr, cmprNum);

    // to ascend 0, descend 1;

    return 0;
}

void fillRndm(int *arr)
{
    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        arr[i] = rand() % 10;
    }
}

void consolePrint(int *arr)
{
    for (int i = 0; i < N; i++)
    {
        printf("%i", arr[i]);
    }
}

void swpvars(int *a, int *b)
{
    int temp = a;
    a = b;
    b = temp;
}

void asc(int *a, int *b)
{
    int temp;
    if (a > b)
    {
        temp = a;
        a = b;
        b = temp;
    }
}

void dec(int *a, int *b)
{
    int temp;
    if (a < b)
    {
        temp = a;
        a = b;
        b = temp;
    }
}

void cmprNum(int *a, int *b)
{
    if (a == b)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void sort_array(int *arr, compare_t compare, compare_asc ascend, compare_des descend)
{

    for (int i = 0; i < N; i++)
    {
        if (choice == 0)
        {
            ascend(arr[i], arr[i + 1]);
        }
        else if (choice == 1)
        {
            /*temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
            */
            // swpv1ars(arr[i], arr[i + 1]);
            descend(arr[i], arr[i + 1]);
        }
    }
}