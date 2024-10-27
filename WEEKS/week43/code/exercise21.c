#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// Function to fill the array with random numbers using pointers
void fillArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        *(arr + i) = rand() % 100; // Random number between 0 and 99
    }
}

// Function to print the array using pointers
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

// Function to sort the array in ascending order using pointers
void sortArray(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (*(arr + i) > *(arr + j)) {
                // Swap the values at arr[i] and arr[j] using pointers
                int temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
}

int main() {
    int arr[SIZE];
    srand(time(0)); // Seed for random number generation

    // Fill the array with random numbers
    fillArray(arr, SIZE);

    // Print the unsorted array
    printf("Unsorted array:\n");
    printArray(arr, SIZE);

    // Sort the array
    sortArray(arr, SIZE);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, SIZE);

    return 0;
}
