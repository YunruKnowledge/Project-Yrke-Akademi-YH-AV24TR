#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    char name[20];
    int age;
    size_t id;
} student_t;

student_t *students = NULL;  // Pointer for dynamic student array
int studentCount = 0;        // Number of students
size_t nextId = 1;           // Global ID tracker

void addStudent() {
    // Increase memory for the new student
    students = realloc(students, (studentCount + 1) * sizeof(student_t));
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Create the new student
    student_t newStudent;
    newStudent.id = nextId++;
    printf("Enter name: ");
    scanf(" %[^\n]", newStudent.name);
    printf("Enter age: ");
    scanf("%d", &newStudent.age);

    // Add to the array
    students[studentCount++] = newStudent;
    printf("Student added with ID %zu\n", newStudent.id);
}

void deleteStudent() {
    if (studentCount == 0) {
        printf("No students to delete.\n");
        return;
    }

    int id;
    printf("Enter the ID of the student to delete: ");
    scanf("%d", &id);

    int index = -1;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Student with ID %d not found.\n", id);
        return;
    }

    // Shift students to fill the gap
    for (int i = index; i < studentCount - 1; i++) {
        students[i] = students[i + 1];
    }

    // Shrink the array
    students = realloc(students, (studentCount - 1) * sizeof(student_t));
    if (students == NULL && studentCount > 1) {
        printf("Memory reallocation failed!\n");
        exit(1);
    }

    studentCount--;
    printf("Student with ID %d deleted.\n", id);
}

void displayStudents() {
    if (studentCount == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\n--- Student List ---\n");
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %zu, Name: %s, Age: %d\n", students[i].id, students[i].name, students[i].age);
    }
}

void freeMemory() {
    free(students);
    printf("Memory freed. Exiting program.\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Add Student\n2. Delete Student\n3. Display Students\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            deleteStudent();
            break;
        case 3:
            displayStudents();
            break;
        case 4:
            freeMemory();
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
}
