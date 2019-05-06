#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Employee.h"

int main()
{
    Employee employees[100];
    initEmployees(employees,100);
    addEmployee(employees,100,1,"test","test",10,1);
    printf("Hello world!\n");
    return 0;
}
