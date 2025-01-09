#include <iostream>
#include <cstdlib>
#include <stdint.h>
#include "buffer.h"

uint8_t *Buffer::createArray(int size)
{
    uint8_t *arr = new (std::nothrow) uint8_t[size];
    return arr;
}

bool Buffer::clearArr(uint8_t *arr)
{
    bool status = false;

    if (Buffer::checkArr(arr))
    {
        delete[] arr;
        arr = nullptr;
        status = true;
    }
    else
    {
        status = false;
    }

    return status;
}

bool Buffer::Int::push(int msgLength, int index, uint8_t msg, uint8_t *arr)
{
    bool status = true;

    if (!Buffer::checkArr(arr))
    {
        status = false;
    }
    else
    {
        if (msgLength <= 0 || msgLength > BUFFER_IN_BITS)
        {
            std::cerr << "Invalid index or message length" << std::endl;
            status = false;
        }
        else
        {
            uint8_t msgBin = Buffer::Int::toBinary(msg);

            for (int i = 0; i < msgLength; i++)
            {
                arr[index + i] = (msgBin >> MSG_SHIFT_FORMULA(msgLength, i)) & 1;
            }
        }
    }

    return status;
}

bool Buffer::Float::push(int msgLength, int index, float msg, uint8_t *arr)
{
    bool status = true;

    if (!Buffer::checkArr(arr))
    {
        status = false;
    }
    else
    {
        if (msgLength <= 0 || msgLength > BUFFER_IN_BITS)
        {
            std::cerr << "Invalid index or message length" << std::endl;
            status = false;
        }
        else
        {
            uint16_t msgBin = Buffer::Float::toBinary(msg);

            for (int i = 0; i < msgLength; i++)
            {
                arr[index + i] = (msgBin >> MSG_SHIFT_FORMULA(msgLength, i)) & 1;
            }
        }
    }

    return status;
}

int Buffer::Int::pull(int msgLength, int index, uint8_t *arr)
{
    uint8_t msg = 0;

    if (Buffer::checkArr(arr))
    {
        for (int i = 0; i < msgLength; i++)
        {
            msg |= (arr[index + i] << MSG_SHIFT_FORMULA(msgLength, i));
        }
    }

    return static_cast<int>(msg);
}

float Buffer::Float::pull(int msgLength, int index, uint8_t *arr)
{
    uint16_t msg = 0;

    if (Buffer::checkArr(arr))
    {
        for (int i = 0; i < msgLength; i++)
        {
            msg |= (arr[index + i] << MSG_SHIFT_FORMULA(msgLength, i));
        }
    }

    return static_cast<float>(msg) * PRECISION;
}

uint8_t Buffer::Int::toBinary(int msgInt)
{
    return static_cast<uint16_t>(msgInt);
}

uint16_t Buffer::Float::toBinary(float msgFloat)
{
    return static_cast<uint16_t>(msgFloat / PRECISION);
}

bool Buffer::checkArr(uint8_t *arr)
{
    bool status = false;

    if (arr == nullptr)
    {
        std::cout << "Error! No array found!" << std::endl;
        status = false;
    }
    else
    {
        status = true;
    }

    return status;
}