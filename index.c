#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_HAND 3      // Rock
#define MIN_HAND 1      // Paper
#define MIDDLE_HAND 2   // Scissors

int aiHand;

void printRandoms(int min, int max, int count) {
    srand(time(0));

    for (int i = 0; i < count; i++) {
        int random_number = rand() % (max - min + 1) + min;
        aiHand = random_number;
    }
}

int main(){
    int playerHand;
    printRandoms(MIN_HAND, MAX_HAND, 1);
    printf("Choose the metod to fight by writing the number before the metod: \n 1. Paper \n 2. Scissors \n 3. Rock \n");
    scanf("%i", &playerHand);

    printf("You chose: %d \n AI chose: %d \n", playerHand, aiHand);

    if (playerHand == MAX_HAND && aiHand == MIN_HAND || playerHand == MIN_HAND && aiHand == MIDDLE_HAND || playerHand == MIDDLE_HAND && aiHand == MAX_HAND)
        printf("You Lost! \n");
    else if (playerHand == aiHand)
        printf("DRAW! \n");
    else
        printf("You WON!!! \n");

    return  0;
}