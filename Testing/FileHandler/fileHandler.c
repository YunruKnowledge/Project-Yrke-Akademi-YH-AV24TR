#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include "fileHandler.h"

// Student struct that holds (ID, name and student age)
typedef struct USER
{
    unsigned id;
    char name[BUFFER];
    uint32_t age;
} t_user;

int userAmount = 0; // To keep track of how many users are in a file

bool createUser(t_user **user, FILE *file, int amount)
{
    char temp[BUFFER]; // Temporary val for user name input
    uint32_t tempAge;  // Temporary val for user age input

    bool returnVal = true; // Temporary return val

    file = fopen(FILE_NAME, "rb"); // Opens a file in read binary mode
    if (file != NULL)
    {
        fseek(file, 0, SEEK_END);                  // Move cursor to the end of the file
        userAmount = ftell(file) / sizeof(t_user); // get amount of users in the file
        rewind(file);                              // Reset the cursor

        fread(*user, sizeof(t_user), userAmount, file); // Copies contents of a file into a stract
        fclose(file);                                   // close the file

        if (userAmount + amount > MAX_USER_AMOUNT) // Check to make sure you dont go over the limit
        {
            (void)printf("Too many users! Maximum allowed is %d.\n", MAX_USER_AMOUNT);
            returnVal = false;
        }
        else
        {
            for (size_t i = userAmount; i < userAmount + amount; i++) // Loops throw students in stack
            {
                (void)printf("Enter Name: ");
                (void)scanf("%s", temp);

                (void)printf("Enter Age: ");
                do
                {
                    if (1 == scanf("%d", &tempAge)) // check if user input is a number
                    {
                        break;
                    }
                    else
                    {
                        (void)printf("Wrong Input! Try Again!\n");
                        getchar();
                    }
                } while (1);

                if (i != 0)
                    (*user)[i].id = (*user)[i - 1].id + 1;
                else
                    (*user)[i].id = userAmount + 1; // Adds 1 to id so it can start from 1 instead of 0

                strcpy((*user)[i].name, temp);
                (*user)[i].age = tempAge;
            }
            userAmount += amount; // Increase the number of students in the file by amount of new students
        }
    }
    else
    {
        printf("Error loading the file!\n");
        fclose(file);
        returnVal = false;
    }

    return returnVal;
}

void addUsersToFile(t_user *user, FILE *file, int amount)
{
    file = fopen(FILE_NAME, "ab"); // Open the file in append binary mode
    if (file != NULL)
    {
        for (size_t i = userAmount - amount; i < userAmount; i++) // Loops throw all new students
        {
            fwrite(&user[i], sizeof(t_user), amount, file); // Writes all new students on the file
        }
        fclose(file); // close the file
    }
    else
    {
        (void)printf("Error opening the file!\n");
        fclose(file);
    }
}

void displayAllUsers(FILE *file, t_user *user, int amount)
{
    file = fopen(FILE_NAME, "rb"); // Opens the file in read binary
    if (file != NULL)
    {
        rewind(file);                              // Resets the cursor
        fread(user, sizeof(t_user), amount, file); // Gets all the students from the file and push them into a struct
        fclose(file);

        (void)printf("ID\tAGE\tNAME\n");
        (void)printf("-----------------------------------------------\n");

        userAmount = getUserAmount(file);
        for (size_t i = 0; i < userAmount; i++) // Loops thro student in stract and print the out
        {
            (void)printf("%d\t%d\t%s \n", user[i].id, user[i].age, user[i].name);
        }
    }
    else
    {
        (void)printf("Error loading the file!\n");
        fclose(file);
    }
}

