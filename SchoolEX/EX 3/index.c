#include <stdio.h>
#include <stdbool.h>

#define PERSONAL_NUMBER_YEAR_LENGTH 5      // The length of the first part of the Personal Number
#define PERSONAL_NUMBER_UNIQ_FOUR_LENGTH 3 // The length of the second part of the Personal Number (Four Uniq Digits)
#define PERSONAL_NUMER_LENGTH 9            // The length of the entire Personal Number

#define NULL_VALUE 0                       // Null value
#define DIGIT_DIVISION_NUMBER 10           // To get digits as well as using it in formulas
#define SECOND 2                           // To multiply every scend number by two

bool checkPersonalNumber(int *personalNumber, int personalNumberLength); // Return true if the Personal number is correct
void addToArray(int personalNumber, int personalUniqNumber, int *array); // Add both input numbers to an array

int main(void)
{
    int personummerYear, personummerUniqFour;  // User Input
    int personalNumber[PERSONAL_NUMER_LENGTH]; // Personal Number in form of array
    printf("Input a number in format [YYMMDD-NNNN]: ");

    if (SECOND == scanf("%d-%d", &personummerYear, &personummerUniqFour)) // To check if inputs are numbers
    {
        addToArray(personummerYear, personummerUniqFour, personalNumber);

        if (checkPersonalNumber(personalNumber, PERSONAL_NUMER_LENGTH)) // To check if personal number is correct
            (void)printf("Valid Personal Number! \n");
        else
            (void)printf("Invalid Personal Number! \n");
    }
    else
    {
        (void)printf("Invalid Input \n");
    }

    return 0;
}

void addToArray(int personalNumber, int personalUniqNumber, int *array)
{
    int index = PERSONAL_NUMER_LENGTH;

    while (personalUniqNumber) // Loop for adding Four Uniq numbers to array
    {
        array[index] = personalUniqNumber % DIGIT_DIVISION_NUMBER; // Adding remainder to the array
        personalUniqNumber /= DIGIT_DIVISION_NUMBER;        
        index--;
    }

    while (personalNumber) // Loop for adding Personal numbers to array
    {
        array[index] = personalNumber % DIGIT_DIVISION_NUMBER; // Adding remainder to the array
        personalNumber /= DIGIT_DIVISION_NUMBER;
        index--;
    }
}

bool checkPersonalNumber(int *personalNumber, int personalNumberLength)
{
    for (int i = NULL_VALUE; i <= personalNumberLength; i += SECOND) // Loop throw every second number
    {
        if (i != personalNumberLength)
        {
            personalNumber[i] *= SECOND;                    // Multiply Every Second number by 2
            if (personalNumber[i] >= DIGIT_DIVISION_NUMBER) // Check if number is in two digits
            {
                int tens, ones;
                tens = personalNumber[i] / DIGIT_DIVISION_NUMBER; // Getting the first digits of two digit number 
                ones = personalNumber[i] % DIGIT_DIVISION_NUMBER; // Getting the second digits of two digit number 
                personalNumber[i] = tens + ones; // Add two digits together and put them in array
            }
        }
        else
            break;
    }

    int sum = NULL_VALUE; // Temporary sum value
    for (int i = NULL_VALUE; i <= personalNumberLength; i++)
    {
        if (i != personalNumberLength)
        {
            sum += personalNumber[i]; // adding all numbers except last from array together into sum
        }
        else
            break;
    }

    sum = (DIGIT_DIVISION_NUMBER - (sum % DIGIT_DIVISION_NUMBER)) % DIGIT_DIVISION_NUMBER; // calculation to get last digit of Four Uniq digits of personal number
    return (sum == personalNumber[personalNumberLength]) ? true : false;
}