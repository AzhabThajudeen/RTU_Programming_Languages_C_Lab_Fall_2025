// week5_task2_struct_save_load.c
// Task 2: Save and load structured records from a file
// Week 5 – Files & Modular Programming

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    float gpa;
} Student;

void save_student(Student s, const char *filename);
Student load_student(const char *filename);

int main(void) {
    Student s1; 
    strcpy(s1.name, "Azhab Thajudeen");
    s1.age = 21;
    s1.gpa = 3.75f;

    const char *filename = "student.txt";

    save_student(s1, filename);

    Student s2 = load_student(filename);

    printf("Loaded student:\n");
    printf("Name: %s\n", s2.name);
    printf("Age: %d\n", s2.age);
    printf("GPA: %.2f\n", s2.gpa);

    return 0;
}


void save_student(Student s, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file for writing");
        exit(1);
    }

    fprintf(fp, "%s\n%d\n%.2f\n", s.name, s.age, s.gpa);

    fclose(fp);
    printf("Student data saved to '%s'\n", filename);
}

Student load_student(const char *filename) {
    Student s;
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file for reading");
        exit(1);
    }


    if (fgets(s.name, MAX_NAME_LEN, fp) == NULL) {
        fprintf(stderr, "Error reading name from file\n");
        exit(1);
    }
    s.name[strcspn(s.name, "\n")] = '\0'; 

    if (fscanf(fp, "%d\n%f", &s.age, &s.gpa) != 2) {
        fprintf(stderr, "Error reading age or GPA from file\n");
        exit(1);
    }

    fclose(fp);
    return s;
}