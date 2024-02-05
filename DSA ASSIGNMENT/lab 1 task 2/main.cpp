#include <iostream>
#include <iomanip>
#include <cstring>

const int MAX_STUDENTS = 40;
const int MAX_COURSES = 2;  // Assuming each student is enrolled in at most 2 courses

struct Course {
    std::string course_code;
    std::string course_name;
};

struct Grade {
    int mark;
    char the_grade;
};

struct Student {
    std::string registration_number;
    std::string name;
    int age;
    Course courses[MAX_COURSES];
    Grade grades[MAX_COURSES];
    bool grades_calculated[MAX_COURSES];
};

// Function prototypes
int findStudentIndex(const Student students[], int num_students, const std::string& reg_number);
void displayStudent(const Student& student);
void editStudentDetails(Student& student);
void addMarksAndCalculateGrades(Student& student, int course_index);

int main() {
    Student students[MAX_STUDENTS];
    int num_students = 0;

    char choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add a student\n";
        std::cout << "2. Edit a student's details\n";
        std::cout << "3. Add marks and calculate grades\n";
        std::cout << "4. Display student details\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1': {
                if (num_students < MAX_STUDENTS) {
                    Student newStudent;
                    std::cout << "Enter registration number: ";
                    std::cin >> newStudent.registration_number;
                    std::cout << "Enter name: ";
                    std::cin.ignore();  // Ignore newline from previous input
                    std::getline(std::cin, newStudent.name);
                    std::cout << "Enter age: ";
                    std::cin >> newStudent.age;

                    // Assuming each student is enrolled in at most 2 courses
                    for (int i = 0; i < MAX_COURSES; i++) {
                        std::cout << "Enter course code for course " << i + 1 << ": ";
                        std::cin >> newStudent.courses[i].course_code;
                        std::cout << "Enter course name for course " << i + 1 << ": ";
                        std::cin.ignore();  // Ignore newline from previous input
                        std::getline(std::cin, newStudent.courses[i].course_name);
                        newStudent.grades_calculated[i] = false;  // Initial grades not calculated
                    }

                    students[num_students++] = newStudent;
                    std::cout << "Student added successfully.\n";
                } else {
                    std::cout << "Maximum number of students reached.\n";
                }
                break;
            }
            case '2': {
                std::string reg_number;
                std::cout << "Enter registration number of the student to edit: ";
                std::cin >> reg_number;

                int studentIndex = findStudentIndex(students, num_students, reg_number);
                if (studentIndex != -1) {
                    editStudentDetails(students[studentIndex]);
                    std::cout << "Student details edited successfully.\n";
                } else {
                    std::cout << "Student not found.\n";
                }
                break;
            }
            case '3': {
                std::string reg_number;
                std::cout << "Enter registration number of the student to add marks: ";
                std::cin >> reg_number;

                int studentIndex = findStudentIndex(students, num_students, reg_number);
                if (studentIndex != -1) {
                    for (int i = 0; i < MAX_COURSES; i++) {
                        if (!students[studentIndex].grades_calculated[i]) {
                            addMarksAndCalculateGrades(students[studentIndex], i);
                            students[studentIndex].grades_calculated[i] = true;  // Set grades as calculated
                        }
                    }
                    std::cout << "Marks added and grades calculated successfully.\n";
                } else {
                    std::cout << "Student not found.\n";
                }
                break;
            }
            case '4': {
                std::string reg_number;
                std::cout << "Enter registration number of the student to display details: ";
                std::cin >> reg_number;

                int studentIndex = findStudentIndex(students, num_students, reg_number);
                if (studentIndex != -1) {
                    displayStudent(students[studentIndex]);
                } else {
                    std::cout << "Student not found.\n";
                }
                break;
            }
            case '5':
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != '5');

    return 0;
}

// Function to find the index of a student in the array
int findStudentIndex(const Student students[], int num_students, const std::string& reg_number) {
    for (int i = 0; i < num_students; i++) {
        if (students[i].registration_number == reg_number) {
            return i;
        }
    }
    return -1;  // Not found
}

// Function to display details of a student
void displayStudent(const Student& student) {
    std::cout << "\nStudent Details:\n";
    std::cout << "Registration Number: " << student.registration_number << "\n";
    std::cout << "Name: " << student.name << "\n";
    std::cout << "Age: " << student.age << "\n";

    for (int i = 0; i < MAX_COURSES; i++) {
        std::cout << "Course " << i + 1 << ":\n";
        std::cout << "  Code: " << student.courses[i].course_code << "\n";
        std::cout << "  Name: " << student.courses[i].course_name << "\n";

        if (student.grades_calculated[i]) {
            std::cout << "  Grade: " << student.grades[i].the_grade << "\n";
        } else {
            std::cout << "  Grade not calculated yet.\n";
        }
    }
}

// Function to edit details of a student
void editStudentDetails(Student& student) {
    std::cout << "Enter new registration number: ";
    std::cin >> student.registration_number;
    std::cout << "Enter new name: ";
    std::cin.ignore();  // Ignore newline from previous input
    std::getline(std::cin, student.name);
    std::cout << "Enter new age: ";
    std::cin >> student.age;
}

// Function to add marks and calculate grades for a course
void addMarksAndCalculateGrades(Student& student, int course_index) {
    std::cout << "Enter mark for course " << course_index + 1 << ": ";
    std::cin >> student.grades[course_index].mark;

    // Calculate grade based on the grading system
    if (student.grades[course_index].mark > 69) {
        student.grades[course_index].the_grade = 'A';
    } else if (student.grades[course_index].mark > 59) {
        student.grades[course_index].the_grade = 'B';
    } else if (student.grades[course_index].mark > 49) {
        student.grades[course_index].the_grade = 'C';
    } else if (student.grades[course_index].mark > 39) {
        student.grades[course_index].the_grade = 'D';
    } else {
        student.grades[course_index].the_grade = 'E';
    }
}
