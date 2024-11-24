#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

#define MIN_AMOUNT_OF_BITS 1
#define MAX_AMOUNT_OF_BITS 8
#define REDUNDANCE_LENGTH 16 // In digits

#define BUFFER 100

#define POLYNOMIAL "1100010110011001" // Testing binary for corruption

char *charToBinary(const char *string, const int length);           // turns char string to binary char
char *addTwoByteRedundancy(char *string, const int length);         // adding redundancy to binary char
uint64_t charBinaryToDecimal(const char *binary, const int length); // it turns binary number into a unit64_t (unsigned long long int) number
int getRandomNumber(int min, int max);                              // Creates a random number (only used in corrupting the user input)

int main(void)
{
    char userInputString[BUFFER]; // User Input
    char corruptedString[BUFFER]; // Corrupted User Input

    (void)printf("Enter a word: ");
    (void)scanf("%s", userInputString);

    if (strlen(userInputString) <= MIN_AMOUNT_OF_BITS){
        (void)printf("Insufficent amount of bits!");
        return 1;
    }
        
    for (size_t i = 0; i < BUFFER; i++) // Corrupting random line of user input
    {
        corruptedString[i] = userInputString[i];
        if (i == getRandomNumber(0, strlen(userInputString)))
            corruptedString[i] = '!';
    }

    char *binaryChar = charToBinary(userInputString, strlen(userInputString) * MAX_AMOUNT_OF_BITS);
    binaryChar = addTwoByteRedundancy(binaryChar, strlen(binaryChar));

    char *corruptedBinaryChar = charToBinary(corruptedString, strlen(corruptedString) * MAX_AMOUNT_OF_BITS);
    corruptedBinaryChar = addTwoByteRedundancy(corruptedBinaryChar, strlen(corruptedBinaryChar));

    uint64_t decimalChar = charBinaryToDecimal(binaryChar, strlen(binaryChar));
    uint64_t corruptedDecimalChar = charBinaryToDecimal(corruptedBinaryChar, strlen(corruptedBinaryChar));
    uint64_t checkDecimalChar = charBinaryToDecimal(POLYNOMIAL, strlen(POLYNOMIAL));

    int mod = decimalChar % checkDecimalChar; // Formula for getting them mode from user Input string(decimal form) and POLYNOMIAL(decimal form)
    uint64_t newDecimalChar = corruptedDecimalChar + (checkDecimalChar - mod); // Adding the different to newDecimal

    if (newDecimalChar % checkDecimalChar == 0)
        (void)printf("Word [%s] is not corrupted!\n", corruptedString);
    else
        (void)printf("Word ['%s'] is corrupted! \nOriginal word was ['%s']\n", corruptedString, userInputString);

    free(binaryChar);
    free(corruptedBinaryChar);

    return 0;
}

char *charToBinary(const char *string, const int length)
{
    char *binaryString = (char *)malloc(length * sizeof(char));
    for (int i = 0; string[i] != '\0'; i++)
    {
        char tempBinary[MAX_AMOUNT_OF_BITS + 1];
        for (int j = MAX_AMOUNT_OF_BITS; j >= 0; j--)
            tempBinary[MAX_AMOUNT_OF_BITS - j] = (string[i] & (1 << j)) ? '1' : '0';

        tempBinary[MAX_AMOUNT_OF_BITS] = '\0';
        strcat(binaryString, tempBinary);
    }

    return binaryString;
}

char *addTwoByteRedundancy(char *string, const int length)
{
    int redundantLength = length + REDUNDANCE_LENGTH;
    char *temp = (char *)realloc(string, redundantLength * sizeof(char));

    for (size_t i = length; i < redundantLength; i++)
        temp[i] = '0';

    return temp;
}

uint64_t charBinaryToDecimal(const char *binary, const int length)
{
    uint64_t returnDecimal = 0;
    for (int i = 0; i < length; i++)
    {
        returnDecimal <<= 1;
        if ((binary[i] - '0') == 1)
            returnDecimal += (binary[i] - '0');
    }

    return returnDecimal;
}

int getRandomNumber(int min, int max)
{
    unsigned int seed = time(0);
    int rd_num = rand_r(&seed) % (max - min + 1) + min;
    return rd_num;
}