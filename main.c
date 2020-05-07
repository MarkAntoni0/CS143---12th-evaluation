//  main.c
//  CS143 - 12th evaluation
//  Created by Mark Antonio on 5/7/20.
//  Copyright © 2020 Mark Antonio. All rights reserved.

#include <stdio.h>

typedef struct {
    int ID;
    float Salary;
}Employee;
//=======================================================================================================================================//
void MenuElements(){
    printf("========================================================\n");
    printf("1. Insert new employee ID and salary\n");
    printf("2. Find and return subset of employee - based on salary value\n");
    printf("3. Give a pay rise to specific employees\n");
    printf("4. Print all the salaries\n");
    printf("0. Exit\n\n");
    printf("[INPUT]Pick one of the above options: ");
}
//=======================================================================================================================================//
void MatrixFiller(Employee *dataMatrix, int employeesCount){
    for (int i=0; i<employeesCount; i++) {
        printf("Insert the employee %d ID: ",i+1);
        scanf("%d", &dataMatrix[i].ID);
        printf("Insert the employee %d Salary: ",i+1);
        scanf("%f", &dataMatrix[i].Salary);
        printf("========================================================\n");
    }
}
//=======================================================================================================================================//
void MatrixViewer(Employee *dataMatrix, int employeesCount){
    printf("Index|     ID|    Salary|\n");
    for (int i=0; i<employeesCount; i++) {
        printf("%5d|\t%5d|\t%8.2f|\n",i+1,dataMatrix[i].ID,dataMatrix[i].Salary);
    }
    printf("========================================================\n");
}
//=======================================================================================================================================//
void MatrixAdd(Employee *dataMatrix, int *employeesCount){
    printf("Insert the new employee ID: ");
    scanf("%d",&dataMatrix[*employeesCount].ID);
    printf("Insert the new employee Salary: ");
    scanf("%f",&dataMatrix[*employeesCount].Salary);
    *employeesCount+=1;
    printf("========================================================\n");
}
//=======================================================================================================================================//
void MatrixFilter(Employee *dataMatrix, int employeesCount){
    float filter;
    printf("Insert salery value for filter: ");
    scanf("%f",&filter);
    printf("\nThe following employees has a salary more than or equal to the value specified: \n");
    for (int i=0; i<employeesCount; i++) {
        if (dataMatrix[i].Salary >= filter) {
            printf("%d\n",dataMatrix[i].ID);
        }
    }
}
//=======================================================================================================================================//
void PayRise(Employee *dataMatrix, int employeesCount){
    int pickedID, pickedRise;
    char pickedChoice;
    do {
        printf("Insert the employee ID: ");
        scanf("%d",&pickedID);
        printf("\nInsert the rise percentage: ");
        scanf("%d",&pickedRise);
        for (int i=0; i<employeesCount; i++) {
            if (dataMatrix[i].ID == pickedID) {
                dataMatrix[i].Salary = (1+pickedRise/100)*dataMatrix[i].Salary;
            }
        }
        printf("[INPUT]Another employee? (Y/N): ");
        scanf(" %c",&pickedChoice);                     //space before "c" as it was being skipped
    } while (pickedChoice=='Y');
}
//=======================================================================================================================================//
int main(int argc, const char * argv[]) {
    
    //Initializing the application
    printf("***Welcome to the employees rise app***\n\n");
    
    int employeesCount;
    printf("Insert the number of employee: ");
    scanf("%d",&employeesCount);
    printf("========================================================\n");
    Employee dataMatrix[employeesCount+50];
    
    MatrixFiller(&dataMatrix, employeesCount);
    MatrixViewer(&dataMatrix, employeesCount);
    
    int userSelection;
    do {
        MenuElements();
        scanf("%d",&userSelection);
        switch (userSelection) {
            case 1:
                MatrixAdd(&dataMatrix, &employeesCount);
                printf("[INFO]]New employees count: %d\n", employeesCount);
                break;
            case 2:
                MatrixFilter(&dataMatrix, employeesCount);
                break;
            case 3:
                PayRise(&dataMatrix, employeesCount);
                break;
            case 4:
                MatrixViewer(&dataMatrix, employeesCount);
                break;
            default:
                break;
        }
    } while (userSelection!=0);
    return 0;
}
