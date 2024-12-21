#include <cassert>
#include <iostream>
#include <cstdlib>
#include <stdint.h>
#include "bufferArray.h"

// Example Numbers
#define MSG 42
#define MSG_LENGTH 7
#define MSG_INDEX 4

int main(void)
{
    uint8_t *arr = Buffer::createArray(BUFFER);

    assert(Buffer::push(MSG_LENGTH, MSG_INDEX, Buffer::toBinary(MSG), arr));
    std::cout << "Test Passed! Msg Successfully Pushed!" << std::endl;

    assert(MSG == (int)(Buffer::pull(MSG_LENGTH, MSG_INDEX, arr)));
    std::cout << "Test Passed! Msg Successfully Pulled!" << std::endl;

    std::cout << "Pulled Message is: " << (int)(Buffer::pull(MSG_LENGTH, MSG_INDEX, arr)) << std::endl;

    assert(Buffer::clearArr(arr));
    std::cout << "Test Passed! Array Successfully Cleared!" << std::endl;

    return 0;
}
