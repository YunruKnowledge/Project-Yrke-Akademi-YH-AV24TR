#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define STRING_LENGHT 20

int main(void) {
    unsigned char str[STRING_LENGHT] = "abccba"; 
    int length = strlen(str); 

    bool isPalindrome = true;  

    for (int i = 0; i < length / 2; i++) {  
        if (str[i] != str[length - i - 1]) {  
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome) 
        printf("It was infact a palindrome\n");
    else 
        printf("It was infact not a palindrome\n");

    return 0;
}