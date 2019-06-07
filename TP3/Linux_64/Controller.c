#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int ret=0;
    FILE* pFile;
    pFile = fopen(path,"r");
    ret=parser_EmployeeFromText(pFile , pArrayListEmployee);
    fclose(pFile);
    return ret;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int ret=0;
    FILE* pFile;
    pFile = fopen(path,"rb");
    ret=parser_EmployeeFromBinary(pFile , pArrayListEmployee);
    fclose(pFile);
    return ret;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* bufferEmployee;
    int bufferId;
    char bufferNombre[4096];
    int bufferHorasTrabajadas;
    int bufferSueldo;
    int i;
    int ret=0;
    int len;
    if(pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        for(i=0;i<len;i++)
        {
            bufferEmployee=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(bufferEmployee,&bufferId);
            employee_getNombre(bufferEmployee,bufferNombre);
            employee_getHorasTrabajadas(bufferEmployee,&bufferHorasTrabajadas);
            employee_getSueldo(bufferEmployee,&bufferSueldo);
            printf("%d,%s,%d,%d\n",bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
        }
        ret=0;
    }
    return ret;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    Employee* bufferEmployee;
    FILE* pf;
    int bufferId;
    char bufferNombre[4096];
    int bufferHorasTrabajadas;
    int bufferSueldo;
    int i;
    int ret=0;
    int len;
    pf=fopen(path,"w");
    if(pArrayListEmployee!=NULL && pf!=NULL)
    {
        fprintf(pf,"id,nombre,horasTrabajadas,sueldo\n");
        len=ll_len(pArrayListEmployee);
        for(i=0;i<len;i++)
        {
            bufferEmployee=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(bufferEmployee,&bufferId);
            employee_getNombre(bufferEmployee,bufferNombre);
            employee_getHorasTrabajadas(bufferEmployee,&bufferHorasTrabajadas);
            employee_getSueldo(bufferEmployee,&bufferSueldo);
            fprintf(pf,"%d,%s,%d,%d\n",bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
            ret++;
        }
        fclose(pf);
    }
    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    Employee* bufferEmployee;
    FILE* pf;
    int i;
    int ret=0;
    int len;
    pf=fopen(path,"w");
    if(pArrayListEmployee!=NULL && pf!=NULL)
    {
        len=ll_len(pArrayListEmployee);
        for(i=0;i<len;i++)
        {
            bufferEmployee=(Employee*)ll_get(pArrayListEmployee,i);
            fwrite(bufferEmployee,sizeof(Employee),1,pf);
            ret++;
        }
        fclose(pf);
    }
    return ret;
}

