#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int ProcessInsertData(void);
int ProcessUpdateData(void);
int ProcessDeleteData(void);
int ProcessSearchData(void);
int ProcessShowAllData(void);

struct PERSON {
    char ID[11];
    char title_Name[10];
    char first_Name[30];
    char last_Name[30];
    char address[100];
    char tell[22];
}student;

int ProcessInsertData(void) {
    FILE *  fp;
    errno_t err;
    struct PERSON student;
    int ioResult;

    printf("************ Insert data ************\n");
    
    err = fopen_s(&fp, "./Data/DataStudent.txt", "a");
    if (err != 0) {
        printf("Error opening file DataStudent.txt\n");
    } else {
        printf("Student ID : ");
        scanf("%s", &student.ID);
        printf("Title name : ");
        scanf("%s", &student.title_Name);
        printf("First name : ");
        scanf("%s", &student.first_Name);
        printf("Last name : ");
        scanf("%s", &student.last_Name);
        printf("Address : ");
        getchar();
        fgets(student.address, sizeof(student.address), stdin);
        student.address[strcspn(student.address, "\n")] = 0;
        printf("Tel : ");
        scanf("%s", &student.address);

        ioResult = fwrite(&student, sizeof(student), 1, fp);

        if (ioResult != 1) {
            printf("Error writing file DataStudent.txt\n");
        }

        if (fclose(fp) == EOF) {
            printf("Error closing file DataStudent.txt");
        }
    }
    return 0;
}

int ProcessUpdateData(void) {
    FILE *fp;
    char chkEdit;
    char inEdit[30];
    errno_t err;
    struct PERSON student;
    int ioResult, isDataFound = 0;
    char studentID[11];
    struct PERSON studentEdit;
    int index = 0;

    printf("************ Update data ************\n");
    printf("Student ID :");
    scanf("%s", studentID);
    err = fopen_s(&fp,  "./Data/DataStudent.txt", "r+");
    if (err != 0) {
        printf("Error opening file DataStudent.txt");
    } else {
        do {
            ioResult = fread(&student, sizeof(student), 1, fp);

            if ((ioResult == 1) && (strcmp(studentID, student.ID) == 0)) {
                printf("~~~ Current Data ~~~\n");
                printf("\nStudent ID : %s\n", student.ID);
                printf("Title name : %s\n", student.title_Name);
                printf("First name : %s\n", student.first_Name);
                printf("Last name : %s\n", student.last_Name);
                printf("Address : %s\n", student.address);
                printf("Tel : %s\n", student.tell);

                printf("\nDo you want to edit data (y/n) ?\n");
                chkEdit = _getch();
                if (chkEdit == 'y') {
                    fseek(fp, (index) * sizeof(student), SEEK_SET);

                    printf("\n~~~ Edit Data ~~~\n");
                    // inEdit = gets();
                    printf("Student ID : ");
                    scanf("%s", &studentEdit.ID);
                    printf("Title name : ");
                    scanf("%s", &studentEdit.title_Name);
                    printf("First name : ");
                    scanf("%s", &studentEdit.first_Name);
                    printf("Last name : ");
                    scanf("%s", &studentEdit.last_Name);
                    printf("Address : ");
                    getchar();
                    fgets(studentEdit.address, sizeof(studentEdit.address), stdin);
                    studentEdit.address[strcspn(studentEdit.address, "\n")] = 0;
                    printf("Tel : ");
                    scanf("%s", &studentEdit.address);

                    ioResult = fwrite(&studentEdit, sizeof(studentEdit), 1, fp);
                    if (ioResult != 1) {
                        printf("Error writing file DataStudent.txt\n");
                    }
                }
                isDataFound = 1;
                break;
            }
            index++;
        } while (ioResult != 0);

        if (isDataFound == 0) {
            printf("Data is not found.");
        }
        if (fclose(fp) == EOF) {
            printf("Error closing file DataStudent.txt");
        }
    }
    return 0;
}