void deleteUser(FILE *file, t_user *user, int id, int *amount)
{

    file = fopen(FILE_NAME, "rb"); // Opens the file in read binary
    if (file != NULL)
    {
        fread(user, sizeof(t_user), 1, file); // Gets all the students from the file and push them into a struct
        fclose(file);                         // Close the file
    }
    else
    {
        (void)printf("Error loading the file!\n");
        exit(1);
    }

    int deleteIndex = -1;
    for (int i = 0; i < *amount; i++) // Loops throw all people in the struct
    {
        if (user[i].id == id) // Find the wanted student
        {
            deleteIndex = i;
            (void)printf("User ready to delete: %s\n", user[i].name);
            break;
        }
    }

    if (deleteIndex == -1) // Check if the ID entered exist
    {
        (void)printf("User with ID %d not found!\n", id);
        exit(1);
    }

    for (int i = deleteIndex; i < *amount - 1; i++) // Remove the student from the struct
    {
        user[i] = user[i + 1];
    }

    (*amount)--;

    file = fopen(FILE_NAME, "wb"); // Open the file in write binary
    if (file == NULL)
    {
        (void)printf("Error opening the file for writing!\n");
        return;
    }

    fwrite(user, sizeof(t_user), *amount, file); // Overwrite the file with new student struct
    fclose(file);

    (void)printf("User with ID %d has been deleted.\n", id);
}

void modifyUser(FILE *file, t_user *user, int id, int amount)
{
    char temp[BUFFER]; // Temporary val for user input
    int tempAge;       // Temporary val for user input

    file = fopen(FILE_NAME, "rb"); // open the file in read binary
    if (file != NULL)
    {
        fread(user, sizeof(t_user), 1, file); // Gets all the students from the file and push them into a struct
        fclose(file);                         // Close the file

        int updateIndex = -1;

        for (size_t i = 0; i < amount; i++) // Loops throw all students
        {
            if (user[i].id == id) // Enter the edit mode for the wanted student
            {
                (void)printf("Enter the new name you want to rewrite in place of [%d: %s].\n", user[i].id, user[i].name);
                (void)scanf("%s", temp);
                strcpy(user[i].name, temp); // change student name

                (void)printf("Enter the new age you want to rewrite in place of [%d: %d].\n", user[i].id, user[i].age);
                do
                {
                    if (1 == scanf("%d", &tempAge)) // check if user input is a number
                    {
                        user[i].age = tempAge; // change user age
                        break;
                    }
                    else
                    {
                        (void)printf("Wrong Input! Try Again! \n");
                    }
                    getchar();
                } while (1);

                updateIndex = i;
                break;
            }
        }

        if (updateIndex == -1) // check if user inupted valid id
        {
            (void)printf("User with ID %d not found!\n", id);
            return;
        }

        file = fopen(FILE_NAME, "wb"); // Open the file in write binary
        if (file == NULL)
        {
            (void)printf("Error opening the file for writing!\n");
            exit(1);
        }

        fwrite(user, sizeof(t_user), amount, file); // Overwrite the file with new student struct
        fclose(file);
    }
    else
    {
        (void)printf("Error loading the file!\n");
        fclose(file);
        exit(1);
    }

    return;
}

FILE *createFile()
{
    FILE *file = fopen(FILE_NAME, "rb+"); // Open the file if the file already exist
    if (file == NULL)
    {
        file = fopen(FILE_NAME, "wb+"); // Create new file if file doesn't exist
        if (file == NULL)
        {
            (void)printf("Error opening file!\n");
            exit(-1);
        }
    }

    return file;
}

t_user *createUserStract(int size, FILE *file)
{
    t_user *user = (t_user *)malloc(sizeof(t_user) * size); // Create student struct
    if (user == NULL)
    {
        (void)printf("Memory allocation failed!\n");
        fclose(file);
        exit(-1);
    }

    return user;
}

int getUserAmount(FILE *file)
{

    file = fopen(FILE_NAME, "rb"); // Open the file in read binary mode
    if (file != NULL)
    {
        fseek(file, 0, SEEK_END);                  // Move cursor to the end of the file
        userAmount = ftell(file) / sizeof(t_user); // Get amount of users in the file
        fclose(file);                              // close the file
    }
    else
    {
        (void)printf("File dont exist!");
    }

    return userAmount; // returns amount of useres in the file
}