

typedef struct student
{
    // 20 bytes
    char name[MAX_NAME];
    // 6 bytes
    size_t age;
    // 6
    size_t id;
} student_t;



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
    fread(students, sizeof(student_t), studentCount, file);

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

    // write into the file the amount of students.
    fwrite(&studentCount, sizeof(int), 1, file);
    // write into the file the structs of students.
    fwrite(students, sizeof(student_t), studentCount, file);

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

    tempStudent.id = newIdCounter + 1;

    printf("Enter student name:\n");
    scanf(" %[^\n]", tempStudent.name); // to take in he spaces too.

    printf("Enter student age:\n");
    scanf(" %lu", &tempStudent.age);

    students[studentCount] = tempStudent;
    studentCount++;
    newIdCounter++; // To get a new ID(For identification)
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

    printf("\n~~~STUDENTS~~~\n");
    for (int i = 0; i < studentCount; i++)
    {
        printf("\t\nID: %lu\nName: %s\nAge: %lu\n\n", students[i].id, students[i].name, students[i].age);
    }
}

void updateStudent()
{
    size_t id;
    printf("Enter ID of the student you want to update");
    scanf("%lu", &id);

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
    int id;
    printf("Give id");
    scanf(" %d", &id);

    if (id < 1 || id > studentCount)
    {
        printf("Out of the limits");
        return;
    }

    // id 1, [id 2], id 3,
    // take id, one step less,
    for (int i = id - 1; i < studentCount; i++)
    {
        students[i] = students[i + 1];
    }

    studentCount--;
    saveToFile();
}

void displayMenu()
{
    printf("\n\n--- Student Record System ---\n");
    printf("1. Create Student Record\n");
    printf("2. Read Student Records\n");
    printf("3. Change Student Record\n");
    printf("4. Delete Student Record\n");
    printf("5. Exit\n\n");
}
