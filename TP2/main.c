#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Employee.h"

int main()
{
    Employee employees[10];
    initEmployees(employees,10);
    addEmployee(employees,10,5,"test10","test",10,1);
    addEmployee(employees,10,2,"test6","test",10,1);
    addEmployee(employees,10,3,"test6","test",10,3);
    addEmployee(employees,10,4,"test3","test",10,1);
    addEmployee(employees,10,1,"test1","test",10,1);
    sortEmployees(employees,10,0);
    printEmployees(employees,10);
    printf("Hello world!\n");
    return 0;
}
