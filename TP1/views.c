#include <stdio.h>
#include <stdlib.h>

void views_drawHome(char*aValue,char*bValue)
{
    system("cls");
    printf("\n         *************************************************************");
    printf("\n         *               :: C A L C U L A D O R A ::                 *");
    printf("\n         *************************************************************");
    printf("\n         * Operando A: %s*",aValue);
    printf("\n         *************************************************************");
    printf("\n         * Operando B: %s*",bValue);
    printf("\n         *************************************************************");
    printf("\n         *                                                           *");
    printf("\n         *       1.- Cargar valor A           5.- Multiplicacion     *");
    printf("\n         *                                                           *");
    printf("\n         *       2.- Cargar valor B           6.- Division           *");
    printf("\n         *                                                           *");
    printf("\n         *       3.- Suma                     7.- Factorial          *");
    printf("\n         *                                                           *");
    printf("\n         *       4.- Resta                    8.- Borrar             *");
    printf("\n         *                                                           *");
    printf("\n         *************************************************************");
    printf("\n                     Nota: Solo funciona con numeros enteros");
    printf("\n");
    printf("\n                              Elija una opcion: ");
}
