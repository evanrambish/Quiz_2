#include <string.h>
#include "employee.h"
#include "employeeTwo.h"

// Match functions
int matchByNumber(const Employee *emp, void *target) {
    long number = *(long *)target;
    return emp->number == number;
}

int matchByName(const Employee *emp, void *target) {
    char *name = (char *)target;
    return strcmp(emp->name, name) == 0;
}

int matchByPhone(const Employee *emp, void *target) {
    char *phone = (char *)target;
    return strcmp(emp->phone, phone) == 0;
}

int matchBySalary(const Employee *emp, void *target) {
    double salary = *(double *)target;
    return emp->salary == salary;
}

// Generic search function
PtrToEmployee searchEmployeeGeneric(const Employee table[], int sizeTable,
                                    int (*matchFunc)(const Employee *, void *),
                                    void *target) {
    for(int i = 0; i < sizeTable; i++) {
        if(matchFunc(&table[i], target))
            return (PtrToEmployee)&table[i];
    }
    return NULL;
}