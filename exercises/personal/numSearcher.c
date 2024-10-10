#include <stdio.h>

/*create an array of random nums, take input from user and run a for loop,
 where it will run the size of that array and prints if the input value is found in the array.*/

int main(void){
 int nums[] = {20, 30, 50, 80, 99};
 //how to get size of this array? size_of? do i need <string.h>?
 int n = 0;

printf("Input a num:___");
scanf("%i", &n);

 for (int i = 0; i<n; i++){
    if (nums[i] == n){
        printf("I found the number %i!", nums[i]);
        return 0;
    }
    return 1;
 }}