#include <stdio.h>

//an enum that is named choice, using typedef so only this enum has this name and WHEN i use the name CHOICE the compiler know and will replace it with the enum.
typedef enum {rock, paper, scissors} choice;

typedef struct {
    char name[50];
    choice input;
} objectS;


int main() {
//ask player a input, take and store, randomize, if the random value is less then 5 player lose(); if value > 5 player win();,
    objectS userInput = {"Ahmet", 1}; // Example values

    printf("%s inputted: %s\n", userInput.name,
        userInput.input == rock ? "Rock" :
        userInput.input == paper ? "Paper" :
        "Scissors");

    return 0;
}