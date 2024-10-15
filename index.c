#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "color.h"

#define MAX_HAND 99
#define MIN_HAND 0 

unsigned int aiNumber, playerNumber, numOfTrys = 10;

void printRandoms(int min, int max, int count) {
    srand(time(0));

    for (int i = 0; i < count; i++) {
        int random_number = rand() % (max - min + 1) + min;
        aiNumber = random_number;
    }
}

int Play(){
    if (numOfTrys != 0){
        printf("Choose a number between 0 and 99: ");
        scanf("%i", &playerNumber);

        if (playerNumber < aiNumber){
            SetTextColor(red);
            printf("Sorry, too small. Try again! \n");
            ResetColors();
            numOfTrys--;
            PLay();
        }
        else if (playerNumber > aiNumber){
            SetTextColor(red);
            printf("Sorry, too big. Try again! \n");
            ResetColors();
            numOfTrys--;
            PLay();
        }
        else if (playerNumber == aiNumber){
            SetTextColor(green);
            printf("Congratulation you guessed the right number \n");
            ResetColors();
            isGoingToPlay();
        }

    }
    else{
        SetTextColor(red);
        printf("Sorry you dont have eny gusses left \n");
        ResetColors();
        isGoingToPlay();
    }
}

int isGoingToPlay(){
    int isPlaying;
    printRandoms(MIN_HAND, MAX_HAND, 1);
    printf("If you want to play again write 1 or if you want to exit write 2 \n");
    scanf("%i", &isPlaying);
    if (isPlaying == 2)
        return 0;
    else if (isPlaying == 1){
        numOfTrys = 10;
        system("clear");
        Play();
    }
    else{
        printf("Please enter a  number between 1 or 2");
        isGoingToPlay();
    }
}

int main(){
    system("clear");
    isGoingToPlay();
}