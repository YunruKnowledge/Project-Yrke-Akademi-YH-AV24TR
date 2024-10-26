#include <stdio.h> 
#include <unistd.h>


    //3x3 Matrix Array
    int marr[3][3];
    //temporary num holder
    int temp = 0;

int main(void){

   
    //a loop i and j to iterate through a matrix array, and fill all the elements(strings)
    for (int i = 1; i<=3; i++){
        for (int j = 1; j<=3; j++){
            printf("What number will you save in line %i column %i?: ", i, j);
            scanf(" %i", &temp);
            marr[i][j] = temp;
        }
    }

    for (int i = 1; i<=3; i++){
        
        printf("\n");
        for (int j = 1; j<=3; j++){
            printf("~%i~", marr[i][j]);
            sleep(1);
            fflush(stdout);
        }
            printf("\n");
    }

return 0;
}
/*
Write a program to make a 2 dimensional(3x3) array of type int.

Then ask the user to enter all the elements and then print the array to the output.

Print the array to the output like a table. For example:

    123  234  456
     54  678  987
     12  987  100
*/