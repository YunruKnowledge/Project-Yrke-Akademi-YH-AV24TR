#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "../../Librarys/colors.h" 

#define FILE_NAME "test.txt"

#define MAX_AMOUNT_OF_USERS 10
#define MIN_AMOUNT_OF_USERS 1

typedef struct user newUser;
struct user {
    char name[50];
    char afterName[50];
    int age;
};

void createFile(FILE *file);
void putInFile(FILE *file, newUser *users, int userAmount);
void readFile(FILE *file, char search[50]);

int main(void)
{
    int amountOfUsers, index = 0;
    char searchWord[50];
    char uInput;

    newUser *users = NULL; 
    FILE *file = fopen(FILE_NAME, "r");

    createFile(file);

    (void)printf("Enter [r] to read the file or [w] to enter new users: ");
    (void)scanf(" %c", &uInput);

    if (uInput == 'r')
    {
        printf("Input a field you want to search for [Name, AfterName, Age]: ");
        scanf("%s", searchWord);
        readFile(file, searchWord);
    }
    else if (uInput == 'w')
    {
        (void)printf("Input how many users you want to input: ");
        (void)scanf("%d", &amountOfUsers);

        if (amountOfUsers < MIN_AMOUNT_OF_USERS || amountOfUsers > MAX_AMOUNT_OF_USERS)
        {
            printf("Too many or too few users! Please input a number between %d and %d.\n", MIN_AMOUNT_OF_USERS, MAX_AMOUNT_OF_USERS);
            fclose(file);
            return 1;
        }

        users = (newUser *)malloc(amountOfUsers * sizeof(newUser));
        if (users == NULL)
        {
            (void)ShowErrorMessage("Memory allocation failed!");
            fclose(file);
            return 1;
        }

        int tempAmount = amountOfUsers;
        while (tempAmount)
        {
            (void)printf("[%d] Input your Name: ", index);
            (void)scanf("%s", users[index].name);

            (void)printf("[%d] Input your AfterName: ", index);
            (void)scanf("%s", users[index].afterName);

            (void)printf("[%d] Input your Age: ", index);
            if (!(scanf("%d", &users[index].age)))
            {
                (void)ShowErrorMessage("Invalid input! Age must be a number.");
                free(users);  
                fclose(file);
                return -1;
            }

            index++;
            tempAmount--;
        }

        putInFile(file, users, amountOfUsers);
        free(users);
    }
    else
    {
        (void)ShowErrorMessage("Wrong Input!");
        fclose(file);
        return -1;
    }

    fclose(file);
    return 0;
}

void createFile(FILE *file)
{
    if (file == NULL)
    {
        (void)printf("File with name[%s] doesn't exist! Creating the file with fileName [%s]\n", FILE_NAME, FILE_NAME);
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
        fprintf(file, "ID: %d \n", (index));
        fprintf(file, "Name: %s \n", users[i].name);
        fprintf(file, "AfterName: %s \n", users[i].afterName);
        fprintf(file, "Age: %d \n", users[i].age);
        fprintf(file, "} \n");
        index++;
    }

    fclose(file);
}

void readFile(FILE *file, char search[50])
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
            if (strncmp(line, "Name:", 5) == 0 && strcmp(search, "Name") == 0)
            {
                sscanf(line + 5, " %49[^\n]", user.name);
                printf("Name: %s\n", user.name);
            }
            else if (strncmp(line, "AfterName:", 10) == 0 && strcmp(search, "AfterName") == 0)
            {
                sscanf(line + 10, " %49[^\n]", user.afterName);
                printf("AfterName: %s\n", user.afterName);
            }
            else if (strncmp(line, "Age:", 4) == 0 && strcmp(search, "Age") == 0)
            {
                sscanf(line + 4, " %d", &user.age);
                printf("Age: %d\n", user.age);
            }
            else if (line[0] == '}')
            {
                readingUser = 0;
            }
        }
    }

    fclose(file);
}
