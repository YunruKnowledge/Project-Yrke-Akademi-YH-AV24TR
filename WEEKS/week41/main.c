#include <stdio.h>

#define NAME "Hello World"

struct customer {
    int bit :5;
    int num;  // Declare num as an integer
};

int main(void) {
    struct customer cust;  // Create an instance of struct customer
    cust.num = 12345678;          // Assign a value to num
    cust.bit = 15;
    // Print customer information
    printf("%s and customer's number is: %04d and bit is %i\n", NAME, cust.num, cust.bit);


    int num1 = 4;
    int num2 = 8;

     float result = num1 + num2;
     printf("result is: %f", result); 
     
    return 0;
}
