#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

/**
 * @brief A program to check for Personnummer validation. Takes in numbers and the calc is done over 10 digits, a dash is also able to be taken. But in an else if statement it is ignored.
 * the last digit is a control digit to check/validate.
 * 
 */

#define BUFFER 12

// Prototypes below
// validate card, take pointer of the chars.
bool validateNum(char *perNum);

int main()
{
    char userInput[BUFFER];
    printf("Input a personnummer in format YYMMDD-NNNN:\n");
    scanf(" %s", userInput);

    printf("Personnummer is: %s\nAnd its a %s", userInput, validateNum(userInput) ? "Valid number" : "Invalid number!");

    return 0;
}

// return false for a wrong number, return true for correct number.
bool validateNum(char *perNum)
{
    int length = 0; // Length of the personnummer.
    // total after everything is done.
    int total = 0;
    // Luhn Algorithm needs this. for determining position parity.
    int oddOrEven = 0;
    // checking every char, to find the length, only the digits will add 1 to length.

    for (int i = 0; perNum[i] != '\0'; i++)
    {
        if (isdigit(perNum[i]))//check every number, if its a digit, +1, OR if its not a digit AND not a dash(-) return false/wrong format.
        {
            length++;
        }
        else if (perNum[i] != '-')
        {
            printf("\nWrong format!\n");
            return false;
        }
        
    }

    if (length != 10)
    {
        return false;
    }
    

    oddOrEven = length % 2;
    int position = 0; // numbers position indicater.
    for (int i = 0; perNum[i] != '\0'; i++)
    {
        if (!isdigit(perNum[i]))
        {
            continue; // perNum[i] will go to the next step/i++. skiping this iteration. Because the perNum[i] is pointing/at position where it is not a number, basically a dash.
        }
        // else  { }
        int numHolder = perNum[i] - '0'; // hold the number, and turn from char into an integer.

        // Because of luhn algorithm, we haveto multiply every 2 number. So we multiply by 2. 
        if (position % 2 == oddOrEven)
        {
            numHolder *= 2;
            if (numHolder > 9) // If the number ismore than 9, - 9 the number to its self.
            {
                numHolder -= 9;
            }
        }
        total += numHolder;
        position++;
    }

    //if the the total modulus to 10 returns 0 everything is correct. The number is valid.
    return total % 10 == 0;
   
}
