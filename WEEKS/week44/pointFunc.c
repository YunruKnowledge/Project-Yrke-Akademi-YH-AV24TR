/**
 * @brief An example of function.
 *        1. Make a function(print_string) to take a string and print it to the terminal.
 *        2. Make a function pointer to print_string and then in your program call print_string
 *           via the function pointer in order to print your name to the terminal.
 *
 * 
 */
#include <stdio.h>

//funcPrototype: After compilation, func turn into instructions. I'll will be pointing to the instructions. Less resource intensive because I won't be copying it.
void funcPrint(double *p);//double olan bit sayi parametere point. (pointer needs to point to an adress)

int main(void){
//a pointer with a parameter. pointing to func.
    void (*fptr)(double *) = funcPrint; // second paranthesis => the parameter

        double n = 88.88;//a double var, storing 88.88;
        fptr(&n);//a pointer that points to address of n.

        return 0;
}

void funcPrint(double *p){
    printf("This funcPointer printed: %f\n", *p);
}
