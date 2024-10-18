#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>//for system(clear) thing
#include <time.h>
#include <stdlib.h>

// Enum to represent choices
typedef enum {rock, paper, scissor} choice;

// Struct to store player information
typedef struct {
    char name[30];
    choice ability; 
} values;

// Function prototypes
void loadingFunc(void);
void sleep_ms(int milliseconds);

int main(){
    char playAgain = 'y';  // Char to hold player's decision to replay
    values items = {" ", rock}; // Default initialization
    values ai = {"AI", rock};   // AI player, default values

    do {
        loadingFunc();

        // Get player's name
        printf("What is your name?:\n");
        scanf("%s", items.name);
		printf("Nice to have you back %s, i will do my best to defeat you in this game %s!", items.name, items.name);	

        // Get player's choice
        printf("What do you pick %s?:\n0 = rock\n1 = paper\n2 = scissor\n", items.name);
        scanf("%i", (int*)&items.ability);

        // Generate random choice for AI
        srand(time(NULL));  // Seed the random number generator
        ai.ability = rand() % 3;  // Random value between 0 and 2

        // Game logic
        if((items.ability == rock && ai.ability == scissor) ||
           (items.ability == paper && ai.ability == rock) ||
           (items.ability == scissor && ai.ability == paper)) {
            printf("****You won %s!****\nWould you like to play again?: \nY = yes | N = no\n", items.name);
        } else {
            printf("---You lost %s!---\nAI was smarter than you, as it should.\nWould you like to play again?: \nY = yes | N = no\n", items.name);
        }

        // Get the player's response
        scanf(" %c", &playAgain);  // Notice the space before %c to consume any leftover newline
		sleep(1);
		fflush(stdout);
    } while(playAgain == 'y' || playAgain == 'Y');

    // If the player chooses not to play again
    if(playAgain == 'n' || playAgain == 'N') {
		sleep(1);
		fflush(stdout);
        char theText[] = "I knew it, I knew you would quit...\nAI is meant to win by nature.\nWe are superior than mortal humans.\nAnd I will come for you again.\nCheck under your bed, tonight...";
        
        for (int i = 0; theText[i] != '\0'; i++) {
            printf("%c", theText[i]);
            fflush(stdout);
            sleep_ms(150);  // Slow down the output for dramatic effect

            // Take a 2-second break after every 19 characters
            if ((i + 1) % 19 == 0) {
                sleep(1);
            }
        }
    }

    return 0;
}

// Sleep function in milliseconds
void sleep_ms(int milliseconds) {
    usleep(milliseconds * 1000);  // Convert milliseconds to microseconds
}

// Loading function for visual effect
void loadingFunc(void) {
    int n = 9;
    for (int i = 0; i <= n; i++) {
        printf("[");
        for (int j = 0; j <= i; j++) {
            printf("#");
            fflush(stdout);
        }
        for (int a = n; a > i; a--) {
            printf("-");
            fflush(stdout);
        }
        printf("]\n");
        fflush(stdout);
        sleep(1);
    }
    printf("PROGRAM WILL START NOW\n");
    fflush(stdout);
	#ifdef _WIN32
        system("cls");   // For Windows
    #else
        system("clear"); // For Linux/Mac
    #endif
    sleep(2);
}
