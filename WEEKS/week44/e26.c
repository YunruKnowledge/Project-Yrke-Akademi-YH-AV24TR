/*Description
Make a function named get_person, to create an instance of person_t and then
ask the user to enter values for the members in a terminal and
in the end return the instance.


typedef struct {


    int age;

    float height;

    char name[16];

} person_t;
*/
#include <stdio.h>
#include <string.h>

typedef struct
{
    int age;
    float height;
    char name[16];
} person_t;

person_t get_person(void); // So the function will return type of person_t(yani those struct types that is inside it).

int main(void)
{
    person_t person = get_person(); // calling person_t struct, name it person, and then assign person as getperson()function?

    printf("\nDetails below\nName: %s\nAge: %i\nHeight: %.2f", person.name, person.age, person.height);

    return 0;
}

person_t get_person(void)
{
    person_t personSt;
    char tempName[16];

    printf("1\n");
    printf("How old are you?\n");
    scanf("%i", &personSt.age);
    
    printf("2\n");
    printf("What is your height?\n");
    scanf("%f", &personSt.height);

    printf("3\n");
    printf("What is your name?\n");
    scanf("%s", tempName);
    strcpy(personSt.name, tempName);//string copy to personSt.name, FROM: tempname.

    return personSt;
}