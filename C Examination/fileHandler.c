#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "fileHandler.h"

typedef struct STUDENT
{
    unsigned id;
    char name[BUFFER];
    int age;
} student_t;

int studentAmount = 0;
int id = 0;

bool fileHandler_createStudent(student_t **student, FILE *file)
{
    char tempName[BUFFER];
    int tempAge;

    bool returnVal = true;

    file = fopen(FILE_NAME, "rb");
    if (file != NULL)
    {
        fseek(file, 0, SEEK_END);
        studentAmount = ftell(file) / sizeof(student_t);
        rewind(file);

        fread(*student, sizeof(student_t), studentAmount, file);
        fclose(file);

        if (studentAmount + 1 > MAX_STUDENT_AMOUNT)
        {
            printf("Too many users! Maximum allowed is %d.\n", MAX_STUDENT_AMOUNT);
            returnVal = false;
        }
        else
        {
            for (size_t i = studentAmount; i < studentAmount + 1; i++)
            {
                printf("Enter name for User ID[%zu]: ", i);
                scanf("%s", tempName);

                if (i != 0)
                    (*student)[i].id = (*student)[i - 1].id + 1;
                else
                    (*student)[i].id = studentAmount;

                strcpy((*student)[i].name, tempName);
            }
            studentAmount++;
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

void fileHandler_addStudentsToFile(student_t *student, FILE *file, int amount)
{
    file = fopen(FILE_NAME, "ab");
    if (file != NULL)
    {
        for (size_t i = studentAmount - amount; i < studentAmount; i++)
        {
            fwrite(&student[i], sizeof(student_t), amount, file);
        }
        fclose(file);
        (void)printf("Student successfully created!\n");
    }
    else
    {
        (void)printf("Error opening the file!\n");
    }

    fclose(file);
}

void fileHandler_displayAllStudents(FILE *file, student_t *student, int amount)
{
    file = fopen(FILE_NAME, "rb");
    if (file != NULL)
    {
        if (amount == 0)
        {
            (void)printf("There are no Students in file! \n");
        }
        else
        {
            fread(student, sizeof(student_t), amount, file);

            for (size_t i = 0; i < id; i++)
            {
                (void)printf("ID[%d] student Name: %s \n", student[i].id, student[i].name);
            }
        }
    }
    else
    {
        (void)printf("Error loading the file!\n");
    }

    fclose(file);
}

void fileHandler_deleteStudent(FILE *file, student_t *student, int id, int *amount)
{

    file = fopen(FILE_NAME, "rb");
    if (file != NULL)
    {
        fread(student, sizeof(student_t), *amount, file);
        fclose(file);
    }
    else
    {
        (void)printf("Error loading the file!\n");
        return;
    }

    int deleteIndex = -1;
    for (int i = 0; i < *amount; i++)
    {
        if (student[i].id == id)
        {
            deleteIndex = i;
            (void)printf("Student ready to delete: %s\n", student[i].name);
            break;
        }
    }

    if (deleteIndex == -1)
    {
        (void)printf("Student with ID %d not found!\n", id);
        return;
    }

    for (int i = deleteIndex; i < *amount - 1; i++)
    {
        student[i] = student[i + 1];
    }

    (*amount)--;

    file = fopen(FILE_NAME, "wb");
    if (file == NULL)
    {
        (void)printf("Error opening the file for writing!\n");
        return;
    }

    fwrite(student, sizeof(student_t), *amount, file);
    fclose(file);

    (void)printf("Student with ID %d has been deleted.\n", id);
}

void fileHandler_modifyStudent(FILE *file, student_t *student, int id, int amount)
{
    char tempName[BUFFER];
    int tempAge;

    file = fopen(FILE_NAME, "rb");
    if (file != NULL)
    {
        fread(student, sizeof(student_t), amount, file);
        fclose(file);

        for (size_t i = 0; i < amount; i++)
        {
            if (student[i].id == id)
            {
                (void)printf("Enter the new name you want to rewrite in place of [%d: %s].\n", student[i].id, student[i].name);
                (void)scanf("%s", tempName);

                (void)printf("Enter the new age you want to rewrite in place of [%d: %d].\n", student[i].id, student[i].age);
                (void)scanf("%d", &tempAge);

                strcpy(student[i].name, tempName);
                student[i].age = tempAge;

                break;
            }
        }

        file = fopen(FILE_NAME, "wb");
        if (file == NULL)
        {
            (void)printf("Error opening the file for writing!\n");
            exit(1);
        }

        fwrite(student, sizeof(student_t), amount, file);
        fclose(file);
    }
    else
    {
        (void)printf("Error loading the file!\n");
        exit(1);
    }

    return;
}

FILE *fileHandler_createFile()
{
    FILE *file = fopen(FILE_NAME, "rb+");
    if (file == NULL)
    {
        file = fopen(FILE_NAME, "wb+");
        if (file == NULL)
        {
            (void)printf("Error opening file!\n");
            exit(-1);
        }
    }

    return file;
}

student_t *fileHandler_createStudentStract(int size, FILE *file)
{
    student_t *student = (student_t *)malloc(size * sizeof(student_t));
    if (student == NULL)
    {
        (void)printf("Memory allocation failed!\n");
        fclose(file);
        exit(-1);
    }

    return student;
}

int fileHandler_getStudentAmount(FILE *file)
{

    file = fopen(FILE_NAME, "rb");
    if (file != NULL)
    {
        fseek(file, 0, SEEK_END);
        studentAmount = ftell(file) / sizeof(student_t);
        fclose(file);
    }
    else
    {
        (void)printf("File dont exist!");
        studentAmount = 0;
    }

    return studentAmount;
}