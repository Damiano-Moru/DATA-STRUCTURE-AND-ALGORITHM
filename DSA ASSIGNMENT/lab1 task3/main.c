#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 40
#define MAX_COURSES 2

struct Course {
    char course_code[10];
    char course_name[50];
};

struct Grade {
    int mark;
    char the_grade;
};

struct Student {
    char registration_number[20];
    char name[50];
    int age;
    struct Course courses[MAX_COURSES];
    struct Grade grades[MAX_COURSES];
    int grades_calculated;
};

void addStudent(struct Student students[], int *num_students);
void editStudentDetails(struct Student students[], int num_students);
void addMarksAndCalculateGrades(struct Student students[], int num_students);
void displayStudentDetails(const struct Student students[], int num_students);
int findStudentIndex(const struct Student students[], int num_students, const char *reg_number);

int main() {
    struct Student students[MAX_STUDENTS];
    int num_students = 0;

    char choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add a student\n");
        printf("2. Edit a student's details\n");
        printf("3. Add marks and calculate grades\n");
        printf("4. Display student details\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                addStudent(students, &num_students);
                printf("Student added successfully.\n");
                break;
            case '2':
                editStudentDetails(students, num_students);
                break;
            case '3':
                addMarksAndCalculateGrades(students, num_students);
                printf("Marks added and grades calculated successfully.\n");
                break;
            case '4':
                displayStudentDetails(students, num_students);
                break;
            case '5':
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != '5');

    return 0;
}

void addStudent(struct Student students[], int *num_students) {
    if (*num_students < MAX_STUDENTS) {
        struct Student newStudent;
        printf("Enter registration number: ");
        scanf("%s", newStudent.registration_number);
        printf("Enter name: ");
        scanf("%s", newStudent.name);
        printf("Enter age: ");
        scanf("%d", &newStudent.age);

        for (int i = 0; i < MAX_COURSES; i++) {
            printf("Enter course code for course %d: ", i + 1);
            scanf("%s", newStudent.courses[i].course_code);
            printf("Enter course name for course %d: ", i + 1);
            scanf("%s", newStudent.courses[i].course_name);
        }

        students[*num_students] = newStudent;
        (*num_students)++;
    } else {
        printf("Maximum number of students reached.\n");
    }
}

void editStudentDetails(struct Student students[], int num_students) {
    char reg_number[20];
    printf("Enter registration number of the student to edit: ");
    scanf("%s", reg_number);

    int studentIndex = findStudentIndex(students, num_students, reg_number);
    if (studentIndex != -1) {
        printf("Enter new registration number: ");
        scanf("%s", students[studentIndex].registration_number);
        printf("Enter new name: ");
        scanf("%s", students[studentIndex].name);
        printf("Enter new age: ");
        scanf("%d", &students[studentIndex].age);
        printf("Student details edited successfully.\n");
    } else {
        printf("Student not found.\n");
    }
}

void addMarksAndCalculateGrades(struct Student students[], int num_students) {
    char reg_number[20];
    printf("Enter registration number of the student to add marks: ");
    scanf("%s", reg_number);

    int studentIndex = findStudentIndex(students, num_students, reg_number);
    if (studentIndex != -1) {
        for (int i = 0; i < MAX_COURSES; i++) {
            printf("Enter mark for course %d: ", i + 1);
            scanf("%d", &students[studentIndex].grades[i].mark);
            // Calculate grade based on the grading system
            if (students[studentIndex].grades[i].mark > 69) {
                students[studentIndex].grades[i].the_grade = 'A';
            } else if (students[studentIndex].grades[i].mark > 59) {
                students[studentIndex].grades[i].the_grade = 'B';
            } else if (students[studentIndex].grades[i].mark > 49) {
                students[studentIndex].grades[i].the_grade = 'C';
            } else if (students[studentIndex].grades[i].mark > 39) {
                students[studentIndex].grades[i].the_grade = 'D';
            } else {
                students[studentIndex].grades[i].the_grade = 'E';
            }
        }
        students[studentIndex].grades_calculated = 1;  // Set grades as calculated
    } else {
        printf("Student not found.\n");
    }
}

void displayStudentDetails(const struct Student students[], int num_students) {
    char reg_number[20];
    printf("Enter registration number of the student to display details: ");
    scanf("%s", reg_number);

    int studentIndex = findStudentIndex(students, num_students, reg_number);
    if (studentIndex != -1) {
        printf("\nStudent Details:\n");
        printf("Registration Number: %s\n", students[studentIndex].registration_number);
        printf("Name: %s\n", students[studentIndex].name);
        printf("Age: %d\n", students[studentIndex].age);

        for (int i = 0; i < MAX_COURSES; i++) {
            printf("Course %d:\n", i + 1);
            printf("  Code: %s\n", students[studentIndex].courses[i].course_code);
            printf("  Name: %s\n", students[studentIndex].courses[i].course_name);

            if (students[studentIndex].grades_calculated) {
                printf("  Grade: %c\n", students[studentIndex].grades[i].the_grade);
            } else {
                printf("  Grade not calculated yet.\n");
            }
        }
    } else {
        printf("Student not found.\n");
    }
}

int findStudentIndex(const struct Student students[], int num_students, const char *reg_number) {
    for (int i = 0; i < num_students; i++) {
        if (strcmp(students[i].registration_number, reg_number) == 0) {
            return i;
        }
    }
    return -1;  // Not found
}
