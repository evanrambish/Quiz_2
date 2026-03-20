#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "employeeTwo.h"  // Include header for generic search

// declared in employeeTable.c
extern Employee EmployeeTable[];
extern const int EmployeeTableEntries;

int main(void) {
    PtrToEmployee matchPtr;

    printf("=== Testing search by ID ===\n");
    long idMatch = 1001;
    long idNoMatch = 9999;
    matchPtr = searchEmployeeGeneric(EmployeeTable, EmployeeTableEntries, matchByNumber, &idMatch);
    if(matchPtr)
        printf("Employee ID %ld found at record %d: %s\n", idMatch, (int)(matchPtr - EmployeeTable), matchPtr->name);
    else
        printf("Employee ID %ld NOT found\n", idMatch);

    matchPtr = searchEmployeeGeneric(EmployeeTable, EmployeeTableEntries, matchByNumber, &idNoMatch);
    if(matchPtr)
        printf("Employee ID %ld found at record %d: %s\n", idNoMatch, (int)(matchPtr - EmployeeTable), matchPtr->name);
    else
        printf("Employee ID %ld NOT found\n", idNoMatch);

    printf("\n=== Testing search by Name ===\n");
    char *nameMatch = "Tony Bobcat";
    char *nameNoMatch = "Jane Doe";
    matchPtr = searchEmployeeGeneric(EmployeeTable, EmployeeTableEntries, matchByName, nameMatch);
    if(matchPtr)
        printf("Employee %s found at record %d\n", nameMatch, (int)(matchPtr - EmployeeTable));
    else
        printf("Employee %s NOT found\n", nameMatch);

    matchPtr = searchEmployeeGeneric(EmployeeTable, EmployeeTableEntries, matchByName, nameNoMatch);
    if(matchPtr)
        printf("Employee %s found at record %d\n", nameNoMatch, (int)(matchPtr - EmployeeTable));
    else
        printf("Employee %s NOT found\n", nameNoMatch);

    printf("\n=== Testing search by Phone ===\n");
    char *phoneMatch = "909-555-1235";
    char *phoneNoMatch = "555-0000";
    matchPtr = searchEmployeeGeneric(EmployeeTable, EmployeeTableEntries, matchByPhone, phoneMatch);
    if(matchPtr)
        printf("Employee with phone %s found at record %d\n", phoneMatch, (int)(matchPtr - EmployeeTable));
    else
        printf("Employee with phone %s NOT found\n", phoneMatch);

    matchPtr = searchEmployeeGeneric(EmployeeTable, EmployeeTableEntries, matchByPhone, phoneNoMatch);
    if(matchPtr)
        printf("Employee with phone %s found at record %d\n", phoneNoMatch, (int)(matchPtr - EmployeeTable));
    else
        printf("Employee with phone %s NOT found\n", phoneNoMatch);

    printf("\n=== Testing search by Salary ===\n");
    double salaryMatch = 6.34;
    double salaryNoMatch = 9.99;
    matchPtr = searchEmployeeGeneric(EmployeeTable, EmployeeTableEntries, matchBySalary, &salaryMatch);
    if(matchPtr)
        printf("Employee with salary %.2f found at record %d: %s\n", salaryMatch, (int)(matchPtr - EmployeeTable), matchPtr->name);
    else
        printf("Employee with salary %.2f NOT found\n", salaryMatch);

    matchPtr = searchEmployeeGeneric(EmployeeTable, EmployeeTableEntries, matchBySalary, &salaryNoMatch);
    if(matchPtr)
        printf("Employee with salary %.2f found at record %d: %s\n", salaryNoMatch, (int)(matchPtr - EmployeeTable), matchPtr->name);
    else
        printf("Employee with salary %.2f NOT found\n", salaryNoMatch);

    return EXIT_SUCCESS;
}