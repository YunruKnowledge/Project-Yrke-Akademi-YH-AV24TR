#include <stdio.h>
#include <ctype.h>  // For checking valid hex input

void hexToBinary(char hex);

int main() {
    char hex[100];  // Buffer to store the hex number
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    // Convert each hex character to binary
    for (int i = 0; hex[i] != '\0'; i++) {
        // Check if it's a valid hex digit
        if (!isxdigit(hex[i])) {
            printf("Invalid hex digit: %c\n", hex[i]);
            return 1;  // Exit the program if invalid input
        }
        hexToBinary(hex[i]);
    }
    printf("\n");
    return 0;
}

void hexToBinary(char hex) {
    switch (toupper(hex)) {  // Ensure case insensitivity for hex digits
        case '0': printf("0000 "); break;
        case '1': printf("0001 "); break;
        case '2': printf("0010 "); break;
        case '3': printf("0011 "); break;
        case '4': printf("0100 "); break;
        case '5': printf("0101 "); break;
        case '6': printf("0110 "); break;
        case '7': printf("0111 "); break;
        case '8': printf("1000 "); break;
        case '9': printf("1001 "); break;
        case 'A': printf("1010 "); break;
        case 'B': printf("1011 "); break;
        case 'C': printf("1100 "); break;
        case 'D': printf("1101 "); break;
        case 'E': printf("1110 "); break;
        case 'F': printf("1111 "); break;
        default: printf("Error ");  // Just in case
    }
}

