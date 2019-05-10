#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Employee.h"
#include "menu.h"

int main()
{
    int len=1000;
    Employee employees[len];
    initEmployees(employees,len);
    menu_mainMenu(employees,len);

    printf("Adios");
    return 0;
}
