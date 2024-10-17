#include <stdio.h>
#include "Librarys/GRN.h"

#define MIN_NUMBER 0
#define MAX_NUMBER 10000
#define NUMBER_OF_RANDOM_NUMBERS 9

int compare(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

int main(){
    int* numbers = getArrayOfRandomNumbers(MIN_NUMBER, MAX_NUMBER, NUMBER_OF_RANDOM_NUMBERS);
    int num[NUMBER_OF_RANDOM_NUMBERS + 1];
    for(int i = 0; i <= NUMBER_OF_RANDOM_NUMBERS; i++){
        printf("%i ",numbers[i]);
        num[i] = numbers[i];
    }

    int n = sizeof(num) / sizeof(num[0]);
    qsort(num, n, sizeof(int), compare);
    printf("\nSorted Array: \n");

    for (int i = 0; i < n; i++) {
        printf("%d ", num[i]);
    }

    printf("\n");

    return 0;
}