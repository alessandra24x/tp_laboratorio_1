#ifndef CALC_H_INCLUDED
#define CALC_H_INCLUDED

void clrscr(void);
void myPause(void);
int getSum(float*aValue,float*bValue);
int getDiference(float*aValue,float*bValue);
int getProduct(float*aValue,float*bValue);
int getDividend(float*aValue,float*bValue);
int getFactorial(float number);
int utn_isFloat(char* string);
int utn_getFloat(float*pResult);
int utn_getNumberFloat(float* pResult,char* mensaje,char* mensajeError,int reintentos);

#endif // CALC_H_INCLUDED
