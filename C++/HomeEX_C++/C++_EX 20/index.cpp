#include <iostream>
#include <cstdlib>
#include <stdint.h>
#include "bufferArray.h"


int main(void)
{
    uint8_t *arr = Buffer::createArray(BUFFER);

    uint8_t msg = 42;
    uint8_t msgLength = 7;
    uint8_t msgIndex = 0;

    Buffer::push(msgLength, msgIndex, Buffer::toBinary(msg), arr);
    std::cout << (int)(Buffer::pull(msgLength, msgIndex, arr)) << std::endl;

    float msgFloat = 7.5f;
    msgLength = 16;
    msgIndex = 7;

    Buffer::push(msgLength, msgIndex, Buffer::toBinary(0, msgFloat), arr);
    std::cout << (float)(Buffer::pull(msgLength, msgIndex, arr, true)) << std::endl;

    Buffer::clearArr(arr);
    return 0;
}
