#include "color.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_HAND 99
#define MIN_HAND 0
#define MAX_AMAOUNT_OF_TRYS 10

int Play();
int isGoingToPlay();

unsigned int aiNumber, playerNumber, numOfTrys = MAX_AMAOUNT_OF_TRYS;
bool isPlaying = false;

void printRandoms(int min, int max) {
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
  char changeState[0];
  printRandoms(MIN_HAND, MAX_HAND);
  isPlaying = false;

  do{ 
    printf("If you want to play again write \"y\" or if you want to exit write \"n\" \n");
    scanf("%c", &*changeState);

    if (tolower(changeState[0]) == 'y'){
        numOfTrys = MAX_AMAOUNT_OF_TRYS;
        system("clear");
        Play();
        isPlaying = true;
    }
    else if (tolower(changeState[0]) == 'n')
        return 0;

    system("clear");
        
  } while (!isPlaying);
}

int main() {
  system("clear");
  isGoingToPlay();
}