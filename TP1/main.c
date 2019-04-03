#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "aritmrtics.h"
#include "views.h"

int main()
{
    int menuOption;
    int exit=0;
    char aValue[50]="    20.2                                      ";
    char bValue[50]="                                              ";
    float aux;
    while(exit==0)
    {
        views_drawHome(aValue,bValue);
        scanf("%d",&menuOption);
        //printf("%d",menuOption);
        switch(menuOption)
        {
        case 1:

            aux=atof(aValue);
            printf("%.2f\n",aux);
            system("pause");
            break;
        case 2:
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
            printf("Opcion invalida");
            system("pause");
            break;
        }
        fflush(stdin);
    }



    return 0;
}

