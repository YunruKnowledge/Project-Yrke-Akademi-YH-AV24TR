/*
func, take in a matrix array(already poiinter).
use define and use it in the matrix. Pre fill the matrix with values.
*/

#include <stdio.h>

#define SIZE 3

void display_matrix(int matrix[SIZE][SIZE]);

    int main(void){
        //matrix array kendinden bir pointer, Asterisk koymaya gerek yok.
        // Yani ilk brackets aslinda sadece bir *.
        int matrixArr[SIZE][SIZE] = {{10,20,30},{50,60,70}, {90,100,110}};
       
        display_matrix(matrixArr);

        return 0;
    }

void display_matrix(int matrix[SIZE][SIZE]){

for (int i = 0; i < SIZE; i++)
{
    printf("~~");
    for (int j = 0; j < SIZE; j++)
    {   
        printf(" %i ", matrix[i][j]);
    }
    printf("~~");
    printf("\n");
}
}

