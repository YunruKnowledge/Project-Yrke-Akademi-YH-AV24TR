#include <stdio.h>
#include "student.h"

// #define FILE_NAME "student.bin"
#define MAX_NAME 32
// #define MAX_STUDENTS 9

typedef struct student
{
    // 20 bytes
    char name[MAX_NAME];
    // 6 bytes
    size_t age;
    // 6
    size_t id;
} student_t;

int main()
{
    char choice;
    int choiceNum;

    while (1)
    {
        loadStudentfromFile();
        displayMenu();

        // pick a choice
        printf("\nMake a choice: ");
        scanf(" %c", &choice);

        if (choiceConverter(choice) < 1 || choiceConverter(choice) > 5)
        {
            printf("\n**** Wrong, must enter one of the following mode: ****");
            continue;
        }
        else
        {
            choiceNum = choiceConverter(choice);
        }

        /*
                if (choice == 'c' || choice == 'C')
                {
                    choiceNum = 1;
                }
                else if (choice == 'p' || choice == 'P')
                {
                    choiceNum = 2;
                }
                else if (choice == 'u' || choice == 'U')
                {
                    choiceNum = 3;
                }
                else if (choice == 'd' || choice == 'D')
                {
                    choiceNum = 4;
                }
                else if (choice == 'e' || choice == 'E')
                {
                    choiceNum = 5;
                }
                else
                {
                    printf("\n**** Wrong, must enter one of the following mode: ****");
                    continue;
                }
        */

        switch (choiceNum)
        {
        case 1:
            // printf("\n********* Soufien says: CREATE! *********\n");
            createUser();
            break;
        case 2:
            // printf("\n********* Soufien says: PRINT! *********\n");
            readStudents();
            break;
        case 3:
            // printf("\n********* Soufien says: UPDATE! *********\n");
            updateStudent();
            break;
        case 4:
            // printf("\n********* Soufien says: DELETE! *********\n");
            deleteStudent();
            break;
        case 5:
            // printf("\n********* Soufien says: EXIT & SAVE! *********\n");
            saveToFile();
            return 0;

        default:
            printf("Wrong input!\n");
            break;
        }
    }
}
