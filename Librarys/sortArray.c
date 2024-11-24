#include <stdlib.h>
#include <time.h>

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

bool checkArrayAscending(int *array, int length){
    bool returnCheck = true;
    for (int i = 0; i < (length - 1); i++){
        if (array[i] <= array[i+1]){
            returnCheck = true;
        }
        else{
            returnCheck = false;
            break;
        }
    }

    return returnCheck;
}
bool checkArrayDescending(int *array, int length){
    bool returnCheck = true;
    for (int i = (length - 1); i > 0; i--){
        if (array[i] >= array[i+1]){
            returnCheck = true;
        }
        else{
            returnCheck = false;
            break;
        }
    }

    return returnCheck;
}

void swapNum(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shuffleNum(int *array, int length)
{
    srand(time(NULL));
    for (int i = length - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swapNum(&array[i], &array[j]);
    }
}

void swapChar(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void shuffleChar(char *array, char length)
{
    srand(time(NULL));
    for (int i = length - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swapChar(&array[i], &array[j]);
    }
}