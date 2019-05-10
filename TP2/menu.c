#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Employee.h"
#include "menu.h"
#include "utn.h"

void menu_mainMenu(Employee* list,int len)
{
    int option, optionInf;
    while(option!=6)
    {
        printf("/-----------------\n1.ALTAS\n2.MODIFICAR\n3.BAJA\n4.INFORMES\n5.MOSTRAR\n6.SALIR");
        utn_getInt(&option,"\nSelecione una opcion: ","\nOpcion invalida",1,6,10);
        switch(option)
        {
        case 1:
            getEmployee(list,len);
            break;
        case 2:
            if(!existEmployee(list,len))
            {
                updateEmployee(list,len);
            }
            else
            {
                printf("\nEl registro esta vacio.\n");
            }
            break;
        case 3:
            if(!existEmployee(list,len))
            {
                getDeleteEmployee(list,len);
            }
            else
            {
                printf("\nEl registro esta vacio.\n");
            }
            break;
        case 4:
            if(!existEmployee(list,len))
            {
                while(optionInf!=3)
                {
                    printf("/-----------------\n1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector\n2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n3.SALIR");
                    utn_getInt(&optionInf,"\nSelecione una opcion: ","\nOpcion invalida",1,3,10);
                    switch(optionInf)
                    {
                    case 1:
                        sortEmployees(list,len,1);
                        printEmployees(list,len);
                        break;
                    case 2:

                        break;
                    }
                }
            }
            else
            {
                printf("\nEl registro esta vacio.\n");
            }
            break;
        case 5:
            if(!existEmployee(list,len))
            {
                printEmployees(list,len);
            }
            else
            {
                printf("\nEl registro esta vacio.\n");
            }
            break;
        }
    }
    return;
}
