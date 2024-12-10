#include "fileHandler.h"
#include <ctype.h>
#include <stdio.h>

int main(void)
{
    char menuInput;

    FILE *file = fileHandler_createFile();
    student_t *newStudent = fileHandler_createStudentStract(MAX_STUDENT_AMOUNT, file);
    student_t *studentsInTheFile = fileHandler_createStudentStract(fileHandler_getStudentAmount(file), file);

    do
    {
        (void)printf("---MENU--- \n");
        (void)printf("C) Create A Student--- \n");
        (void)printf("P) Print All Students--- \n");
        (void)printf("U) Update A Student--- \n");
        (void)printf("D) Delete A Student--- \n");
        (void)printf("E) Exit--- \n");
        (void)scanf("%c", &menuInput);

        if (tolower(menuInput) == 'c')
        {
            if (fileHandler_createStudent(&newStudent, file))
                fileHandler_addStudentsToFile(newStudent, file, 1);
            else
                (void)printf("Failed to create a student\n");
        }
        else if (tolower(menuInput) == 'p')
        {
            int amount = fileHandler_getStudentAmount(file);
            fileHandler_displayAllStudents(file, studentsInTheFile, amount);
        }
        else if (tolower(menuInput) == 'u')
        {
            int tempID;
            bool goodInput = false;
            (void)printf("Enter an ID of a student you want to update! \n");
            do
            {
                if (1 == scanf("%d", &tempID))
                {
                    fileHandler_modifyStudent(file, newStudent, tempID, fileHandler_getStudentAmount(file));
                    goodInput = true;
                }
                else
                {
                    (void)printf("WRONG INPUT!\n");
                }
            } while (!goodInput);
        }
        else if (tolower(menuInput) == 'd')
        {
            int tempID;
            int amount = fileHandler_getStudentAmount(file);
            bool goodInput = false;
            (void)printf("Enter an ID of a student you want to delete! \n");
            do
            {
                if (1 == scanf("%d", &tempID))
                {
                    fileHandler_deleteStudent(file, newStudent, tempID, &amount);
                    goodInput = true;
                }
                else
                {
                    (void)printf("WRONG INPUT!\n");
                }
            } while (!goodInput);
        }
        else if (tolower(menuInput) == 'e')
        {
            break;
        }
        else
        {
            (void)printf("WRONG INPUT! Please refer to menu below\n");
        }
        getchar();
    } while (1);
}