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

    printf("=== Testing search by ID ===\n");
    // example match
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1001);
    if(matchPtr)
        printf("Employee ID 1001 found at record %d: %s\n", (int)(matchPtr - EmployeeTable), matchPtr->name);
    else
        printf("Employee ID 1001 NOT found\n");
    // example no match
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 9999);
    if(matchPtr)
        printf("Employee ID 9999 found at record %d: %s\n", (int)(matchPtr - EmployeeTable), matchPtr->name);
    else
        printf("Employee ID 9999 NOT found\n");

    printf("\n=== Testing search by Name ===\n");
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat"); // match
    if(matchPtr)
        printf("Employee Tony Bobcat found at record %d\n", (int)(matchPtr - EmployeeTable));
    else
        printf("Employee Tony Bobcat NOT found\n");
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Jane Doe"); // no match
    if(matchPtr)
        printf("Employee Jane Doe found at record %d\n", (int)(matchPtr - EmployeeTable));
    else
        printf("Employee Jane Doe NOT found\n");

    printf("\n=== Testing search by Phone ===\n");
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "909-555-1235"); // match
    if(matchPtr)
        printf("Employee with phone 909-555-1235 found at record %d\n", (int)(matchPtr - EmployeeTable));
    else
        printf("Employee with phone 909-555-1235 NOT found\n");
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "555-0000"); // no match
    if(matchPtr)
        printf("Employee with phone 555-0000 found at record %d\n", (int)(matchPtr - EmployeeTable));
    else
        printf("Employee with phone 555-0000 NOT found\n");

    printf("\n=== Testing search by Salary ===\n");
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 6.34); // match
    if(matchPtr)
        printf("Employee with salary 6.34 found at record %d: %s\n", (int)(matchPtr - EmployeeTable), matchPtr->name);
    else
        printf("Employee with salary 6.34 NOT found\n");
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 9.99); // no match
    if(matchPtr)
        printf("Employee with salary 9.99 found at record %d: %s\n", (int)(matchPtr - EmployeeTable), matchPtr->name);
    else
        printf("Employee with salary 9.99 NOT found\n");

    return EXIT_SUCCESS;
}