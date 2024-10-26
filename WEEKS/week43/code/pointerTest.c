#include <stdio.h>
#include <unistd.h>
/*
char name[9] = "Go Home";
char *p = name;
*/
int main(void){

//different test below
   /*
    char **pp = &p;//double asterisk,bcz im pointing to a pointer
    char ***ppp = &pp;

    *(**ppp+2) = 'j';
    *(**ppp+3) = 'o';
    *(**ppp+4) = ' ';
    *(**ppp+5) = ' ';
    *(**ppp+6) = 'O';
    *(**ppp+7) = 'P';
    // *(**ppp+8) = '\0';

    printf("ptrAddress: %p\nThe manipulatedName: %s\n", pp, **ppp);//The value that the pointer is pointing to.
*/

//Forcing in a string into an array using pointer.
  /*  const char *arr[2];
    arr[1] = "num 1";
    char *ptr = arr[2];

    ptr = "this is 2 element of the arr[] but assigned through the use of a pointer";

    printf(" %s\n", ptr);
    */

   //1.Declare an array of 5 integers.
   //2.Use a pointer to iterte through the array and print each element.
   //3. Modify the elements using the pointer.

   int n = 5;
   printf("How many integers in the array do you want?: ");
   scanf(" %i", &n);
   int arr[n];
   //point to array
    int *ptr = arr;

    for(int i = 1; i<=n;i++){
        //Both ways of iterating through an array a pointer points to is possible.
    // *(ptr+i) = i;
    ptr[i] = i;

    printf(" arr[%i] is %i\n", i, i);
    printf(" The ptr: %i\nHolds the value: %i\n", i, ptr[i]);
    sleep(4);
    fflush(stdout);
    }




    return 0;
}