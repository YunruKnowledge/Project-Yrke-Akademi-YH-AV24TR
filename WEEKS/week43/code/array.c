#include <stdio.h>

int main(void){
    char arr[] = {'n','o','-','w','a','y'};
    int arr2d[10][4] = {{1,2,3}, {4,5,6}};
    /*
      ---
    1|456|
    0|123|
      ---
      012
    */
    for (int i = 0; i <= sizeof(arr)/sizeof(arr[0]); i++){
        printf("Inside the arr: %c\n", arr[i]);
    }

    int numArr = sizeof(arr)/sizeof(arr[0]);
    printf("Num of e in arr %i\n", numArr);
    printf("the second row, second element has %i\n", arr2d[1][1]);
}