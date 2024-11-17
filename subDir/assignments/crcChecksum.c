/**
 * @file crcChecksum.c
 * @author Khanh Tran (88000687+YunruKnowledge@users.noreply.github.com)
 * @brief An effort to implement and run a test of CRC based on the videos
 * provided.
 * @version 0.9
 * @date 2024-11-17
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define POLYNOM 0xC599
#define POLYNOM_APPEND_AMOUNT 15
#define MAX 13
#define MIN 1
#define BITS_IN_BYTE 8
#define HIGH_BIT 0b1
#define ARRAY_START_COMPENSATION 1
#define VERIFY_FALSE 1
#define VERIFY_ERROR 2
#define EXTRA_NULL_TERM 1

static uint8_t *simulateBinary(const uint8_t *_message);
static uint16_t writeCRC(uint8_t *_message_array, const size_t _message_size);
static uint8_t verifyCRC(uint8_t *_message_array, const size_t _message_size);
static uint8_t *decodeMessageBinary(const uint8_t *_message_array,
                                    const size_t _array_size);
static void printVerificationMessage(const uint8_t _code);
static uint8_t checkStringLength(const uint8_t *_string);

/**
 * @brief Program to append CRC and check for errors.
 * Received message is uint8_t, max 14 elements.
 * Uses CRC-15 CAN. (C599)
 * Processes first to last elements, LSB to MSB.
 * Uses bitshifting for conversion, read etc.
 *
 * @return int
 */
int main(void) {
  const uint8_t _recievedString[MAX] = "Faulty?";
  uint8_t *_decodedMessage;

  // Convert
  uint8_t *_messageArray = simulateBinary(_recievedString);
  const size_t _arraySize =
      sizeof(uint8_t) * BITS_IN_BYTE * checkStringLength(_recievedString) +
      POLYNOM_APPEND_AMOUNT;

  _decodedMessage = decodeMessageBinary(_messageArray, _arraySize);
  printf("Received and encoded: \"%s\"\n", _decodedMessage);
  if (_decodedMessage != NULL) {
    free(_decodedMessage);
    _decodedMessage = NULL;
  }

  // Apply CRC
  printf("Applying CRC...\n");
  uint16_t _crcValue = writeCRC(_messageArray, _arraySize);
  printf("Appended: 0x%x\n", _crcValue);

  // Verifying
  printf("Verifying CRC...\n");
  uint8_t _verify = verifyCRC(_messageArray, _arraySize);
  printVerificationMessage(_verify);

  // Add errors
  printf("Adding errors... (XOR flips)\n"); // *Flips only the first letter :P
  _messageArray[2] = _messageArray[2] ^ 1;
  _messageArray[8] = _messageArray[7] ^ 1;
  _messageArray[5] = _messageArray[5] ^ 1;

  printf("Message is now:");
  _decodedMessage = decodeMessageBinary(_messageArray, _arraySize);
  printf(" %s\n", decodeMessageBinary(_messageArray, _arraySize));
  if (_decodedMessage != NULL) {
    free(_decodedMessage);
    _decodedMessage = NULL;
  }

  // Verify with error
  printf("Verifying CRC...\n");
  _verify = verifyCRC(_messageArray, _arraySize);
  printVerificationMessage(_verify);

  if (_messageArray != NULL) {
    free(_messageArray);
    _messageArray = NULL;
  }

  return 0;
}

/**
 * @brief Converts a uint8 string into a array of bits. Goes through each array
 * element left to right, every byte right to left (LSB to MSB)
 *
 * @param _message
 * @return uint8_t*
 */
static uint8_t *simulateBinary(const uint8_t *_message) {
  // E.g. 8 bits for each letter, plus 15 bits for polynomial.
  const size_t _tempSize =
      sizeof(uint8_t) * BITS_IN_BYTE * checkStringLength(_message) +
      POLYNOM_APPEND_AMOUNT;
  // Allocates temp for binary 1 and 0s of message.
  uint8_t *_temp = (uint8_t *)malloc(_tempSize);
  uint8_t _msgIndex = 0, _index = 0;

  if (_temp != NULL) {
    // Set message as bits into _temp.
    while (_index < _tempSize) {
      _temp[_index] = 0;

      // For every byte, jump to next word.
      if (_index % BITS_IN_BYTE == 0 && _index != 0) {
        _msgIndex++;
      }

      // Push bits into _temp.
      if (_msgIndex < checkStringLength(_message)) {
        _temp[_index] =
            ((_message[_msgIndex] >> (_index % BITS_IN_BYTE)) & HIGH_BIT);
      }

      _index++;
    }
  } else {
    (void)printf("%i:FETAL ERROR, MEMORY ALLOCATION FAILED. RETURN NULL",
                 __LINE__);
  }

  return _temp;
}

/**
 * @brief Makes a local array clone, runs the CRC through the clone, apply the
 * CRC to the original array. Returns the CRC value, 0 if error.
 *
 * @param _message_array
 * @param _message_size
 * @return uint16_t
 */
