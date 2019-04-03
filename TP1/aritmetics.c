
int utn_getFactorial(int number,unsigned long long*pFactorial)
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


