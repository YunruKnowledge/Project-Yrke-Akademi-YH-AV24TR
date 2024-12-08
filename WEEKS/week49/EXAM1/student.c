#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "student.h"

#define FILE_NAME "student.bin"
#define MAX_NAME 32
#define MAX_STUDENTS 20

typedef struct student
{
    // 20 bytes
    char name[MAX_NAME];
    // 6 bytes
    size_t age;
    // 6
    size_t id;
} student_t;

// global variable, amount of students.
int studentCount = 0;   // total students
int newIdCounter = 1;   // All students and deleted
int deletedCounter = 1; // deleted students

// array of students
student_t students[MAX_STUDENTS];

void loadStudentfromFile()
{
    FILE *file = fopen(FILE_NAME, "rb");

    if (file == NULL)
    {
        printf("ERROR -> Couldn't load from file, or the file doesn't exist!\n\nTry to create a student first to create a file.");
        return;
    }
    // fread(AmountofStudents: 3, 4bytes, [reading]1 integer, source: file )
    // int oldugu icin &addressi veriliyor.
    fread(&studentCount, sizeof(int), 1, file);
    // read the newIDcounter from file so that it can be tracked in the file.
    fread(&newIdCounter, sizeof(int), 1, file);
    // fread(stores data in the students array, reads bytes equal to the size of a Student struct)
    fread(students, sizeof(student_t), studentCount, file);

    fclose(file);
}

void saveToFile()
{
    FILE *file = fopen(FILE_NAME, "wb");

    if (file == NULL)
    {
        printf("ERROR -> COULDN'T CREATE FILE!");
        return;
    }

    // write into the file the amount of students.
    fwrite(&studentCount, sizeof(int), 1, file);
    // write the new ID counter that tracks the ids, so that even if user is deleted its id won't be used.
    fwrite(&newIdCounter, sizeof(int), 1, file);
    // write into the file the structs of students.
    fwrite(students, sizeof(student_t), studentCount, file);

    fclose(file);
}

void createUser()
{
    if (studentCount >= MAX_STUDENTS)
    {
        printf("CANNOT ADD MORE, STUDENT LIMIT REACHED!");
        return;
    }

    student_t tempStudent;
    char tempAge[3];

    printf("Enter student name:\n");
    scanf(" %[^\n]", tempStudent.name); // to take in he spaces too.

    printf("Enter student age:\n");
    scanf(" %s", &tempAge);
    /**/

    for (int i = 0; i <= 3; i++)
    {
        if ( !isdigit(tempAge[i] ))
        {
            printf("\n\n*** The input is not an age, exiting the application ***");
            exit(1);
        }
    }

    tempStudent.age = strtoul(tempAge, NULL, 3);
    tempStudent.id = newIdCounter; // The new student gets the available new ID.

    students[studentCount] = tempStudent;
    newIdCounter++; // To get a new ID(For identification)
    studentCount++; // Total user counter.
    printf("Student record has been created!");

    saveToFile();
}

void readStudents()
{
    if (studentCount == 0)
    {
        printf("NO STUDENT FOUND!\n");
        return;
    }

    printf("\nID    Age     Name\n");
    printf("==============================");
    for (int i = 0; i < studentCount; i++)
    {
        printf("\n%lu     %lu      %s\n", students[i].id, students[i].age, students[i].name);
    }
}

void updateStudent()
{
    int id;
    // int tempDeleted = deletedCounter + 1;

    printf("Enter ID of the student you want to update: ");
    scanf(" %d", &id);

    if (id < 1 || id > studentCount)
    {
        printf("Wrong ID, Try again!");
        return;
    }

    printf("Enter new name:\n");
    scanf(" %[^\n]", students[id - 1].name);
    printf("Enter new age:\n");
    scanf(" %lu", &students[id - 1].age);

    printf("Updated to new credantials succcesfully!");

    saveToFile();
}

void deleteStudent()
{
    int id; // Hold ID user wants to delete.

    printf("Give id of the student to delete:\n");
    scanf(" %i", &id);

    int index = -1;
    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].id == id)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        printf("The student with the id %i was not found!", id);
        return;
    }

    // id 1, [id 2], id 3,
    // Go one step before the given ID by the user, then starting from the, we move the ids of the other students back to the rest using for loop.

    for (int i = index; i < studentCount - 1; i++) // shift students left
    {
        students[i] = students[i + 1];
    }

    // move students one step left, and remove the last spot because student isn't thered
    studentCount--;
    deletedCounter++;

    saveToFile();
}

void displayMenu()
{
    printf("\n\n======== DB =========\n");
    printf("C. Create A Student\n");
    printf("P. Print ALL Sudents\n");
    printf("U. Update A Student\n");
    printf("D. Delete A Student\n");
    printf("E. Exit\n");
}

int choiceConverter(char choice)
{
    int choiceNum;
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
    return choiceNum;
}
