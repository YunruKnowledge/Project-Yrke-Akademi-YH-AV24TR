#include <stdio.h>

/*
    fwrite and fread for binary data reading and storing.
*/

#define MAX_NAME 20
#define MAX_STUDENTS 4
#define FILE_NAME "studentData.bin"

typedef struct student
{
    char name[MAX_NAME];
    size_t age;
    size_t id;
} student_t;

student_t students[MAX_STUDENTS];
// global variable, amount of students.
int studentCount = 0;
// menu
void displayMenu();
// load student from the file.
void loadStudentfromFile();
// Save the data into the document.
void saveToFile();

void createUser();

void readStudents();

void updateStudent();

void deleteStudent();

int main(void)
{
    /* FILE *fptr = fopen("test.txt", "w");

     if (fptr == NULL)
     {
         printf("Problem sir, write acccess denied!");
     }

     char str[] = "FUMOS ARE BEST";
     int age = 21;

     // write into the file.
     fprintf(fptr, "The string: %s\nThe age: %i", str, age);
     fclose(fptr);

     FILE *fptrr = fopen("test.txt", "r");

     if (fgets(str, 14, fptrr) != NULL)
     {
         // fputs(str, stdout);
         printf("%s", str);
     }

     fclose(fptrr);
 */
    student_t student1;

    createUser();
    createUser();

    readStudents();

    return 0;
}

void loadStudentfromFile()
{
    FILE *file = fopen(FILE_NAME, "rb");

    if (file == NULL)
    {
        return;
    }
    // fread(AmountofStudents: 3, 4bytes, [reading]1 integer, source: file )
    // int oldugu icin &addressi veriliyor.
    fread(&studentCount, sizeof(int), 1, file);
    // fread(stores data in the students array, reads bytes equal to the size of a Student struct)
    fread(students, sizeof(students), studentCount, file);

    fclose(file);
}

void saveToFile()
{
    FILE *file = fopen(FILE_NAME, "wb");

    if (file == NULL)
    {
        printf("ERROR -> File doesn't exist!");
        return;
    }
    else
    {
        printf("File created!");
    }

    // write into the file the amount of students.
    fwrite(&studentCount, sizeof(int), 1, file);
    // write into the file the structs of students.
    fwrite(students, sizeof(students), studentCount, file);

    fclose(file);
}

void createUser()
{
    if (studentCount >= MAX_STUDENTS)
    {
        printf("CANNOT ADD MORE, LIMIT REACHED!");
        return;
    }

    student_t tempStudent;

    tempStudent.id = studentCount + 1;

    printf("Enter student name:\n");
    scanf("%[^\n]", tempStudent.name); // to take in he spaces too.

    printf("Enter student age:\n");
    scanf(" %d", &tempStudent.age);

    students[studentCount] = tempStudent;
    studentCount++;
    printf("Student record has been created!");

    saveToFile();
}

void readStudents()
{
    if (studentCount == 0)
    {
        printf("NO STUDENT FOUND!");
        return;
    }

    for (int i = 0; i <= MAX_STUDENTS; i++)
    {
        printf("\n~~~STUDENTS~~~\n");
        printf("\t\nID: %u\nName: %s\nAge: %u\n\n", students[i].id, students[i].name, students[i].age);
    }
}

void updateStudent()
{
    int id;
    printf("Enter ID of the student you want to update");
    scanf("%d", &id);

    if (id < 1 || id > studentCount)
    {
        printf("Wrong ID, Try again!");
        return;
    }

    printf("Enter new name:\n");
    scanf(" %[^\n]", students[id - 1].name);
    printf("Enter new age:\n");
    scanf("%d", &students[id - 1].age);

    printf("Updated to new credantials succcesfully!");

    saveToFile();
}

void deleteStudent()
{
    
}

void displayMenu()
{
    printf("\n--- Student Record System ---\n");
    printf("1. Create Student Record\n");
    printf("2. Read Student Records\n");
    printf("3. Change Student Record\n");
    printf("4. Delete Student Record\n");
    printf("5. Exit\n");
}
