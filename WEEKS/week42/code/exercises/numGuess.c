#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>//sleep

int main(){
    char playAgain = 'y';
    system("clear");

    while (playAgain == 'y' || playAgain == 'Y'){
        srand(time(NULL));
        int secretNumber = rand() % 100;
        int theGuess = 0;
        int tries = 10;

        //a forLoop to go through the the entire application
        for (int i = 0; i < tries; i++){
            printf("Tries left: %d\n", (tries - i));
            printf("Write the number you think is close to the secretnumber: \n");
            scanf("%d", &theGuess);

            while (isalpha(theGuess)){
                printf("Input a number!\n");
                printf("Write the number you think is close to the secretnumber: \n");
            scanf("%d", &theGuess);
            }
//add do loop above
            if (theGuess < 0 || theGuess > 99){
                printf("Wrong, I said MAX 99 bruh.");
                i--;
                continue;// restart the main whileLoop 
            }
            else if (theGuess == secretNumber){
                printf("Guess what genius, you found it.\nNow what is 2*6.5?");
                theGuess = 0;
                // break;//exits the while loop
                goto replay;
            }
            else if(theGuess < secretNumber){
                printf("MORE!");
            }
            else{
                printf("LOWER!");
            }

        // replay:
        if (i == tries - 1){
            printf("You lost, now go cry about it. 3-)");
        }
    }
        replay:
     printf("Wana give it another shot? (y/n): ");
     scanf(" %c", &playAgain);
    }

    printf("Goodbye!");
    return 0;
}