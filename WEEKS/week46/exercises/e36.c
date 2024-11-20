/*Description
Write a program to make an array of person_t dynamically.

The program shall ask the user to enter length of the array.
Then the program shall allocate memory for the array.
Then the program shall ask the user to enter name and age of each person.
Memory for the name member shall be allocated dynamically.
Then the program shall print all the persons to the output.
In the end the program shall release all the dynamically allocated memory.

*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct

{
    char *name;

    uint8_t age;

} person_t;

int main(void)

{
    // ask user for length of array.
    uint8_t length = 0;

    while (length < 1)
    {
        (void)printf("Evter length of the array: \n");
        (void)scanf("%u", &length);
        clear_buffer();
    }

    // Array to hold the structs.
    // a pointer of type that struct, that points to a block of memory, that has the size of the struct, TIMES the length(amount of persons)
    person_t *thePersons = (person_t *)malloc(length * sizeof(person_t));

    // allocate mem for this array.

    // ask users to enter name and age of each person.

    // dynamically allocate mem for name members

    // print all the persons with name and age to output.

    // free all the dynamic memories used.

    return 0;
}