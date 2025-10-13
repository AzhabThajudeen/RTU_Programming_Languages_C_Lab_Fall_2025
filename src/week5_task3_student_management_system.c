// week5_task3_student_management_system.c
// Task 3: Mini-project – Student management system with file persistence
// Week 5 – Files & Modular Programming

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50
#define DATA_FILE "students.txt"

typedef struct {
    char name[NAME_LEN];
    int id;
    float gpa;
} Student;

// Function prototypes
int load_students(Student arr[]);
void save_students(Student arr[], int count);
void add_student(Student arr[], int *count);
void list_students(Student arr[], int count);

int main(void) {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    // TODO: Load existing data from file using load_students()
    count = load_students(students);

    printf("%d student(s) loaded from file.\n", count);

    do {
        printf("\n=== Student Management System ===\n");
        printf("1. List students\n");
        printf("2. Add student\n");
        printf("3. Save and Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                // TODO: Call list_students()
                list_students(students, count);
                break;

            case 2:
                // TODO: Call add_student()
                add_student(students, &count);
                break;

            case 3:
                // TODO: Call save_students() and exit loop
                save_students(students, count);
                printf("Data saved. Exiting...\n");
                break;

            default:
                printf("Invalid option. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// TODO: Implement load_students()
// Open DATA_FILE, read records until EOF, return number of records loaded
int load_students(Student arr[]) {
    FILE *fp = fopen(DATA_FILE, "r");
    if (fp == NULL) {
        // File doesn't exist yet — no data to load
        return 0;
    }

    int count = 0;
    while (fscanf(fp, "%d,%49[^,],%f\n",
                  &arr[count].id,
                  arr[count].name,
                  &arr[count].gpa) == 3) {
        count++;
        if (count >= MAX_STUDENTS) break;
    }

    fclose(fp);
    return count;
}

// TODO: Implement save_students()
// Write all students to DATA_FILE
void save_students(Student arr[], int count) {
    FILE *fp = fopen(DATA_FILE, "w");
    if (fp == NULL) {
        perror("Error opening file for writing");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d,%s,%.2f\n", arr[i].id, arr[i].name, arr[i].gpa);
    }

    fclose(fp);
}

// TODO: Implement add_student()
// Read input from user and append to array
void add_student(Student arr[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Cannot add more students (max reached).\n");
        return;
    }

    Student s;

    printf("Enter student ID: ");
    scanf("%d", &s.id);
    getchar(); // consume newline

    printf("Enter student name: ");
    fgets(s.name, NAME_LEN, stdin);
    s.name[strcspn(s.name, "\n")] = '\0'; // remove newline

    printf("Enter GPA: ");
    scanf("%f", &s.gpa);

    arr[*count] = s;
    (*count)++;

    printf("Student added successfully!\n");
}

// TODO: Implement list_students()
// Print all students in readable format
void list_students(Student arr[], int count) {
    if (count == 0) {
        printf("No students found.\n");
        return;
    }

    printf("\n%-10s %-25s %-10s\n", "ID", "Name", "GPA");
    printf("------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-10d %-25s %-10.2f\n",
               arr[i].id, arr[i].name, arr[i].gpa);
    }
}