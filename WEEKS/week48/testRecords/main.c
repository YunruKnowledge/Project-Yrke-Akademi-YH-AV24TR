#include <stdio.h>
#include <string.h>

#define FILE_NAME "students.txt"
#define MAX_STUDENTS 100

// Define a struct for student data
typedef struct {
    int id;
    char name[50];
    int age;
} Student;

// Array to store student records
Student students[MAX_STUDENTS];
int studentCount = 0;

// Function prototypes
void loadStudentsFromFile();
void saveStudentsToFile();
void createStudent();
void readStudents();
void updateStudent();
void deleteStudent();
void displayMenu();

int main() {
    loadStudentsFromFile(); // Load existing records from the file at the start

    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createStudent(); break;
            case 2: readStudents(); break;
            case 3: updateStudent(); break;
            case 4: deleteStudent(); break;
            case 5: 
                saveStudentsToFile(); // Save records to the file before exiting
                printf("Exiting program. Goodbye!\n");
                return 0;
            default: 
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void displayMenu() {
    printf("\n--- Student Record System ---\n");
    printf("1. Create Student Record\n");
    printf("2. Read Student Records\n");
    printf("3. Update Student Record\n");
    printf("4. Delete Student Record\n");
    printf("5. Exit\n");
}

void loadStudentsFromFile() {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        // File does not exist; assume no records
        return;
    }

    // Read student records into the array
    fread(&studentCount, sizeof(int), 1, file);
    fread(students, sizeof(Student), studentCount, file);

    fclose(file);
}

void saveStudentsToFile() {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Error: Unable to save records to file.\n");
        return;
    }

    // Write the number of records and the records themselves to the file
    fwrite(&studentCount, sizeof(int), 1, file);
    fwrite(students, sizeof(Student), studentCount, file);

    fclose(file);
}

void createStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Cannot add more students. Maximum limit reached.\n");
        return;
    }

    Student s;
    s.id = studentCount + 1;

    printf("Enter student name: ");
    scanf(" %[^\n]", s.name); // Read input with spaces
    printf("Enter student age: ");
    scanf("%d", &s.age);

    students[studentCount] = s;
    studentCount++;
    printf("Student record created successfully!\n");

    saveStudentsToFile(); // Save changes to the file
}

void readStudents() {
    if (studentCount == 0) {
        printf("No student records found.\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", students[i].id, students[i].name, students[i].age);
    }
}

void updateStudent() {
    int id;
    printf("Enter student ID to update: ");
    scanf("%d", &id);

    if (id < 1 || id > studentCount) {
        printf("Invalid ID. Please try again.\n");
        return;
    }

    printf("Enter new name: ");
    scanf(" %[^\n]", students[id - 1].name);
    printf("Enter new age: ");
    scanf("%d", &students[id - 1].age);

    printf("Student record updated successfully!\n");

    saveStudentsToFile(); // Save changes to the file
}

void deleteStudent() {
    int id;
    printf("Enter student ID to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > studentCount) {
        printf("Invalid ID. Please try again.\n");
        return;
    }

    // Shift remaining students to fill the gap
    for (int i = id - 1; i < studentCount - 1; i++) {
        students[i] = students[i + 1];
    }
    studentCount--;

    printf("Student record deleted successfully!\n");

    saveStudentsToFile(); // Save changes to the file
}
