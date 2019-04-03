#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "aritmrtics.h"
#include "views.h"

int main()
{
    char aValue[50]="                                              ";
    char bValue[50]="                                              ";
    views_drawHome(aValue,bValue);

    int menuOption;
    scanf("%d",&menuOption);
    switch(menuOption)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        getSum();
        break;
    case 4:
        getDiference();
        break;
    case 5:
        getProduct();
        break;
    case 6:
        getDividend();
        break;
    case 7:
        //getFactorial();
        break;
    case 8:
        break;
    default:
        printf("Opcion invalida");
        break;
    }

    double result;
    getFactorial(10,&result);
    printf("\nEl factorial es: %.0lf",result);

    return 0;
}

