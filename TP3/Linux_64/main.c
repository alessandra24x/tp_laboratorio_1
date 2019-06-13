#include <stdio.h>
#include <stdlib.h>
#include "Win64_LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    printf("/****************************************************\
\nMenu:\
\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\
\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\
\n\n3. Alta de empleado\
\n4. Modificar datos de empleado\
\n5. Baja de empleado\
\n6. Listar empleados\
\n7. Ordenar empleados\
\n\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\
\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\
\n\n10. Salir\
\n*****************************************************/");
     utn_getInt(&option,"\nSeleccione opcion: ","Opcion invalida",1,10,10);
        switch(option)
        {
            case 1:
                printf("%d elementos cargados\n",controller_loadFromText("data.csv",listaEmpleados));
                controller_lastIdEmployee(listaEmpleados);
                break;
            case 2:
                printf("%d elementos cargados\n",controller_loadFromBinary("datasavebin",listaEmpleados));
                controller_lastIdEmployee(listaEmpleados);
                break;
            case 3:
                controller_addEmployee(listaEmpleados);
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                break;
            case 8:
                printf("%d elementos guardados\n",controller_saveAsText("datasave.csv",listaEmpleados));
                break;
            case 9:
                printf("%d elementos guardados\n",controller_saveAsBinary("datasavebin",listaEmpleados));
                break;
        }
    }while(option != 10);
    return 0;
}
