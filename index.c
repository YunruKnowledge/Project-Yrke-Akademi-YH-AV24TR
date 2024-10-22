#include <ctype.h>
#include <stdbool.h>
#import <stdio.h>

char array[10] ={'y', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
bool finishGame = false;

void showBoard();

int showChoosingBoard(){
    printf("\nEnter the number where you want to place your mark \n");
    for (int i = 1; i < 10; i += 3){
        printf("\t %i|%i|%i \n", i, i+1, i+2);
        printf("\t -|-|- \n");
    }
}

bool checkWin(char currentSymbol) {
    // Winning combinations
    int winPatterns[8][3] = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9},  // Rows
        {1, 4, 7}, {2, 5, 8}, {3, 6, 9},  // Columns
        {1, 5, 9}, {3, 5, 7}                          // Diagonals
    };

    for (int i = 0; i < 8; i++) {
        if (array[winPatterns[i][0]] == currentSymbol &&
            array[winPatterns[i][1]] == currentSymbol &&
            array[winPatterns[i][2]] == currentSymbol) {
            system("clear");
            printf("Congratulations! Player (%c) won!\n", toupper(currentSymbol));
            showBoard();
            finishGame = true;
            return true;
        }
    }
    return false;
}

void showBoard(){
    printf("\n");
    for (int i = 1; i < 10; i += 3){
        printf("\t %c|%c|%c \n", toupper(array[i]), toupper(array[i+1]), toupper(array[i+2]));
        printf("\t -|-|- \n");
    }
}

int main(){
    char currentSymbol = 'x';
    do {
        system("clear");

        showBoard();
        printf("\nCurrently playing (%c)", toupper(currentSymbol));
        showChoosingBoard();

        int selecedPlace;
        scanf("%i", &selecedPlace);

        if (selecedPlace < 1 || selecedPlace > 9){
            printf("Please enter the number from table above! \n");
        }
        else if (array[selecedPlace] == ' '){
            array[selecedPlace] = tolower(currentSymbol);

            checkWin(currentSymbol);
            currentSymbol = (currentSymbol == 'x') ? 'o' : 'x';
        }else{
            printf("That place is already occupaid \n");
        }

        sleep(1);
    }while (!finishGame);

    return 0;
}