

#include <stdio.h>
#include <string.h>
#include "e39Lib.h"

unsigned int gcd(unsigned int a, unsigned int b)
{

    // find GCD
    // Yani, b 0 olmadigi surece.
    // a ve b yi bol, arta kalan b ye ekle.
    // ve sonuc olarak, a ve b mod olunca, b nin degerini, a ya verip a yi return ediyorum.

    while (b != 0)
    {
        unsigned int temp = b; // temp will hold b

        // b is the remainder
        b = a % b;
        // temp or first value of b goes gets assigned to "a"
        a = temp;
    }
    printf("A is %i\n", a);

    return a; // the b that divided with the a int.
}

// 1. find the gcd value.
//  2. a * b, divide by the gcd value.
//  3. return the result.

unsigned int lcm(unsigned int a, unsigned int b)
{
    unsigned int gcdValue = gcd(a, b);

    unsigned int result = (a * b);
    result /= gcdValue;

    return result;
}

void sortString(char *str)
{

    printf("\n\tThe string will be printed below:\n");

    // for(int i = 0; i < 7; i++){
    //     printf("%c", str[i]);
    // }

    int n = strlen(str);
    int i, j;
    char temp;

//string len, eksi null
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)//n(8 example), minus the i(1 example), then to make it one position behind, -1
        {
            // prioritize uppercase letters
            if (str[j] >= 'A' && str[j] <= 'Z' && str[j + 1] >= 'a' && str[j + 1] <= 'z' && str[j] == str[j + 1] + 'a' - 'A')
            {
                // Swap positions
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
            else if (str[j] > str[j + 1])
            {
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }

    for (int a = 0; a < n; a++)
    {
        (void)printf("%c",str[a]);
    }
    
}

// if capital, int value is smaller by 32.
// if the campared number is smaller,which means +32,
//  i incrememnt the position variable by 1., and then i do a swap.

// How to swap the other letter?
//  If the value difference is more than 32, and less than 70. do the swap.

// I'll need 2 for loops, one to hold  the current position of the letter.
// and the second one to compare.
// I'll use pointer, so nothing returned.