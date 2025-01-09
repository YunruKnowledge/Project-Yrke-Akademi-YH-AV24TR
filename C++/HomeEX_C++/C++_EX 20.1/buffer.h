#ifndef BUFFER_H
#define BUFFER_H

#include <cstdint>

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

    namespace Int
    {
        /**
         * @brief Push the message (in binary) to array
         *
         * @param msgLength is a length of a message
         * @param index is a place where to put it in array
         * @param msg you want to push to array
         * @param arr you want to write the message in
         * @return true if push is successfully done or false if arr is null or there is no place to put msg
         */
        bool push(int msgLength, int index, uint8_t msg, uint8_t *arr);

        /**
         * @brief A function to get a message from a array
         *
         * @param msgLength length of a message you want to pull
         * @param index start position in array of a message
         * @param arr array that stores the messages
         * @return message in int format
         */
        int pull(int msgLength, int index, uint8_t *arr);

        /**
         * @brief Function to turn message to a binary
         *
         * @param msgInt message as a int variable
         * @return uint8_t in binary
         */
        uint8_t toBinary(int msgInt = 0);
    }

    namespace Float
    {
        /**
         * @brief Push the message (in binary) to array
         *
         * @param msgLength is a length of a message
         * @param index is a place where to put it in array
         * @param msg you want to push to array
         * @param arr you want to write the message in
         * @return true if push is successfully done or false if arr is null or there is no place to put msg
         */
        bool push(int msgLength, int index, float msg, uint8_t *arr);

        /**
         * @brief A function to get a message from a array
         *
         * @param msgLength length of a message you want to pull
         * @param index start position in array of a message
         * @param arr array that stores the messages
         * @return message in float format
         */
        float pull(int msgLength, int index, uint8_t *arr);

        /**
         * @brief Function to turn message to a binary
         *
         * @param msgFloat message as a float variable
         * @return uint16_t in binary
         */
        uint16_t toBinary(float msgFloat = 0);
    }

    /**
     * @brief Check if array exist
     * 
     * @param arr you want to check
     * @return true if array is not a nullptr
     * @return false if array is a nullptr
     */
    bool checkArr(uint8_t *arr);

    /**
     * @brief Function to clear the memory of a array
     *
     * @param arr you want to clear
     * @return true if cleared successfully or false if arr is null already
     */
    bool clearArr(uint8_t *arr);
}

#endif // !BUFFER_H