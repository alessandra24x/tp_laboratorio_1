#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "aritmrtics.h"
#include "views.h"

int main()
{
    int menuOption;
    int exit=0;
    float aValue=0;
    float bValue=0;
    while(exit==0)
    {
        views_drawHome(aValue,bValue);
        scanf("%d",&menuOption);
        //printf("%d",menuOption);
        switch(menuOption)
        {
        case 1:
            utn_getNumberFloat(&aValue,"Ingrese el numero A: ","\nError, numero invalido",10);
            printf("%f\n",aValue);
            system("pause");
            break;
        case 2:
            utn_getNumberFloat(&bValue,"Ingrese el numero A: ","\nError, numero invalido",10);
            system("pause");
            break;
        case 3:
            getSum();
            system("pause");
            break;
        case 4:
            getDiference();
            system("pause");
            break;
        case 5:
            getProduct();
            system("pause");
            break;
        case 6:
            getDividend();
            system("pause");
            break;
        case 7:
            //getFactorial();
            system("pause");
            break;
        case 8:
            //Borra todo
            break;
        case 9:
            exit=1;
            break;
        default:
            printf("Opcion invalida\n");
            system("pause");
            break;
        }
        fflush(stdin);
    }



    return 0;
}

