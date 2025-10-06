/*
 * week4_3_struct_database.c
 * Author: [Azhab.Thajudeen]
 * Student ID: [241ADB047]
 * Description:
 *   Simple in-memory "database" using an array of structs.
 *   Students will use malloc to allocate space for multiple Student records,
 *   then input, display, and possibly search the data.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct Student with fields name, id, grade
struct Student {
    char name[50];
    int id;
    float grade;
};

int main(void) {
    int n;
    struct Student *students = NULL;
    float totalGrade = 0.0f;
    int topIndex = 0;

    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number.\n");
        return 1;
    }

    // Allocate memory for n Student structs using malloc
    students = (struct Student *)malloc(n * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Read student data in a loop
    for (int i = 0; i < n; i++) {
        printf("\n--- Student %d ---\n", i + 1);

        printf("Enter name: ");
        getchar(); // consume leftover newline
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0'; // remove newline

        printf("Enter ID: ");
        scanf("%d", &students[i].id);

        printf("Enter grade: ");
        scanf("%f", &students[i].grade);

        totalGrade += students[i].grade;
        if (students[i].grade > students[topIndex].grade) {
            topIndex = i;
        }
    }

    // Display all student records in formatted output
    printf("\n=== Student Records ===\n");
    printf("%-20s %-10s %-10s\n", "Name", "ID", "Grade");
    printf("------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-20s %-10d %-10.2f\n", students[i].name, students[i].id, students[i].grade);
    }

    // Compute and display average grade
    float average = totalGrade / n;
    printf("\nAverage grade: %.2f\n", average);

    // Display top student
    printf("Top student: %s (ID: %d) with grade %.2f\n",
           students[topIndex].name, students[topIndex].id, students[topIndex].grade);

    // Free allocated memory
    free(students);

    return 0;
}
