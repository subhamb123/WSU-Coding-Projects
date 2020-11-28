#ifndef parent

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct employee{
    char name[100];
    char title;
    double hours_worked;
    double payrate;
    double payment;
} Employee;

void init_employee(Employee* payroll);

#endif