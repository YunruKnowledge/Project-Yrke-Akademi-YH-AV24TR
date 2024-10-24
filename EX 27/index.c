#include "../Librarys/GRN.h"

#define MIN_NUM 1
#define MAX_NUM 99
#define NUM_OF_RANDOM_NUM 5

int main()
{
    int *arr = getArrayOfRandomNumbers(MIN_NUM, MAX_NUM, NUM_OF_RANDOM_NUM);
    int biggestNum = 0, avgNum = 0, findNum;

    printf("Enter the number you want to find in array: ");
    scanf("%d", &findNum);

    for (int i = 0; i < NUM_OF_RANDOM_NUM; i++)
    {
        printf("[%d]", arr[i]);
        avgNum += arr[i];

        if (biggestNum < arr[i])
            biggestNum = arr[i];
    }

    printf("\nBiggest number is: %d\n", biggestNum);
    printf("Average number is: %d\n", (avgNum / NUM_OF_RANDOM_NUM));

    for (int i = 0; i < NUM_OF_RANDOM_NUM; i++)
    {
        if (findNum == arr[i])
            printf("Your number [%d] is found in place [%d] inside the array \n", findNum, i);
    }

    return 0;
}