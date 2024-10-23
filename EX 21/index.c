#include <stdio.h>
#include "../Librarys/GRN.h"

#define NUM_OF_RANDOM_NUM 10 
#define MAX_RANDOM_NUM 99
#define MIN_RANDOM_NUM 0

int compare(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

int main(){
    int *arr = getArrayOfRandomNumbers(MIN_RANDOM_NUM, MAX_RANDOM_NUM, NUM_OF_RANDOM_NUM);

    for (int i = 0; i < NUM_OF_RANDOM_NUM; i++){
        printf("[%i] ", arr[i]);
    }

    printf("\n");
    qsort(arr, NUM_OF_RANDOM_NUM, sizeof(int), compare);

    for (int i = 0; i < NUM_OF_RANDOM_NUM; i++){
        printf("[%i] ", arr[i]);
    }

    printf("\n");
}