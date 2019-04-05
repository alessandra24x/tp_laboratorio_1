#ifndef CALC_H_INCLUDED
#define CALC_H_INCLUDED
/**
*\brief Limpia el buffer de la consola
**/
void clean_stdin(void);

/**
*\brief Limpia todo lo visible en consola
**/
void clrscr(void);

/**
*\brief Realiza una pausa hasta que se precione la tecla enter
**/
void myPause(void);

/**
*\brief Suma dos numeros e imprime el resultado
*\param aValue Primer numero a sumar
*\param bValue Segundo numero a sumar
*\return Retorna 0 luego de realizar la suma
**/
int getSum(float*aValue,float*bValue);

/**
*\brief Resta dos numeros e imprime el resultado
*\param aValue Numero a ser restado
*\param bValue Numero a restar
*\return Retorna 0 luego de realizar la resta
*/
int getDiference(float*aValue,float*bValue);

/**
*\brief Calcula el producto entre dos numeros e imprime el resultado
*\param aValue Primer numero a multiplicar
*\param bValue Segundo numero a multiplicar
*\return Retorna 0 luego de realizar el producto
*/
int getProduct(float*aValue,float*bValue);

/**
*\brief Divide dos numeros e imprime el resultado
*\param aValue numero dividendo
*\param bValue numero divisor
*\return 1 si la division fue realizada
*\return 0 si el divisor es 0
*/
int getDividend(float*aValue,float*bValue);

/**
*\brief Recibe un numero, comprueba que sea un entero no negativo e imprime su factorial
*\param number Numero para calcular su factorial
*\return 1 Si pudo imprimir su factorial
*\return -1 Si el numero es negativo
*\return -2 Si el numero no es entero
*/
int getFactorial(float number);

/**
*\brief Llama a la funcion getFactorial sobre dos numeros
*\param aValue primer numero a ser factoreado
*\param bValue segundo numero a ser factoreado
*\return 0
*/
int calculateFactorial(float aValue, float bValue);

/**
*\brief Recibe un array de chars y comprueba si es un numero tipo float
*\param string Cadena de caracteres a comprobar
*\return 1 Si es un numero tipo float
*\return 0 Si no es un numero tipo float
*/
int utn_isFloat(char* string);

/**
*\brief Solicita un numero, lo toma como array de chars, comprueba si es de tipo float y escbribe su valor en punturo si lo es.
*\param pResult puntero donde escribir el numero en caso de recibir un float
*\return 1 si consigio un numero tipo float
*\return -1 si no consigio un numero tipo float
*/
int utn_getFloat(float*pResult);

/**
*\brief Imprime un mensaje y solicita un numero tipo float al usuario, si el valor ingresado no es un numero valido muestra un mensaje de error, lo reintenta una cantidad definida de veces
*\param pResult puntero donde escribir el numero si consigio uno
*\param mensaje Mensaje a ser mestrado al momento de solicitar el numero
*\param mensajeError mensaje a ser mostrado cuando se ingresa un valor invalido
*\param reintentos Cantidad de veces que la funcion intenta conseguir el nuemero
*\return 0 Si logro escribir un numero valido
*\return -1 si se agotaron la cantidad de intentos
*/
int utn_getNumberFloat(float* pResult,char* mensaje,char* mensajeError,int reintentos);

#endif // CALC_H_INCLUDED
