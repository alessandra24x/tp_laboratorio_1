#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Employee.h"

Employee* employee_new()
{
    return (Employee*)malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* aux;
    aux=employee_new();
    if(aux!=NULL)
    {
    employee_setIdStr(aux,idStr);
    employee_setNombre(aux,nombreStr);
    employee_setHorasTrabajadasStr(aux,horasTrabajadasStr);
    employee_setSueldoStr(aux,sueldoStr);
    }
    return aux;
}

int employee_delete(Employee* this)
{
    int ret=-1;
    if(this!=NULL)
    {
        free(this);
        ret=0;
    }
    return ret;
}

int employee_setIdStr(Employee* this,char* idStr)
{
    int ret=-1;
    int bufferId;
    if(this!=NULL)
    {
        if(utn_isValidInt(idStr))
        {
            bufferId = atoi(idStr);
            employee_setId(this,bufferId);
        }
    }
    return ret;
}

int employee_setId(Employee* this,int id)
{
    int ret=-1;
    if(this!=NULL)
    {
        this->id=id;
        ret=0;
    }
    return ret;
}

int employee_getId(Employee* this,int* id)
{
    int ret=-1;
    if(this!=NULL&&id!=NULL)
    {
        *id=this->id;
        ret=0;
    }
    return ret;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int ret=-1;
    if(this != NULL)
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        ret=0;
    }
    return ret;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int ret=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strncpy(nombre,this->nombre,sizeof(this->nombre));
        ret=0;
    }
    return ret;
}

int employee_setHorasTrabajadasStr(Employee* this,char* horasTrabajadasStr)
{
    int ret=-1;
    int bufferHorasTrabajadas;
    if(this!=NULL)
    {
        if(utn_isValidInt(horasTrabajadasStr))
        {
            bufferHorasTrabajadas = atoi(horasTrabajadasStr);
            if(!employee_setHorasTrabajadas(this,bufferHorasTrabajadas))
            {
                ret=0;
            }
        }
    }
    return ret;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int ret=-1;
    if(this!=NULL && horasTrabajadas>=0)
    {
        this->horasTrabajadas=horasTrabajadas;
        ret=0;
    }
    return ret;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int ret=-1;
    if(this!=NULL&&horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        ret=0;
    }
    return ret;
}

int employee_setSueldoStr(Employee* this,char* sueldoStr)
{
    int ret=-1;
    int bufferSueldo;
    if(this!=NULL)
    {
        if(utn_isValidInt(sueldoStr))
        {
            bufferSueldo = atoi(sueldoStr);
            employee_setHorasTrabajadas(this,bufferSueldo);
        }
    }
    return ret;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int ret=-1;
    if(this!=NULL && sueldo>=0)
    {
        this->sueldo=sueldo;
        ret=0;
    }
    return ret;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int ret=-1;
    if(this!=NULL&&sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        ret=0;
    }
    return ret;
}


