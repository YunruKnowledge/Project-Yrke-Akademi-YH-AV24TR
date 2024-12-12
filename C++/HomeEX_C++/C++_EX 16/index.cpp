#include <iostream>
#include <stdlib.h>

using namespace std;

#define MIN_NUM 0
#define MAX_NUM 99

#define MAX_AMOUNT_OF_RANDOM_NUMBERS 10

int *getArrayOfRandomNumbers(int min, int max, int count);
void printArray(int *arr, int size);

int main(void)
{
    int *arrOfRandomNumbers = getArrayOfRandomNumbers(MIN_NUM, MAX_NUM, MAX_AMOUNT_OF_RANDOM_NUMBERS);

    cout << "Un sorted array:";
    printArray(arrOfRandomNumbers, MAX_AMOUNT_OF_RANDOM_NUMBERS);

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
