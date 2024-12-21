#include <iostream>
#include <cstdlib>
#include <stdint.h>
#include "bufferArray.h"

uint8_t *Buffer::createArray(int size)
{
    uint8_t *arr = new (std::nothrow) uint8_t[size];
    return arr;
}

bool Buffer::clearArr(uint8_t *arr)
{
    bool status = false;

    if (arr != nullptr)
    {
        delete[] arr;
        arr = nullptr;
        status = true;
    }
    else
    {
        std::cout << "Error! No array found!" << std::endl;
        status = false;
    }

    return status;
}

bool Buffer::push(int msgLength, int index, uint16_t msg, uint8_t *arr)
{
    bool status = true;

    if (arr == nullptr)
    {
        status = false;
        exit(0);
    }

    if (msgLength <= 0 || msgLength > BUFFER_IN_BITS)
    {
        std::cerr << "Invalid index or message length" << std::endl;
        status = false;
        exit(0);
    }

    for (int i = 0; i < msgLength; i++)
    {
        arr[index + i] = (msg >> MSG_SHIFT_FORMULA(msgLength, i)) & 1;
    }

    return status;
}

uint16_t Buffer::toBinary(int msgInt, float msgFloat)
{
    uint16_t binary;

    if (msgInt > 0)
    {
        binary = static_cast<uint16_t>(msgInt);
    }
    else if (msgFloat > 0)
    {
        binary = static_cast<uint16_t>(msgFloat / PRECISION);
    }
    else
    {
        binary = 0;
    }

    return binary;
}

float Buffer::pull(int msgLength, int index, uint8_t *arr, bool isFloat)
{
    uint16_t msg = 0;

    if (arr == nullptr)
    {
        std::cout << "Error! No array found!" << std::endl;
        exit(0);
    }

    for (int i = 0; i < msgLength; i++)
    {
        msg |= (arr[index + i] << MSG_SHIFT_FORMULA(msgLength, i));
    }

    return isFloat ? (static_cast<float>(msg) * PRECISION) : static_cast<float>(msg);
}
