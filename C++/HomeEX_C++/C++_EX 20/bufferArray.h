/**
 * @file bufferArray.h
 * @author Lazar Roksandic
 * @brief Library to store binary messages inside 3 bit array
 * @version 0.1
 * @date 2024-12-20
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef BUFFER_ARRAY_H
#define BUFFER_ARRAY_H

#include <stdint.h>

namespace Buffer
{
#define BUFFER 3          // Buffer in byte
#define BUFFER_IN_BITS 24 // Buffer in bits

#define PRECISION 0.01f // Precision used in converting the float to int or vice versa

#define MSG_SHIFT_FORMULA(length, position) ((length) - (position) - 1) // Formula for bit shifting

    /**
     * @brief Create a Array object
     *
     * @param size that you want to give to array in memory (In byte)
     * @return uint8_t* array of given size
     */
    uint8_t *createArray(int size);

    /**
     * @brief Push the message (in binary) to array
     *
     * @param msgLength is a length of a message
     * @param index is a place where to put it in array
     * @param msg you want to push to array
     * @param arr you want to write the message in
     * @return true if push is successfully done or false if arr is null or there is no place to put msg
     */
    bool push(int msgLength, int index, uint16_t msg, uint8_t *arr);

    /**
     * @brief A function to get a message from a array
     *
     * @param msgLength length of a message you want to pull
     * @param index start position in array of a message
     * @param arr array that stores the messages
     * @param isFloat if the message is in a float format
     * @return float if the message is a float variable or int if its not
     */
    float pull(int msgLength, int index, uint8_t *arr, bool isFloat = false);

    /**
     * @brief Function to turn message to a binary
     *
     * @param msgInt message as a int variable
     * @param msgFloat message as a float variable
     * @return uint16_t in binary
     */
    uint16_t toBinary(int msgInt = 0, float msgFloat = 0);

    /**
     * @brief Function to clear the memory of a array
     *
     * @param arr you want to clear
     * @return true if cleared successfully or false if arr is null already
     */
    bool clearArr(uint8_t *arr);
}

#endif // !BUFFER_ARRAY_H