#include <stdio.h>
#include <stdbool.h>

#define PERSONAL_NUMBER_YEAR_LENGTH 5      // The length of the first part of the Personal Number
#define PERSONAL_NUMBER_UNIQ_FOUR_LENGTH 3 // The length of the second part of the Personal Number (Four Uniq Digits)
#define PERSONAL_NUMER_LENGTH 9            // The length of the entire Personal Number

#define NULL_VALUE 0             // Null value
#define DIGIT_DIVISION_NUMBER 10 // To get digits as well as using it in formulas
#define SECOND 2                 // To multiply every scend number by two

#define MAX_AMOUNT_OF_MONTH_IN_A_YEAR 12 // Number of month
#define MAX_AMOUNT_OF_DAY_IN_A_MONTH 31  // Number of days

#define TEN_MULTIPLAYER 10 // Turning first number to double digits

// Return true if the Personal number is correct
bool checkPersonalNumber(int *personalNumber, int personalNumberLength);
// Checking the amount of month/year (bool true for month and bool false for year)
bool checkYear(int *personalNumber, int personalNumberLength);
// Add both input numbers to an array
void addToArray(int personalNumber, int personalUniqNumber, int *array);

int main(void)
{
    int personummerYear, personummerUniqFour;  // User Input
    int personalNumber[PERSONAL_NUMER_LENGTH]; // Personal Number in form of array
    printf("Input a number in format [YYMMDD-NNNN]: ");

    if (SECOND == scanf("%d-%d", &personummerYear, &personummerUniqFour)) // To check if inputs are numbers
    {
        addToArray(personummerYear, personummerUniqFour, personalNumber);
        if (checkYear(personalNumber, PERSONAL_NUMBER_YEAR_LENGTH))
        {
            if (checkPersonalNumber(personalNumber, PERSONAL_NUMER_LENGTH)) // To check if personal number is correct
                (void)printf("Valid Personal Number! \n");
            else
                (void)printf("Invalid Personal Number! \n");
        }
        else
        {
            (void)printf("Invalid Personal Number! \n");
        }
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
                personalNumber[i] = tens + ones;                  // Add two digits together and put them in array
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

bool checkYear(int *personalNumber, int personalNumberLength)
{
    bool returnBool;
    bool month_year = false;                                    // For if checking year/month
    for (int i = SECOND; i < personalNumberLength; i += SECOND) // Starts from second number in array
    {
        int tempTens = (personalNumber[i] * TEN_MULTIPLAYER) + personalNumber[i + 1]; // adding number i from array with next one
        if (tempTens > MAX_AMOUNT_OF_MONTH_IN_A_YEAR && !month_year)     // Check for year
        {
            returnBool = false;
        }
        else if (tempTens > MAX_AMOUNT_OF_DAY_IN_A_MONTH && month_year) // Check for month
        {
            returnBool = false;
        }
        else
        {
            month_year = true;
            returnBool = true;
        }
    }
    return returnBool;
}