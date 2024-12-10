#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef unsigned int uint_t;
#define LIMIT 100


void displayStats(uint_t answer, uint_t attempts, long int startTime)
{
    long int timeTaken = time(0) - startTime;
    printf("###        Answer: %u\n", answer);
    printf("### Attempts left: %u\n", attempts);
    printf("###    Time taken: %lds\n", timeTaken);
}

int main(void)
{
    printf("\nStarting...\n\n");

    long int startTime = time(0);
    srand(time(NULL));
    uint_t attempts = 10;
    uint_t targetNumber = rand() % (LIMIT + 1); // rand below 101 (0-100)
    uint_t userInput;

    printf("Guess a number between zero and hundred.\n");
    while (attempts > 0)
    {
        printf("\n[%2u] Input-> ", attempts);
        scanf("%u", &userInput);

        if (userInput > LIMIT)
        {
            printf("\nINVALID NUMBER.\n");
            printf("RANGE IS FROM [0] TO [%i].\n", LIMIT);
            printf("TRY AGAIN.\n\n");
            continue;
        }

        if (userInput < targetNumber)
        {
            printf("Wrong number, too low :)\n");
        }
        else if (userInput == targetNumber)
        {
            printf("\n\n\n");
            printf("###       CORRECT NUMBER!! :D       ###\n");
            printf("### WINNER WINNER CHICKEN DINNER !! ###\n");
            printf("\n###              STATS              ###\n");

            displayStats(targetNumber, attempts, startTime);
            attempts = 1; // set to 0 + 1 for --i back to 0
        }
        else
        {
            printf("Wrong number, too high >:)\n");
        }
        --attempts;
    }

    return 0;
}