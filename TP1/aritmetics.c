#include <stdio.h>
int getSum(void)
{
    printf("Funcion sin programar");

    return 0;
}

int getDiference(void)
{
    printf("Funcion sin programar");

    return 0;
}

int getProduct(void)
{
    printf("Funcion sin programar");

    return 0;
}

int getDividend(void)
{
    printf("Funcion sin programar");

    return 0;
}

int getFactorial(int number,double*pFactorial)
{
    int ret=-1;
    int i;
    *pFactorial = 1;

    if (number < 0)
    {
        ret=-1;
    }
    else
    {
        for(i=1; i<=number; ++i)
        {
            *pFactorial *= i;
        }
    }
    return ret;
}
