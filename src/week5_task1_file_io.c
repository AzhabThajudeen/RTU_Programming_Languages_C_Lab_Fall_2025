// week5_task1_file_io.c
// Task 1: Read and write data from text files
// Week 5 – Files & Modular Programming
// TODO: Fill in the missing parts marked below.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *fp;
    char filename[100];
    char line[256];
    int lineCount = 0;
    printf("Enter filename (or press Enter for default 'data.txt'): ");
    fgets(filename, sizeof(filename), stdin);

    if (filename[0] == '\n') {

        snprintf(filename, sizeof(filename), "data.txt");
    } else {
        // Remove trailing newline from filename
        char *newline = strchr(filename, '\n');
        if (newline) *newline = '\0';
    }

    fp = fopen(filename, "w");

    if (fp == NULL) {
        perror("Error opening file for writing");
        return 1;
    }


    fprintf(fp, "This is line 1: Hello, world!\n");
    fprintf(fp, "This is line 2: File I/O in C is fun.\n");
    fprintf(fp, "This is line 3: Learning modular programming.\n");


    fclose(fp);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        perror("Error opening file for reading");
        return 1;
    }

    printf("\nContents of '%s':\n", filename);
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
        lineCount++; 
    }

    fclose(fp);


    printf("\nTotal lines read: %d\n", lineCount);

    return 0;
}