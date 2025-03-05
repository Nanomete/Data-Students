#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "./Process/Student.c"

int main() {
    char chMenu;
    do {
        system("cls"); // clear display
        printf("************ Student Information ************\n\n");
        printf("Please select the number of menu 1-5 \n");
        printf("1) Insert data\n");
        printf("2) Update data\n");
        printf("3) Delete data\n");
        printf("4) Search data\n");
        printf("5) Show all data\n");
        printf("6) Exit\n\n");
        printf("*********************************************\n\n");

        chMenu = _getch(); // input value from keyboard
        system("cls"); // clear display
        switch (chMenu)
        {
        case '1':
            ProcessInsertData();
            break;
        case '2':
            ProcessUpdateData();
            break;
        case '3':
            ProcessDeleteData();
            break;
        case '4':
            ProcessSearchData();
            break;
        case '5':
            ProcessShowAllData();
            break;
        }
    } while(chMenu != '6');

    return 0;
}