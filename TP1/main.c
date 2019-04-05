#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
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
        switch(menuOption)
        {
        case 1:
            utn_getNumberFloat(&aValue,"Ingrese el numero A: ","\nError, numero invalido\n",10);
            //myPause();
            break;
        case 2:
            utn_getNumberFloat(&bValue,"Ingrese el numero B: ","\nError, numero invalido\n",10);
            //myPause();
            break;
        case 3:
            getSum(&aValue,&bValue);
            myPause();
            break;
        case 4:
            getDiference(&aValue,&bValue);
            myPause();
            break;
        case 5:
            getProduct(&aValue,&bValue);
            myPause();
            break;
        case 6:
            getDividend(&aValue,&bValue);
            myPause();
            break;
        case 7:
            getFactorial(aValue);
            myPause();
            break;
        case 8:
            aValue=0;
            bValue=0;
            break;
        case 9:
            exit=1;
            break;
        default:
            printf("Opcion invalida\n");
            myPause();
            break;
        }
        fflush(stdin);
    }



    return 0;
}

