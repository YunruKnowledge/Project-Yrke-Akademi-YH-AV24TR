#include <ctype.h>
#include <stdio.h>
#include <strings.h>

#define BUFFER 50

int GCD(const int numOne, const int numTwo);
int LCM(const int numOne, const int numTwo);
void *sortStringAlphabeticby(char *string, const unsigned int length);

int main(void)
{
    char stringArray[BUFFER] = {'j', 'A', 'z', 'X', 'a', 'd', 'b', 'N', 'm', 'v', 'Y'};

    (void)printf("%d\n", GCD(8, 12));

    sortStringAlphabeticby(stringArray, BUFFER);
    for (int i = 0; i < BUFFER; i++)
    {
        (void)printf("%c", stringArray[i]);
    }
    (void)printf("\n");
    
    return 0;
}

int GCD(const int numOne, const int numTwo)
{
    return (numOne * numTwo) / LCM(numOne, numTwo);
}

int LCM(const int numOne, const int numTwo)
{
    int returnVal = 0;
    for (int i = 0; i < (sizeof(int) * 8); i++)
    {
        if (returnVal)
            break;
        for (int j = 0; j < (sizeof(int) * 8); j++)
        {
            if (numOne * i == numTwo * j)
                returnVal = numOne * i;
            else if (numOne * i < numTwo * j)
                break;
        }
    }

    return returnVal;
}

void *sortStringAlphabeticby(char *string, const unsigned int length)
{
    int swap = 1;
    int temp;

    for (int i = 0; i < length && swap; i++)
    {
        swap = 0;
        for (int j = 0; j < (length - 1); j++)
        {
            if (tolower(string[j + 1]) < tolower(string[j]))
            {
                temp = string[j + 1];
                string[j + 1] = string[j];
                string[j] = temp;
                swap = 1;
            }
        }
    }
}