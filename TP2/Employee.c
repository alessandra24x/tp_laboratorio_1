#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Employee.h"

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len)
{
    int i;
    int ret= -1;
    if(list!=NULL&&len>0)
    {
        for(i=0;i<len;i++)
        {
            list[i].isEmpty = 0;
        }
        ret=0;
    }
    return ret;
}

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int i;
    int ret= -1;
    if(list!=NULL&&len>0)
    {
        for(i=0;i<len;i++)
        {
            list[i].id=id;
            list[i].isEmpty=0;
            list[i].salary=salary;
            list[i].sector=sector;
            strncpy(list[i].name,name,sizeof(list[0].name));
            strncpy(list[i].lastName,lastName,sizeof(list[0].lastName));
        }
        ret=0;
    }
    return ret;
}

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len,int id)
{
    int i;
    int ret= -1;
    if(list!=NULL&&len>0)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].id==id)
            {
                ret=i;
                break;
            }
        }
    }
    return ret;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id)
{
    int index;
    int ret= -1;
    index=findEmployeeById(list,len,id);
    if(list!=NULL && len>0 && index>=0)
    {
        list[index].isEmpty=1;
        ret=0;
    }
    return ret;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 *//*
int sortEmployees(Employee* list, int len, int order)
{
    int i,j;
    int ret= -1;
    if(list!=NULL && len>0)
    {

    }
    return ret;
}*/

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int printEmployees(Employee* list, int length)
{
    int i;
    int ret= -1;
    if(list!=NULL && length>0)
    {
        for(i=0;i<length;i++)
        {
            if(!list[i].isEmpty)
            {
                printf("id: %d\nName: %s\nLastname: %s\nSalary %.2f\nSector: %d\n", list[i].id,
                                                                                    list[i].name,
                                                                                    list[i].lastName,
                                                                                    list[i].salary,
                                                                                    list[i].sector);
            }

        }
    }
    return ret;
}

void swapEmployee(Employee* a,Employee* b)
{
    Employee* buffer;
    buffer=a;
    a=b;
    b=buffer;
    return;
}
