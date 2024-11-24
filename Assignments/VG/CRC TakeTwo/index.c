#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define POLYNOMIAL 0xC599        // CRC-15 Polynomial (1100010110011001)
#define CRC_INITIAL_VALUE 0xFFFF // Initial CRC value

#define MESSAGE_MAX_LENGTH 14 // Maximum message length
#define MESSAGE_MIN_LENGTH 1  // Minimum message length

#define BIT_SIZE 8           // Size of a bit
#define PROCESS_LENGTH 7     // Amount of bits to shift
#define REDUNDANCY_LENGTH 14 // Amount of zeros added

// Function to compute the CRC-15 checksum
static uint16_t calculateCRC(const uint8_t *message, size_t length);
// Function to verify if the CRC of the received message matches the expected CRC
static int verifyCRC(const uint8_t *message, size_t length, uint16_t expected_crc);
// Function to corrupt a message by flipping one random bit
static void simulateCorruption(uint8_t *message, size_t length);

int main(void)
{
    char inputMessage[MESSAGE_MAX_LENGTH + 1];
    
    (void)printf("Enter a message (max 14 characters): ");
    fgets(inputMessage, sizeof(inputMessage), stdin);

    size_t inputLength = strlen(inputMessage);
    if (inputMessage[inputLength - 1] == '\n')
    {
        inputMessage[inputLength - 1] = '\0';
        inputLength--;
    }

    if (inputLength < MESSAGE_MIN_LENGTH || inputLength > MESSAGE_MAX_LENGTH)
    {
        (void)printf("Error: Message length must be between %d and %d characters.\n", MESSAGE_MIN_LENGTH, MESSAGE_MAX_LENGTH);
        return 1;
    }

    uint8_t message[inputLength];
    for (size_t i = 0; i < inputLength; i++)
        message[i] = (uint8_t)inputMessage[i]; // Convert each char to uint8_t

    uint16_t originalCRC = calculateCRC(message, inputLength); // Calculate the CRC for the original message
    (void)printf("Original message CRC: 0x%X\n", originalCRC);

    uint8_t corruptedMessage[inputLength];             // Corrupt the message by changing the random val
    memcpy(corruptedMessage, message, inputLength);    // Copy original message to corrupted message
    simulateCorruption(corruptedMessage, inputLength); // Corrupt the message

    uint16_t corruptedCRC = calculateCRC(corruptedMessage, inputLength); // Calculate the CRC for the corrupted message
    (void)printf("Corrupted message CRC: 0x%X\n", corruptedCRC);

    if (verifyCRC(corruptedMessage, inputLength, originalCRC))
        (void)printf("Corrupted message passed the CRC check!\n");
    else
        (void)printf("Corrupted message failed the CRC check!\n");

    return 0;
}

static uint16_t calculateCRC(const uint8_t *message, size_t length)
{
    uint16_t crc = CRC_INITIAL_VALUE;
    for (size_t i = 0; i < length; i++)
    {
        uint8_t byte = message[i];
        for (int bit = 0; bit < BIT_SIZE; bit++)
        {
            uint16_t crc_bit = (crc >> REDUNDANCY_LENGTH) & 1;
            crc <<= 1;

            if (crc_bit ^ ((byte >> (PROCESS_LENGTH - bit)) & 1))
                crc ^= POLYNOMIAL;
        }
    }
    return crc & 0x7FFF;
}

static int verifyCRC(const uint8_t *message, size_t length, uint16_t expected_crc)
{
    uint16_t crc = calculateCRC(message, length);
    return crc == expected_crc;
}

static void simulateCorruption(uint8_t *message, size_t length)
{
    srand(time(NULL));

    size_t byte_index = rand() % length;
    size_t bit_index = rand() % BIT_SIZE;

    message[byte_index] ^= (1 << bit_index);
}
