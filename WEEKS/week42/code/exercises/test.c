#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char playAgain = 'y';
    system("clear");

    while (playAgain == 'y' || playAgain == 'Y') {
        srand(time(NULL));
        int secretNumber = rand() % 100;
        int theGuess = 0;
        int tries = 10;
        char input[100]; // To store user input as a string

        // Loop to go through the entire application
        for (int i = 0; i < tries; i++) {
            printf("Tries left: %d\n", (tries - i));
            printf("Write the number you think is close to the secret number (0-99): \n");

            scanf("%s", input);  // Take input as a string

            // Check if the input contains non-digit characters
            int isNumber = 1;
            for (int j = 0; input[j] != '\0'; j++) {
                if (!isdigit(input[j])) {
                    isNumber = 0; // If there's a non-digit, it's not a number
                    break;
                }
            }

            if (!isNumber) {
                printf("Input a number!\n");
                i--; // Keep the same number of tries
                continue; // Go back to the start of the loop
            }

            theGuess = atoi(input); // Convert string to integer

            // Number range validation
            if (theGuess < 0 || theGuess > 99) {
                printf("Wrong, I said MAX 99.\n");
                i--; // Don't count this as a valid try
                continue;
            }
            // Check if the guess is correct
            else if (theGuess == secretNumber) {
                printf("Guess what genius, you found it!\n");
                goto replay;
            }
            // Give hint if the guess is too low
            else if (theGuess < secretNumber) {
                printf("MORE!\n");
            }
            // Give hint if the guess is too high
            else {
                printf("LOWER!\n");
            }

            // If out of tries
            if (i == tries - 1) {
                printf("You lost, now go cry about it. 3-)\n");
            }
        }

    replay:
        printf("Wanna give it another shot? (y/n): ");
        scanf(" %c", &playAgain);
    }

    printf("Goodbye!\n");
    return 0;
}
