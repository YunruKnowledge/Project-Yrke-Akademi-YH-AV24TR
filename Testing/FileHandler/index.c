#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "fileHandler.h"

int main(void)
{
    FILE *file = createFile();                              // create file
    t_user *user = createUserStract(MAX_USER_AMOUNT, file); // creat new user

    char menuInput; // temporary menu option
    int userAmount; // to keep track how many users are in the file

    t_user *newUsers = createUserStract(MAX_USER_AMOUNT, file); // all students in the file
    if (newUsers == NULL)
    {
        free(user);
    }

    do
    {
        (void)printf("--- DB --- \n");
        (void)printf("C) Create A Student \n");
        (void)printf("P) Print All Students \n");
        (void)printf("U) Update A Student \n");
        (void)printf("D) Delete A Student \n");
        (void)printf("E) Exit \n");

        (void)scanf("%c", &menuInput);

        if (tolower(menuInput) == 'c') // Create a student 
        {
            if (createUser(&user, file, 1)) // If creating the user was a susses push it to the file
            {
                addUsersToFile(user, file, 1);
            }
        }
        else if (tolower(menuInput) == 'p') // Print all students
        {
            userAmount = getUserAmount(file);
            if (userAmount == 0)
            {
                (void)printf("No user found inside the file!\n");
            }
            else
            {
                displayAllUsers(file, newUsers, userAmount);
            }
        }
        else if (tolower(menuInput) == 'u') // Modify student
        {
            int temp;
            userAmount = getUserAmount(file);
            if (userAmount == 0)
            {
                (void)printf("No user found inside the file!\n");
            }
            else
            {
                bool tempBool = false;
                (void)printf("Write ID of person you want to modify: \n");
                int temp;
                do
                {
                    if (1 == scanf("%d", &temp))
                    {
                        modifyUser(file, newUsers, temp, userAmount);
                        tempBool = true;
                    }
                    else
                    {
                        (void)printf("Wrong input! Try again\n");
                        getchar();
                    }

                } while (!tempBool);
            }
        }
        else if (tolower(menuInput) == 'd') // Delete a student
        {
            userAmount = getUserAmount(file);
            if (userAmount == 0)
            {
                (void)printf("No user found inside the file!\n");
            }
            else
            {
                (void)printf("Write ID of person you want to delete: \n");
                bool tempBool = false;
                int temp;
                do
                {
                    if (1 == scanf("%d", &temp))
                    {
                        deleteUser(file, newUsers, temp, &userAmount);
                        tempBool = true;
                    }
                    else
                    {
                        (void)printf("Wrong input! Try again\n");
                        getchar();
                    }
                } while (!tempBool);
            }
        }
        else if (tolower(menuInput) == 'e') // Exit
        {
            break;
        }
        else
        {
            (void)printf("Wrong Input! \n");
        }
        getchar();
    } while (1);

    // Free the memory
    free(user);
    free(newUsers);

    user = NULL;
    newUsers = NULL;

    return 0;
}
