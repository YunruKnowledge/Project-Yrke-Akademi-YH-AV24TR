#include <stdio.h>
#include "Librarys/GRN.h"
#include "Librarys/colors.h"

#define MIN_NUMBER 0
#define MAX_NUMBER 10000
#define NUMBER_OF_RANDOM_NUMBERS 9

int compare(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

int main(){
    int* numbers = getArrayOfRandomNumbers(MIN_NUMBER, MAX_NUMBER, NUMBER_OF_RANDOM_NUMBERS);
    int num[NUMBER_OF_RANDOM_NUMBERS + 1];

    printf("Unsorted Array: { ");
    for(int i = 0; i <= NUMBER_OF_RANDOM_NUMBERS; i++){
        SetBoldTextColor(red);
        SetBGHighIntenstyColor(white);
        printf("%i",numbers[i]);
        if (i < NUMBER_OF_RANDOM_NUMBERS) printf(", ");
        num[i] = numbers[i];
    }
    ResetColors();

    int n = sizeof(num) / sizeof(num[0]);
    qsort(num, n, sizeof(int), compare);

    printf(" } \n  Sorted Array: { " );
    for (int i = 0; i < n; i++) {
        SetBoldTextColor(white);
        SetBGHighIntenstyColor(red);
        printf("%d", num[i]);
        if (i < n - 1) printf(", ");
    }
    ResetColors();
    printf(" }\n");

    return 0;
}