#include "numGenerator.h"
#include <iostream>

bool checkRange(int min, int max);

int NUMGEN::randomNumber(int min, int max)
{
    checkRange(min, max);

    int randomNumber{0};

    srand(time(0));
    randomNumber = rand() % (max - min + 1) + min;

    return randomNumber;
}

void NUMGEN::randomNumbers(int min, int max, int amount, int *numArr)
{
    checkRange(min, max);

    int randomNumber{0};
    srand(time(0));

    for (size_t i = 0; i < amount; i++)
    {
        randomNumber = rand() % (max - min + 1) + min;
        numArr[i] = randomNumber;
    }
}

bool checkRange(int min, int max)
{
    bool status(true);
    if (min < 0 && max > 255)
    {
        status = false;
        throw std::range_error("MIN or MAX value is out of range");
    }

    return status;
}