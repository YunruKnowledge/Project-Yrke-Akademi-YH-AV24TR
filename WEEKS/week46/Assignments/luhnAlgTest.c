#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

#define BUFFER 12

// Prototypes below
// validate card, take pointer of chars.
bool validateNum(char *perNum);

int main()
{
    /*
    char *userInput = "0201034915";
    printf("Input a personnummer:\n");
    scanf(" %s", &userInput);

    printf("Personnummer is: %s\nAnd its a %s", userInput, validateNum(userInput) ? "Valid number" : "Invalid number!");

    return 0;
*/
    char userInput[BUFFER]; // buffer to hold personnummer 10 number and if dash.
    printf("Enter personnummer (YYMMDDNNNN or YYMMDD-NNNN): ");
    scanf("%11s", userInput);

    if (validateNum(userInput)) // validate returns true
        printf("Personnummer is: Valid number!\n");
    else // else return false
    {
        printf("Personnummer is: Invalid number!\n");
    }

    return 0;
}

// return false for a wrong number, return true for correct number.
bool validateNum(char *perNum)
{
    int length = 0; // Length of the personnummer.
    while (perNum[length] != '\0')
    {
        // To find the length of the string/input, add 1 to the length until we find the Null char that ends or show that the string is ended.
        length++;
    }

    int numHolder = 0;
    // total.
    int total = 0;
    // Luhn Algorithm needs this. To know if we multiply the number or avoid.
    int oddOrEven = length % 2;

    // a loop to start from right digit, and end at the leftmost number, which most likely is a 1 or 2.
    for (int i = length - 1; i >= 0; i--)
    {

        // check if the num we look at is a number with a library.
        if (isdigit(perNum[i]) == false)
        {
            return false;
        }
        else if (perNum[i] == '-')
        {
            continue;
        }

        // converts the number from string to a INTEGER!
        numHolder = perNum[i] - '0';

        // if the i mod 2 is equal to oddOrEven, *= numHolder by 2.
        // and if numHolder is more than 9, -= oddOrEven by 9.
        if (i % 2 == oddOrEven)
        {
            numHolder *= 2;

            if (numHolder > 9)
            {
                numHolder -= 9;
            }
        }
        total += numHolder;
    }

    // if (total % 10 == 0)
    // {
    //     return true;
    // }
    return total % 10 == 0;
}
