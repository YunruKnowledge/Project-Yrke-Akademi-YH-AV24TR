#include <stdio.h>

int main(void){

    int matrix[1][2][1][2];

    matrix[0][0][0][2] = 99;

    printf(" the num is %i", matrix[0][0][0][2]);
}
