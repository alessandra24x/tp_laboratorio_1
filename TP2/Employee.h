#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

typedef struct
{
    int id;
    int isEmpty;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
}Employee;

int initEmployees(Employee* list, int len);
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int findEmployeeById(Employee* list, int len,int id);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
int printEmployees(Employee* list, int length);
void swapEmployee(Employee* list,int i);
int findFree(Employee* list,int len);
#endif // EMPLOYEE_H_INCLUDED
