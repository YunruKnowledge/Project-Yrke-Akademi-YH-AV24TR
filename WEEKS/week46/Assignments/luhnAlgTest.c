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
    char userInput[BUFFER];
    printf("Input a personnummer:\n");
    scanf(" %s", userInput);

    printf("Personnummer is: %s\nAnd its a %s", userInput, validateNum(userInput) ? "Valid number" : "Invalid number!");

    return 0;
}

// return false for a wrong number, return true for correct number.
bool validateNum(char *perNum)
{
    int length = 0; // Length of the personnummer.
    // while (perNum[length] != '\0')
    // {
    //     // To find the length of the string/input, add 1 to the length until we find the Null char that ends or show that the string is ended.
    //     length++;
    // }

    // int numHolder = 0;
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
    /*
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

        */
}
