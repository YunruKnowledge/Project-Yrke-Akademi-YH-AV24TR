#include <ctype.h>
#include <stdbool.h>
#import <stdio.h>

char array[10] ={'y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
bool finishGame = false;


int showChoosingBoard(){
    printf("\nEnter the number where you want to place your mark \n");
    for (int i = 1; i < 10; i += 3){
        printf("\t %i|%i|%i \n", i, i+1, i+2);
        printf("\t -|-|- \n");
    }
}

int checkGameState(char currentSymbol){
    for (int i = 1; i < sizeof(array); i += 3){
                if (array[i] == currentSymbol && array[i+1] == currentSymbol && array[i+2] == currentSymbol){
                    printf("Congratulation! Player (%c) won! \n", toupper(currentSymbol));
                    sleep(1);
                    finishGame = true;
                }
            }

            for (int i = 1; i < 4; i++){
                if (array[i] == currentSymbol && array[i+3] == currentSymbol && array[i+6] == currentSymbol){
                    printf("Congratulation! Player (%c) won! \n", toupper(currentSymbol));
                    sleep(1);
                    finishGame = true;
                }
            }

            if (array[1] == currentSymbol && array[5] == currentSymbol && array[9] == currentSymbol ||
                array[3] == currentSymbol && array[5] == currentSymbol && array[7] == currentSymbol){
                printf("Congratulation! Player (%c) won! \n", toupper(currentSymbol));
                sleep(1);
                finishGame = true;
            }
}

int main(){
    system("clear");

    char currentSymbol = 'x';
    do {
        int selecedPlace;

        printf("\n");
        for (int i = 1; i < 10; i += 3){
            printf("\t %c|%c|%c \n", toupper(array[i]), toupper(array[i+1]), toupper(array[i+2]));
            printf("\t -|-|- \n");
        }

        printf("\nCurrently playing (%c)", toupper(currentSymbol));
        showChoosingBoard();
        scanf("%i", &selecedPlace);

        if (selecedPlace < 1 || selecedPlace > 9){
            printf("Please enter the number from table above! \n");
        }
        else if (array[selecedPlace] == ' ' && array[selecedPlace] != currentSymbol){
            array[selecedPlace] = tolower(currentSymbol);

            // Confirm state of the game
            checkGameState(currentSymbol);

            if (currentSymbol == 'x')
                currentSymbol = 'o';
            else
                currentSymbol = 'x';
        }else{
            printf("That place is already occupaid \n");
        }

        sleep(1);
        system("clear");
    }while (!finishGame);

    return 0;
}