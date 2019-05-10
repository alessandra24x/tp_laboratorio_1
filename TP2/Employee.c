#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"

/** \brief Generate and keep track of the ids.
 * \return int Return the next id to use.
 *
 */
static int idGen(void)
{
    static int idMax=0;
    return idMax++;
}

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
            list[i].id=0;
            list[i].isEmpty = 1;
            strcpy(list[i].name,"");
            list[i].salary=0;
            list[i].sector=0;
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
        i=findFree(list,len);
        if(i>=0)
        {
            list[i].id=id;
            list[i].isEmpty=0;
            list[i].salary=salary;
            list[i].sector=sector;
            strncpy(list[i].name,name,sizeof(list[0].name));
            strncpy(list[i].lastName,lastName,sizeof(list[0].lastName));
            ret=0;
        }
        else
        {
            printf("No hay espacio libre");
        }
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
        list[index].id=0;
        list[index].isEmpty = 1;
        strcpy(list[index].name,"");
        list[index].salary=0;
        list[index].sector=0;
        ret=0;
    }
    return ret;
}

/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order)
{
    int i;
    int swap;
    int ret= -1;
    if(list!=NULL && len>0 && (order==0 || order==1))
    {
        do
        {
            swap=0;
            for(i=0;i<len-1;i++)
            {
                if(strcmp(list[i].name,list[i+1].name)==0)
                {
                    if(order==0 && list[i].sector<list[i+1].sector)
                    {
                        swapEmployee(list,i);
                        swap=1;
                    }
                    if(order==1 && list[i].sector>list[i+1].sector)
                    {
                        swapEmployee(list,i);
                        swap=1;
                    }
                }
                if(order==0 && strcmp(list[i].name,list[i+1].name)<0)
                {
                    swapEmployee(list,i);
                    swap=1;
                }
                if(order==1 && strcmp(list[i].name,list[i+1].name)>0)
                {
                    swapEmployee(list,i);
                    swap=1;
                }
            }
        }while(swap!=0);
        ret=0;
    }
    return ret;
}

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
            if(list[i].isEmpty==0)
            {
                printf("id: %d\n1. Name: %s\n2. Lastname: %s\n3. Salary %.2f\n4. Sector: %d\n", list[i].id,
                                                                                                list[i].name,
                                                                                                list[i].lastName,
                                                                                                list[i].salary,
                                                                                                list[i].sector);
            }

        }
    }
    return ret;
}

/** \brief swap two positions in an array of employee datatype
 *
 * \param list Employee*
 * \param length int
 * \return void
 *
 */
void swapEmployee(Employee* list,int i)
{
    Employee buffer1;
    Employee buffer2;
    buffer1=list[i];
    buffer2=list[i+1];
    list[i]=buffer2;
    list[i+1]=buffer1;
    return;
}

/** \brief Find a free space in the array and return his position
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - The index of a free position in the array
 *
 */
int findFree(Employee* list,int len)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==1)
        {
            ret=i;
            break;
        }
    }
    return ret;
}

/** \brief request to the users the information for a new employee
 *
 * \param list Employee*
 * \param length int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int getEmployee(Employee* list,int len)
{
    int ret=-1;
    char bufferName[51];
    char bufferLastname[51];
    float bufferSalary;
    int bufferSector;
    int freeIndex=findFree(list,len);

    if( !utn_getName(bufferName,51,"\nIngrese nombre: ","\nValor invalido",3,50,10)&&
        !utn_getName(bufferLastname,50,"\nIngrese apellido: ","\nValor invalido",3,50,10)&&
        !utn_getFloat(&bufferSalary,"\nIngrese salario: ","\nValor invalido",0,32000000,10)&&
        !utn_getInt(&bufferSector,"\nIngrese sector: ","\nValor invalido",1,1000,10)&&
        freeIndex>=0)
    {
        addEmployee(list,len,idGen(),bufferName,bufferLastname,bufferSalary,bufferSector);
        ret=0;
    }
    return ret;
}

/** \brief Request an id and permits modify his parameters.
 *
 * \param list Employee*
 * \param length int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int updateEmployee(Employee *list,int len)
{
    int ret=-1;
    int auxId;
    int option;
    char bufferName[51];
    char bufferLastname[51];
    float bufferSalary;
    int bufferSector;
    utn_getInt(&auxId,"\nIngrese id: ","\nValor invalido",0,9999,10);
    if(findEmployeeById(list,len,auxId)>=0)
    {

        while(option!=5)
        {
            printEmployees(list,len);
            printf("5. Salir");
            utn_getInt(&option,"\nSeleccione campo a modificar: ","\nOpcion invalida",1,5,10);
            switch(option)
            {
            case 1:
            {
                if(!utn_getName(bufferName,51,"\nIngrese nombre: ","\nValor invalido",3,50,10))
                {
                    strncpy(list[auxId].name,bufferName,50);
                }
                break;
            }
            case 2:
            {
                if(!utn_getName(bufferLastname,50,"\nIngrese apellido: ","\nValor invalido",3,50,10))
                {
                    strncpy(list[auxId].lastName,bufferLastname,50);
                }
                break;
            }
            case 3:
            {
                if(!utn_getFloat(&bufferSalary,"\nIngrese salario: ","\nValor invalido",0,32000000,10))
                {
                    list[auxId].salary=bufferSalary;
                }
                break;
            }
            case 4:
            {
                if(!utn_getInt(&bufferSector,"\nIngrese sector: ","\nValor invalido",1,1000,10))
                {
                    list[auxId].sector=bufferSector;
                }
                break;
            }
            }
        }
        ret=0;
    }
    else
    {
        printf("\nId invalido");
    }
    return ret;
}

/** \brief Find if exist a register of employee type
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int existEmployee(Employee* list,int len)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==0)
        {
            ret=0;
            break;
        }
    }
    return ret;
}

/** \brief Request an id and deletes the register.
 *
 * \param list Employee*
 * \param length int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int getDeleteEmployee(Employee *list,int len)
{
    int ret=-1;
    int auxId;
    utn_getInt(&auxId,"\nIngrese id: ","\nValor invalido",0,9999,10);
    if(findEmployeeById(list,len,auxId)>=0)
    {
        removeEmployee(list,len,auxId);
        ret=0;
    }
    else
    {
        printf("\nId invalido");
    }
    return ret;
}
