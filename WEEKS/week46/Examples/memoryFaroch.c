/**
 * @file main.c
 * @author Faroch Mehri (faroch.mehri@ya.se)
 * @brief An example of dynamic memory management.
 *        1) Make a function to create a person
 *        2) Make a function to free a person
 * @version 0.1
 * @date 2021-03-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct
{
    char *name;
    uint8_t age;
} person_t;

static void free_person(person_t **person);
static person_t *create_person(const char *name, uint8_t age);

int main(void)
{
    person_t *stefan = create_person("Stefan", 23);
    if (stefan == NULL)
    {
        printf("Failed to create Stefan\n");
        exit(1);
    }

    printf("%s is %u years old.\n", stefan->name, stefan->age);

    person_t *alice = create_person("Alice", 30);
    if (alice == NULL)
    {
        free_person(&stefan);
        printf("Failed to create Alice\n");
        exit(1);
    }

    printf("%s is %u years old.\n", alice->name, alice->age);

    free_person(&stefan);

    free_person(&alice);

    return 0;
}

static void free_person(person_t **person)
{
    free((*person)->name);
    free(*person);
    *person = NULL;
}

static person_t *create_person(const char *name, uint8_t age)
{
    person_t *ptr = (person_t *)malloc(sizeof(person_t));
    if (ptr != NULL)
    {
        ptr->age = age;
        size_t len = strlen(name) + 1;
        ptr->name = (char *)malloc(len * sizeof(char));
        if (ptr->name != NULL)
        {
            strncpy(ptr->name, name, len);
        }
        else
        {
            free(ptr);
            ptr = NULL;
        }
    }

    return ptr;
}