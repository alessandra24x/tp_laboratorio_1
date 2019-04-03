#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int utn_isInt(char* number)
{
    int ret=-1;
    int i=0;
    if(number!=NULL)
    {
        while(number[i]!='\0')
        {
            if(number[i]<'0' || number[i]>'9')
                break;
            i++;
        }
        if(number[i]=='\0')
            ret=1;
    }
    return ret;
}

int utn_isFloat(char* number)
{
    int dotCounter=0;
    int ret=-1;
    int i=0;
    if(number!=NULL)
    {
        while(number[i]!='\0')
        {
            if(number[i]=='.')
            {
                dotCounter++;
            }
            if(number[i]<'0' || number[i]>'9'|| number[i]!='.'||dotCounter>1)
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

int utn_getInt(int* pResult)
{
    int ret=-1;
    char buffer[8];
    fgets(buffer,sizeof(buffer),stdin);
    buffer[strlen(buffer)-1]='\0';
    if(utn_isInt(buffer))
    {
        *pResult = atoi(buffer);
        ret=1;
    }
    return ret;
}

int unt_getFloat(float*pResult)
{
    int ret=-1;
    char buffer[8];
    fgets(buffer,sizeof(buffer),stdin);
    buffer[strlen(buffer)-1]='\0';
    if(utn_isFloat(buffer))
    {
        *pResult = atoi(buffer);
        ret=1;
    }
    return ret;
}

int utn_getNumber(int* pResult,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
    int ret;
    int num;
    while(reintentos>0)
    {
        printf("%s",mensaje);
        if(utn_getInt(&num)==1)
        {
            if(num<=maximo && num>=minimo)
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
