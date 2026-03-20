#ifndef EMPLOYEETWO_H
#define EMPLOYEETWO_H

#include "employee.h"

// Generic search function
PtrToEmployee searchEmployeeGeneric(const Employee table[], int sizeTable,
                                    int (*matchFunc)(const Employee *, void *),
                                    void *target);

// Match functions to pass to generic search
int matchByNumber(const Employee *emp, void *target);
int matchByName(const Employee *emp, void *target);
int matchByPhone(const Employee *emp, void *target);
int matchBySalary(const Employee *emp, void *target);

#endif