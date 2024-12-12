#include <iostream>
#include <stdlib.h>

using namespace std;

#define MIN_NUM 0
#define MAX_NUM 99

#define MAX_AMOUNT_OF_RANDOM_NUMBERS 10

typedef bool (*compare_t)(int, int);

bool ascending(int a, int b) { return a <= b; }
bool descending(int a, int b) { return a >= b; }

bool checkArrayAscending(int *array, int length);
bool checkArrayDescending(int *array, int length);

int *getArrayOfRandomNumbers(int min, int max, int count);

void printArray(int *arr, int size);

void sortArray(int *array, int length, compare_t compare);
void swap(int *a, int *b);

int *changeTwoVal(int *arr, int length);

int main(void)
{
    int *arrOfRandomNumbers = getArrayOfRandomNumbers(MIN_NUM, MAX_NUM, MAX_AMOUNT_OF_RANDOM_NUMBERS);

    cout << "Un sorted array:\t\t\t\t";
    printArray(arrOfRandomNumbers, MAX_AMOUNT_OF_RANDOM_NUMBERS);

    cout << "Un sorted array white changed val:\t\t";
    arrOfRandomNumbers = changeTwoVal(arrOfRandomNumbers, MAX_AMOUNT_OF_RANDOM_NUMBERS);
    printArray(arrOfRandomNumbers, MAX_AMOUNT_OF_RANDOM_NUMBERS);

    cout << "Sorted array Ascending:\t\t\t\t";
    sortArray(arrOfRandomNumbers, MAX_AMOUNT_OF_RANDOM_NUMBERS, ascending);
    printArray(arrOfRandomNumbers, MAX_AMOUNT_OF_RANDOM_NUMBERS);

    if (checkArrayAscending(arrOfRandomNumbers, MAX_AMOUNT_OF_RANDOM_NUMBERS))
    {
        cout << "Checking complete, array is sorted subsecfull!" << endl;
    }
    else
    {
        cout << "Checking complete, array is not sorted subsecfull!" << endl;
    }

    cout << "Sorted array Descending:\t\t\t";
    sortArray(arrOfRandomNumbers, MAX_AMOUNT_OF_RANDOM_NUMBERS, descending);
    printArray(arrOfRandomNumbers, MAX_AMOUNT_OF_RANDOM_NUMBERS);

    if (checkArrayDescending(arrOfRandomNumbers, MAX_AMOUNT_OF_RANDOM_NUMBERS))
    {
        cout << "Checking complete, array is sorted subsecfull!" << endl;
    }
    else
    {
        cout << "Checking complete, array is not sorted subsecfull!" << endl;
    }

    return 0;
}

int *getArrayOfRandomNumbers(int min, int max, int count)
{
    if (count <= 0 || min >= max)
        return NULL;

    int *numbers = (int *)malloc(count * sizeof(int));
    if (!numbers)
        return NULL;

    srand(time(NULL));
    for (int i = 0; i < count; i++)
    {
        numbers[i] = min + rand() % (max - min);
    }
    return numbers;
}

void printArray(int *arr, int size)
{
    cout << " { ";
    for (size_t i = 0; i < MAX_AMOUNT_OF_RANDOM_NUMBERS; i++)
    {
        cout << arr[i];
        if (i != MAX_AMOUNT_OF_RANDOM_NUMBERS - 1)
        {
            cout << ", ";
        }
    }
    cout << " }" << endl;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortArray(int *array, int length, compare_t compare)
{
    for (int i = 0; i < length - 1; ++i)
    {
        for (int j = 0; j < length - i - 1; ++j)
        {
            if (!compare(array[j], array[j + 1]))
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

bool checkArrayAscending(int *array, int length)
{
    bool returnCheck = true;
    for (int i = 0; i < (length - 1); i++)
    {
        if (array[i] <= array[i + 1])
        {
            returnCheck = true;
        }
        else
        {
            returnCheck = false;
            break;
        }
    }

    return returnCheck;
}

bool checkArrayDescending(int *array, int length)
{
    bool returnCheck = true;
    for (int i = (length - 1); i > 0; i--)
    {
        if (array[i] >= array[i + 1])
        {
            returnCheck = true;
        }
        else
        {
            returnCheck = false;
            break;
        }
    }

    return returnCheck;
}

int *changeTwoVal(int *arr, int length)
{
    int *pos = getArrayOfRandomNumbers(MIN_NUM, length, 2);
    int *val = getArrayOfRandomNumbers(MIN_NUM, MAX_NUM, 2);

    arr[pos[0]] = val[0];
    arr[pos[1]] = val[1];

    return arr;
}