#include <stdio.h>
#include <stdlib.h>
#include "employee.h"

// declared in employeeOne.c
PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char *nameToFind);
PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char *phoneToFind);
PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);

// declared in employeeTable.c
extern Employee EmployeeTable[];
extern const int EmployeeTableEntries;

int main(void) {
    PtrToEmployee matchPtr;

    // Test all employees in the table by ID
    printf("=== Testing search by ID ===\n");
    for(int i = 0; i < EmployeeTableEntries; i++){
        long id = EmployeeTable[i].number;
        matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, id);
        if(matchPtr != NULL)
            printf("Employee ID %ld found at record %d\n", id, (int)(matchPtr - EmployeeTable));
        else
            printf("Employee ID %ld NOT found\n", id);
    }

    // Test all employees in the table by Name
    printf("\n=== Testing search by Name ===\n");
    for(int i = 0; i < EmployeeTableEntries; i++){
        char *name = EmployeeTable[i].name;
        matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, name);
        if(matchPtr != NULL)
            printf("Employee %s found at record %d\n", name, (int)(matchPtr - EmployeeTable));
        else
            printf("Employee %s NOT found\n", name);
    }

    // Test all employees in the table by Phone
    printf("\n=== Testing search by Phone ===\n");
    for(int i = 0; i < EmployeeTableEntries; i++){
        char *phone = EmployeeTable[i].phone;
        matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, phone);
        if(matchPtr != NULL)
            printf("Employee with phone %s found at record %d\n", phone, (int)(matchPtr - EmployeeTable));
        else
            printf("Employee with phone %s NOT found\n", phone);
    }

    printf("\n=== Testing search by Salary ===\n");
        matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 6.34);
        if(matchPtr != NULL)
            printf("Employee with salary 6.34 found at record %d: %s\n", (int)(matchPtr - EmployeeTable), matchPtr->name);
        else
            printf("Employee with salary 6.34 NOT found\n");

        matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 9.99);
        if(matchPtr != NULL)
            printf("Employee with salary 9.99 found at record %d: %s\n", (int)(matchPtr - EmployeeTable), matchPtr->name);
        else
            printf("Employee with salary 9.99 NOT found\n");

    return EXIT_SUCCESS;
}