/*

Description
Make a utility module to provide the following functionalities:

A function to get the greatest common divisor (gcd) of two unsigned integers greater than 0.
Example: the gcd of 8 and 12 is 4.

A function to get the least common multiple(lcm) of two unsigned integers greater than 0.
Example: the lcm of 4 and 6 is 12.

A function to sort a string in alphabetical order.
Example:
String: jsaNSHosAlPWnSJq
Sorted String: AaHJjlNnoPqSSssW
Make a test program to test the functions using assertion.

*/
#include <stdio.h>
#include <stdint.h>
#include "e39Lib.h"

int main(void)
{
    /*

        // find GCD
        // Yani, b 0 olmadigi surece.
        // a ve b yi bol, arta kalan b ye ekle.
        // ve sonuc olarak, a ve b mod olunca, b nin degerini, a ya verip a yi return ediyorum.
        int a = 7;
        int b = 12;

        while (b != 0)
        {
            uint_8 temp = b; // temp will hold b
            printf("B was %i\n", b);
            // b is the remainder
            b = a % b;
            printf("a mod b, is %i\n", b);
            // temp or first value of b goes gets assigned to "a"
            a = temp;


        }
        printf("A is %i\n", a);
    */
    char *firstString = "Arinah";
    unsigned int a, b;

    printf("What is the value of a?\n");
    scanf(" %u", &a);

    printf("What is the value of B?\n");
    scanf(" %u", &b);

    printf("\nThe GCD, of %u and %u is: %u", a, b, gcd(a, b));
    printf("\nThe LCM is %u", lcm(a, b));

    sortString(firstString);

    return 0;
}