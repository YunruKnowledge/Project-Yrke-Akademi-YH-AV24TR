#include <ctype.h>
#include <stdbool.h>
#import <stdio.h>

int showChoosingBoard(){
    printf("\nEnter the number where you want to place your mark \n");
    printf("\t 1|2|3 \n");
    printf("\t -|-|- \n");
    printf("\t 4|5|6 \n");
    printf("\t -|-|- \n");
    printf("\t 7|8|9 \n");
    printf("\t -|-|- \n");
}

int main(){
    system("clear");

    char array[10] ={'y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char currentSymbol = 'x';
    bool finishGame = false;

    do {
        int selecedPlace;

        printf("\t %c|%c|%c \n", array[1], array[2], array[3]);
        printf("\t -|-|- \n");
        printf("\t %c|%c|%c \n", array[4], array[5], array[6]);
        printf("\t -|-|- \n");
        printf("\t %c|%c|%c \n", array[7], array[8], array[9]);
        printf("\t -|-|- \n");

        printf("\nCurrently playing (%c)", toupper(currentSymbol));
        showChoosingBoard();
        scanf("%i", &selecedPlace);

        if (selecedPlace < 1 || selecedPlace > 9){
            printf("Please enter the number from table above! \n");
        }
        else if (array[selecedPlace] == ' ' && array[selecedPlace] != currentSymbol){
            array[selecedPlace] = toupper(currentSymbol);
            if (currentSymbol == 'x')
                currentSymbol = 'o';
            else
                currentSymbol = 'x';
        }else{
            printf("That place is already occupaid \n");
        }

        // Confirm state of the game

        sleep(1);
        system("clear");
    }while (!finishGame);

    return 0;
}