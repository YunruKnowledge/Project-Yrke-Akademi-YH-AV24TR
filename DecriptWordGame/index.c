#include <stdbool.h>
#include <stdio.h>

bool isChoosen = false;
bool _singlePlayer;
bool _twoPlayer;

void singlPlayer(){
    printf("Work in progress!");
}

void twoPlayer(){
    char letters;
}

int main()
{
    printf("Welcome to descript Word game! \n");
    printf("There is two game mode types: \n");
    printf("\t 1. One player vs AI \t 2. Player vs Player \n");

    do
    {
        unsigned int playerChoice;
        printf("Write the num of the mode you want to play (\"SinglPlayer : 1\" : \"TwoPlayer : 2\") \n");
        scanf("%d", &playerChoice);
        if (playerChoice == 1){
            _singlePlayer = true;
            isChoosen = true;
        }
        else if (playerChoice == 2){
            _twoPlayer = true;
            isChoosen = true;
        }
        else
            printf("Please enter a valid input! \n");
    } while (!isChoosen);

    if (_singlePlayer == true)
        singlPlayer();
    else if (_twoPlayer == true)
        twoPlayer();
}