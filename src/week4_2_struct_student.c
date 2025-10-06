/*
 * week4_2_struct_student.c
 * Author: [Azhab.Thajudeen]
 * Student ID: [241ADB047]
 * Description:
 *   Demonstrates defining and using a struct in C.
 *   Students should define a 'Student' struct with fields like name, id, and grade.
 *   Then create a few instances and print them.
 */

#include <stdio.h>
#include <string.h>

// Define struct Student with fields: name, id, and grade
struct Student {
    char name[50];
    int id;
    float grade;
};

int main(void) {
    struct Student s1;  // Declare one Student variable

    // Assign values manually
    strcpy(s1.name, "Azhab Thajudeen");
    s1.id = 1001;
    s1.grade = 89.5;

    // Print struct contents
    printf("Student Information:\n");
    printf("Name: %s\n", s1.name);
    printf("ID: %d\n", s1.id);
    printf("Grade: %.2f\n", s1.grade);

    return 0;
}