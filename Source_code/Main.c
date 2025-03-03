#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// int ProcessInsertData(void);
// int ProcessUpdateData(void);
// int ProcessDeleteData(void);
// int ProcessSearchData(void);
// int ProcessShowAllData(void);

struct PERSON {
    char ID[11];
    char title_Name[10];
    char first_Name[30];
    char last_Name[30];
    char address[100];
    char tell[22];
}student;

int main() {
    char chMenu;
    do {
        system("cls");
        printf("************ Student Information ************\n\n");
        printf("Please select the number of menu 1-5 \n");
        printf("1) Insert data\n");
        printf("2) Update data\n");
        printf("3) Delete data\n");
        printf("4) Search data\n");
        printf("5) Show all data\n");
        printf("6) Exit\n\n");
        printf("*********************************************\n\n");

        chMenu = _getch();
        system("cls");
        switch (chMenu)
        {
        case '1':
            // ProcessInsertData();
            break;
        case '2':
            // ProcessUpdateData();
            break;
        case '3':
            // ProcessDeleteData();
            break;
        case '4':
            // ProcessSearchData();
            break;
        case '5':
            // ProcessShowAllData();
            break;
        }
    } while(chMenu != '6');

    return 0;
}