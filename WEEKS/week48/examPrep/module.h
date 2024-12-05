#ifndef MODULE_H
#define MODULE_H

typedef struct student
{
} student_t;

student_t students[MAX_STUDENTS];
// global variable, amount of students.
int studentCount = 0;
int newIdCounter = 0;
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

#endif //MODULE_H