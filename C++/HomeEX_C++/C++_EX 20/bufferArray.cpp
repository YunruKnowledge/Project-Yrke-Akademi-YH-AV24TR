#include <iostream>
#include <cstdlib>
#include <stdint.h>
#include "bufferArray.h"

uint8_t *Buffer::createArray(int size)
{
    uint8_t *arr = new (std::nothrow) uint8_t[size];
    return arr;
}

void Buffer::clearArr(uint8_t *arr)
{
    delete[] arr;
    arr = nullptr;
}

void Buffer::push(int msgLength, int index, uint16_t msg, uint8_t *arr)
{
    if (msgLength <= 0 || msgLength > BUFFER_IN_BITS)
    {
        std::cerr << "Invalid index or message length" << std::endl;
        exit(0);
    }

    for (int i = 0; i < msgLength; i++)
    {
        arr[index + i] = (msg >> MSG_SHIFT_FORMULA(msgLength, i)) & 1;
    }
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

    for (int i = 0; i < msgLength; i++)
    {
        msg |= (arr[index + i] << MSG_SHIFT_FORMULA(msgLength, i));
    }

    return isFloat ? (static_cast<float>(msg) * PRECISION) : static_cast<float>(msg);
}
