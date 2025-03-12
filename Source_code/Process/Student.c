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
        scanf(" %[^\n]", &student.address);
        printf("Tel : ");
        scanf("%s", &student.tell);

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
    char chkEdit, inEdit;
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
                    printf("~~~~~~~~~~~~~~ Edit Data ~~~~~~~~~~~~~~\n");
                    printf("Student ID : ");
                    scanf("%s", &studentEdit.ID);
                    printf("Title name : ");
                    scanf("%s", &studentEdit.title_Name);
                    printf("First name : ");
                    scanf("%s", &studentEdit.first_Name);
                    printf("Last name : ");
                    scanf("%s", &studentEdit.last_Name);
                    printf("Address : ");
                    scanf(" %[^\n]", &studentEdit.address);
                    printf("Tel : ");
                    scanf("%s", &studentEdit.tell);
                    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
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

int ProcessDeleteData(void) {
    FILE *fp, *fpTemp;
    char chkDelete;
    errno_t err, errTemp;
    struct PERSON student;
    int ioResult, ioResultTemp, isDataFound = 0;
    char studentID[11];
    int index = 0;

    printf("************ Delete data ************\n");
    printf("Student ID:");
    scanf("%s", studentID);

    errTemp = fopen_s(&fpTemp, "./Data/DataStudent.tmp", "w");
    err = fopen_s(&fp, "./Data/DataStudent.txt", "r");
    if (err != 0 && errTemp != 0) {
        printf("Error opening file DataStudent.txt");
    } else {
        do {
            chkDelete = 'n';
            ioResult = fread(&student, sizeof(student), 1, fp);

            if ((ioResult == 1) && (strcmp(studentID, student.ID) == 0)) {
                printf("~~~ Current Data ~~~\n");
                printf("\nStudent ID : %s\n", student.ID);
                printf("Title name : %s\n", student.title_Name);
                printf("First name : %s\n", student.first_Name);
                printf("Last name : %s\n", student.last_Name);
                printf("Address : %s\n", student.address);
                printf("Tell : %s\n", student.tell);

                printf("\nDo you want to delete data (y/n) ?\n");
                chkDelete = _getch();

                isDataFound = 1;
            }
            if (chkDelete == 'n' && ioResult != 0) {
                ioResultTemp = fwrite(&student, sizeof(student), 1, fpTemp);
                if (ioResultTemp != 1) {
                    printf("Error writing file DataStudent.tmp\n");
                }
            }
            index++;
        } while (ioResult != 0);

        if (fclose(fp) != 0) {
            printf("Error closing file DataStudent.txt");
        }
        if (fclose(fpTemp) == EOF) {
            printf("Error closing file DataStudent.tmp");
        }

        if (isDataFound == 0) {
            printf("Data is not found.");
            remove("./Data/DataStudent.tmp");
        } else {
            remove("./Data/DataStudent.txt");
            rename("./Data/DataStudent.tmp","./Data/DataStudent.txt");
        }
    }
    return 0;
}

int ProcessSearchData(void) {
    FILE *fp;
    errno_t err;
    struct PERSON student;
    int ioResult, isDataFound = 0;
    char studentID[11], chOut;

    printf("************ Search data ************\n");
    printf("Student ID :");
    scanf("%s", studentID);
    
    err = fopen_s(&fp, "./Data/DataStudent.txt", "r");
    if (err != 0) {
        printf("Error opening file DataStudent.txt");
    } else {
        do {
            ioResult = fread(&student, sizeof(student), 1, fp);

            if ((ioResult == 1) && (strcmp(studentID, student.ID) == 0)) {
                printf("\nStudent ID : %s\n", student.ID);
                printf("Title name : %s\n", student.title_Name);
                printf("First name : %s\n", student.first_Name);
                printf("Last name : %s\n", student.last_Name);
                printf("Address : %s\n", student.address);
                printf("Tell : %s\n", student.tell);
                isDataFound = 1;
                printf("\n(e) for exit the menu ?\n");
                chOut = _getch();
            } else if (isDataFound == 0) {
                printf("Data is not found.");
                chOut = 'e';
            }
        } while (ioResult != 0 && chOut != 'e');

        if (fclose(fp) == EOF) {
            printf("Error closing file DataStudent.txt");
        }
    }
    return 0;
}

int ProcessShowAllData(void) {
    FILE *fp;
    errno_t err;
    struct PERSON student;
    char chkExit;
    int ioResult;

    printf("************ Show all data ************\n");

    err = fopen_s(&fp, "./Data/DataStudent.txt", "r");
    if (err != 0) {
        printf("Error opening file DataStudent.txt");
    } else {
        do {
            do {
                ioResult = fread(&student, sizeof(student), 1, fp);
                if (ioResult == 1) {
                    printf("\nStudent ID : %s\n", student.ID);
                    printf("Title name : %s\n", student.title_Name);
                    printf("First name : %s\n", student.first_Name);
                    printf("Last name : %s\n", student.last_Name);
                    printf("Address : %s\n", student.address);
                    printf("Tell : %s\n", student.tell);
                }
            } while (ioResult != 0 );
            printf("\n(e) for exit the menu ?\n");
            chkExit = _getch();
        } while (chkExit != 'e');

        if (fclose(fp) == EOF) {
            printf("Error closing file DataStudent.txt");
        }
    }
    return 0;
}