#ifndef EMPLOYEE_H
#define EMPLOYEE_H

typedef struct {
    long number;
    char *name;
    char *phone;
    double salary;
} Employee, *PtrToEmployee;

typedef const Employee *PtrToConstEmployee;

#endif