#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

int utn_isInt(char* cadena);
int utn_isFloat(char* string);
int utn_getInt(int* pResultado);
int unt_getFloat(float*pResult);
int utn_getNumber(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);

#endif // UTN_H_INCLUDED
