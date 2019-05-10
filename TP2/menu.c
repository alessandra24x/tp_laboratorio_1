#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Employee.h"
#include "menu.h"
#include "utn.h"

void menu_mainMenu(Employee* list,int len)
{
    int option;
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
                //informes
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