static uint16_t writeCRC(uint8_t *_message_array, const size_t _message_size) {
  uint8_t *_pendingCRCTemp = (uint8_t *)malloc(_message_size);
  uint16_t _crcValue = 0;
  const size_t _lengthWithoutCRC = _message_size - POLYNOM_APPEND_AMOUNT;

  if (_pendingCRCTemp != NULL) {
    // Clone for CRC.
    for (size_t i = 0; i < _message_size; i++) {
      _pendingCRCTemp[i] = _message_array[i];
    }

    // For each "bit"(1 and 0s) of the message array.
    // Skip 0s. Do polynumial XOR to bits.
    for (size_t a = 0; a < _lengthWithoutCRC; a++) {
      if (_pendingCRCTemp[a] & HIGH_BIT) {
        for (size_t b = 0; b < POLYNOM_APPEND_AMOUNT; b++) {
          if (POLYNOM & (1 << b)) {
            _pendingCRCTemp[a + b] ^= 1;
          }
        }
      }
    }

    // Write CRC to message array.
    for (size_t i = _lengthWithoutCRC; i < _message_size; i++) {
      _message_array[i] = _pendingCRCTemp[i];
    }

    // Copy final CRC value to variable for return. *from right to left
    for (size_t i = 1; i <= POLYNOM_APPEND_AMOUNT; i++) {
      _crcValue |= (((uint16_t)_pendingCRCTemp[_message_size - i] & HIGH_BIT)
                    << (i - ARRAY_START_COMPENSATION));
    }

    free(_pendingCRCTemp);
    _pendingCRCTemp = NULL;
  } else {
    _crcValue = 0;
    (void)printf("%i:FETAL ERROR, MEMORY ALLOCATION FAILED. RETURN ZERO",
                 __LINE__);
  }

  return _crcValue;
}

/**
 * @brief Makes a local clone, and applies the CRC XOR and check if final CRC is
 * only zeros. Returns 0 if valid, other numbers are for invalids or errors.
 *
 * @param _message_array
 * @param _message_size
 * @return uint8_t
 */
static uint8_t verifyCRC(uint8_t *_message_array, const size_t _message_size) {
  uint8_t *_pendingCRCTemp = (uint8_t *)malloc(_message_size);
  uint8_t _isInvalid = 0;
  const size_t _lengthWithoutCRC = _message_size - POLYNOM_APPEND_AMOUNT;

  if (_pendingCRCTemp != NULL) {
    // Clone for CRC.
    for (size_t i = 0; i < _message_size; i++) {
      _pendingCRCTemp[i] = _message_array[i];
    }

    // For each "bit"(1 and 0s) of the message.
    // Skip 0s. Do polynumial XOR to bits.
    for (size_t a = 0; a < _lengthWithoutCRC; a++) {
      if (_pendingCRCTemp[a] & HIGH_BIT) {
        for (size_t b = 0; b < POLYNOM_APPEND_AMOUNT; b++) {
          if (POLYNOM & (HIGH_BIT << b)) {
            _pendingCRCTemp[a + b] ^= HIGH_BIT;
          }
        }
      }
    }

    for (size_t i = _message_size - POLYNOM_APPEND_AMOUNT; i < _message_size;
         i++) {
      if (_pendingCRCTemp[i] & HIGH_BIT) {
        _isInvalid = VERIFY_FALSE;
      }
    }

    free(_pendingCRCTemp);
    _pendingCRCTemp = NULL;
  } else {
    _isInvalid = VERIFY_ERROR;
    (void)printf("%i:FETAL ERROR, MEMORY ALLOCATION FAILED. RETURN CODE TWO",
                 __LINE__);
  }

  return _isInvalid;
}

/**
 * @brief Reads simulated array and returns an array with normal values for
 * using.
 *
 * @param _message_array
 * @param _array_size
 * @return uint8_t*
 */
static uint8_t *decodeMessageBinary(const uint8_t *_message_array,
                                    const size_t _array_size) {
  const size_t _charAmount =
      (_array_size - POLYNOM_APPEND_AMOUNT) / BITS_IN_BYTE;
  uint8_t *_string = (uint8_t *)malloc(_charAmount + EXTRA_NULL_TERM);

  if (_string != NULL) {

    for (size_t a = 0; a < _charAmount; a++) {
      uint8_t _char = 0;

      for (size_t b = 0; b < BITS_IN_BYTE; b++) {
        size_t _bitIndex = a * BITS_IN_BYTE + b;
        _char |= (_message_array[_bitIndex] << b);
      }
      _string[a] = _char;
    }

    _string[_charAmount] = '\0';

  } else {
    (void)printf("%i:FETAL ERROR, MEMORY ALLOCATION FAILED. RETURN NULL",
                 __LINE__);
    _string = NULL;
  }

  return _string;
}

/**
 * @brief Small function to printf out messages based on the return of
 * verifyCRC( ).
 *
 * @param _code
 */
static void printVerificationMessage(const uint8_t _code) {
  if (!_code) {
    (void)printf("Polynomial Matched! Valid string.\n");
  } else if (_code == VERIFY_FALSE) {
    (void)printf("CRC did not match zero, potential corrupted string.\n");
  } else {
    (void)printf(
        "Verification failed. (Does not mean string was valid or invalid.)\n");
  }
}

/**
 * @brief Loop and check for '\\0' and '\\n' to end for string length.
 *
 * @param _string
 * @return uint8_t
 */
static uint8_t checkStringLength(const uint8_t *_string) {
  uint8_t _index = 0;
  while (_string[_index]) {
    if (_string[_index] == '\0' || _string[_index] == '\n') {
      break;
    } else {
      _index++;
    }
  }

  return _index;
}
