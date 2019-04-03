#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "aritmrtics.h"
#include "views.h"

int main()
{
    views_drawHome();
    unsigned long long result;
    utn_getFactorial(65,&result);
    printf("El factorial es: %llu",result);
    return 0;
}

