#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void clean_stdin(void)
{
    int c;
    do
    {
        c = getchar();
    }
    while (c != '\n' && c != EOF);
}

void clrscr(void)
{
    system("@cls||clear");
}

void myPause(void)
{
    clean_stdin();
    printf("\nPresione enter para continuar");
    getchar();
}

int getSum(float*aValue,float*bValue)
{
    float result;
    result=(*aValue)+(*bValue);
    printf("\nEl resultado de %.2f+%.2f es: %.2f\n",*aValue,*bValue,result);
    return 0;
}

int getDiference(float*aValue,float*bValue)
{
    float result;
    result=(*aValue)-(*bValue);
    printf("El resultado de %.2f-%.2f es: %.2f\n",*aValue,*bValue,result);

    return 0;
}

int getProduct(float*aValue,float*bValue)
{
    float result;
    result=(*aValue)*(*bValue);
    printf("El resultado de %.2f*%.2f es: %.2f\n",*aValue,*bValue,result);

    return 0;
}

int getDividend(float*aValue,float*bValue)
{
    if(*bValue)
    {
        float result;
        result=(*aValue)*(*bValue);
        printf("El resultado de %.2f/%.2f es: %.2f\n",*aValue,*bValue,result);
    }
    else
    {
        printf("No es posible dividir por cero\n");
    }

    return 0;
}

int getFactorial(float number)
{
    double factorial=1;
    int ret=-1;
    int i;
    if (roundf(number) == number)
    {
        if (number < 0)
        {
            printf("El numero %.2f es negativo\n",number);
            ret=-1;
        }
        else
        {
            for(i=1; i<=number; ++i)
            {
                factorial *= i;
            }
            printf("El factorial de %.2f es: %.0lf\n",number,factorial);
        }
        //printf("integer\n");
    }
    else
    {
        printf("El numero %.2f no es entero\n",number);
    }

    /*   if (number < 0)
       {
           printf("Numero invalido\n");
           ret=-1;
       }
       else
       {
           for(i=1; i<=number; ++i)
           {
               factorial *= i;
           }
           printf("El factorial de A es:%.2lf  y El factorial de B es: r2",factorial);
       }*/
    return ret;
}

int calculateFactorial(float aValue, float bValue)
{
    getFactorial(aValue);
    getFactorial(bValue);
    return 0;
}

int utn_isFloat(char* number)
{
    int dotCounter=0;
    int ret=0;
    int i=0;
    if(number!=NULL)
    {
        while(number[i]!='\0')
        {
            if(number[i]=='.')
            {
                dotCounter++;
            }
            if((number[i]<'0' || number[i]>'9')&&(number[i]!='.'||dotCounter>1)&&number[i]!='-')
            {
                break;
            }
            i++;
        }
        if(number[i]=='\0')
            ret=1;
    }
    return ret;
}

int utn_getFloat(float*pResult)
{
    int ret=-1;
    char buffer[50];
    fgets(buffer,sizeof(buffer),stdin);
    buffer[strlen(buffer)-1]='\0';
    if(utn_isFloat(buffer))
    {
        *pResult = atof(buffer);
        ret=1;
    }
    return ret;
}

int utn_getNumberFloat(float* pResult,char* mensaje,char* mensajeError,int reintentos)
{
    int ret;
    float num;
    while(reintentos>0)
    {
        clean_stdin();
        printf("%s",mensaje);
        if(utn_getFloat(&num)==1)
        {
            break;
        }
        reintentos--;
        printf("%s",mensajeError);
    }
    if(reintentos==0)
    {
        ret=-1;
    }
    else
    {
        ret=0;
        *pResult = num;
    }
    return ret;
}
