#include <stdio.h>
#include "binary.h"

int main(){
    int num, options;
    int numA, numB;

    printf("Choose one of the options! \n");
    printf("--------------1. For Binary transform ----------------------- \n");
    printf("--------------2. For Binary substraction ----------------------- \n");
    scanf("%d01", &options);

    if (options == 1){
        printf("Enter any number: ");
        scanf("%d", &num);
        toBinary(num);  
    }

    if (options == 2){
        printf("Enter first num: ");
        scanf("%d", &numA);

        printf("Enter second num: ");
        scanf("%d", &numB);

        binarySubstraction(numA, numB);
    }

    printf("\n");
    return 0;
}