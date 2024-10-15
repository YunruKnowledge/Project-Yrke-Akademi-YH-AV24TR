#include "color.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_HAND 99
#define MIN_HAND 0
#define MAX_AMAOUNT_OF_TRYS 10

unsigned int aiNumber, playerNumber, numOfTrys = MAX_AMAOUNT_OF_TRYS;
bool isPlaying = false;

void printRandoms(int min, int max, int count) {
    srand(time(0));

    int random_number = rand() % (max - min + 1) + min;
    aiNumber = random_number;
}

int Play() {
    do {
    printf("Choose a number between 0 and 99: ");
    scanf("%i", &playerNumber);

    if (playerNumber < aiNumber) {
      SetBoldTextColor(red);
      printf("Sorry, too small. Try again! \nNumber of guesses left: %i \n", numOfTrys);
      ResetColors();
      numOfTrys--;
    } else if (playerNumber > aiNumber) {
      SetBoldTextColor(red);
      printf("Sorry, too big. Try again! \nNumber of guesses left: %i \n", numOfTrys);
      ResetColors();
      numOfTrys--;
    } else if (playerNumber == aiNumber) {
      SetBoldTextColor(green);
      printf("Congratulation you guessed the right number \n");
      ResetColors();
      isGoingToPlay();
    }
  } while (numOfTrys <= MAX_AMAOUNT_OF_TRYS);

    SetBoldTextColor(red);
    printf("Sorry you dont have eny gusses left \n");
    ResetColors();
    isGoingToPlay();
}

int isGoingToPlay() {
  int changeState;
  printRandoms(MIN_HAND, MAX_HAND, 1);
  isPlaying = false;

  do{ 
    printf("If you want to play again write 1 or if you want to exit write 2 \n");
    scanf("%i", &changeState);

    if (changeState == 1){
        numOfTrys = MAX_AMAOUNT_OF_TRYS;
        system("clear");
        Play();
        isPlaying = true;
    }
    else if (changeState == 2)
        return 0;
  } while (!isPlaying);
}

int main() {
  system("clear");
  isGoingToPlay();
}