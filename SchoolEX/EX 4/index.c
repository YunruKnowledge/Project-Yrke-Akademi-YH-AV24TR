#include <stdio.h>
#include <string.h>
#include "../../Librarys/colors.h"

#define FILE_NAME "test.txt"

#define MAX_AMOUNT_OF_USERS 10
#define MIN_AMOUNT_OF_USERS 1

typedef struct user newUser;
struct user
{
    char name[50];
    char afterName[50];
    int age;
};

void createFile(FILE *file);
void putInFile(FILE *file, newUser *users, int userAmount);
void readFile(FILE *file);

int main(void)
{
    int amountOfUsers, index = 0;
    char uInput;

    newUser *users;
    FILE *file = fopen(FILE_NAME, "r");

    createFile(file);

    (void)printf("Enter [r] to read the file or [w] to enter new users: ");
    (void)scanf("%c", &uInput);

    if (uInput == 'r')
    {
        readFile(file);
    }
    else if (uInput == 'w')
    {
        (void)printf("Input how many users u want to input: ");
        (void)scanf("%d", &amountOfUsers);

        if (amountOfUsers < MIN_AMOUNT_OF_USERS || amountOfUsers > MAX_AMOUNT_OF_USERS)
        {
            printf("Too many or too few users! Please input a number between %d and %d.\n", MIN_AMOUNT_OF_USERS, MAX_AMOUNT_OF_USERS);
            fclose(file);
            return 1;
        }

        int tempAmount = amountOfUsers;
        while (tempAmount)
        {
            (void)printf("[%d] Input your Name:", index);
            (void)scanf("%s", users[index].name);

            (void)printf("[%d] Input your AfterName:", index);
            (void)scanf("%s", users[index].afterName);

            (void)printf("[%d] Input your Age:", index);
            if(!(scanf("%d", &users[index].age))){
                (void)ShowErrorMessage("Invalid input! Must be a number!");
                return -1;
            }

            index++;
            tempAmount--;
        }

        putInFile(file, users, amountOfUsers);
    }
    else
    {
        (void)ShowErrorMessage("Wrong Input!");
        return -1;
    }

    fclose(file);
    return 0;
}

void createFile(FILE *file)
{
    if (file == NULL)
    {
        (void)printf("File with name[%s] doesn't exist! Creating the file with fileName [%s]", FILE_NAME, FILE_NAME);
        file = fopen(FILE_NAME, "w");
        fclose(file);
    }
}

void putInFile(FILE *file, newUser *users, int userAmount)
{
    char line[100];
    int userID = -1;
    int index = 0;

    file = fopen(FILE_NAME, "r");
    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (sscanf(line, "%d:", &userID) == 1)
            index++;
    }
    fclose(file);

    file = fopen(FILE_NAME, "a");
    for (int i = 0; i < userAmount; i++)
    {
        fprintf(file, "%d: {\n", index);
        fprintf(file, "\tID: %d \n", (index));
        fprintf(file, "\tName: %s \n", users[i].name);
        fprintf(file, "\tAfterName: %s \n", users[i].afterName);
        fprintf(file, "\tAge: %d \n", users[i].age);
        fprintf(file, "} \n");
        index++;
    }

    fclose(file);
}

void readFile(FILE *file)
{
    file = fopen(FILE_NAME, "r");

    char line[100];

    int userID = -1;
    int readingUser = 0;

    newUser user;
    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (sscanf(line, "%d:", &userID) == 1)
        {
            printf("\nFound user ID: %d\n", userID);
            readingUser = 1;
        }
        else if (readingUser)
        {
            if (strncmp(line, "\tName:", 5) == 0)
            {
                sscanf(line + 5, " %49[^\n]", user.name);
            }
            else if (strncmp(line, "\tAfterName:", 10) == 0)
            {
                sscanf(line + 10, " %49[^\n]", user.afterName);
            }
            else if (strncmp(line, "\tAge: ", 5) == 0)
            {
                sscanf(line + 5, " %d", &user.age);

                printf("Name: %s\n", user.name);
                printf("AfterName: %s\n", user.afterName);
                printf("Age: %d\n\n", user.age);

                readingUser = 0;
            }
        }
    }
    fclose(file);
}