#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "Venta.h"
#include "Producto.h"
#include "Controller.h"
#include "parser.h"
#include "utn.h"
/*
1. Alta de cliente : (se le pedir� nombre, apellido y DNI). Se generar� un ID
autom�ticamente
2. Modificaci�n de cliente: Se ingresa el ID y se permite cambiar el resto de los campos
3. Baja de cliente: Se ingresa el ID y el cliente se eliminar�. No permitir esta acci�n si
hay ventas asociadas al cliente.
4. Listar clientes: Se imprimir� por pantalla la lista de clientes ordenados por Apellido.
5. Realizar una venta: Se pedir� el ID del cliente, luego se pedir� que se ingrese el
c�digo del producto a comprar y la cantidad. Se generar� un n�mero �nico que
identifica a la venta.
6. Anular una venta: Se pedir� que se ingrese el ID de la venta y la misma se eliminar�.
7. Informar ventas: Se imprimir� por pantalla las ventas realizadas.
8. Informar ventas por producto . Se pedir� que se ingrese el c�digo de un producto y
se imprimir� por pantalla las ventas realizadas de dicho producto.
9. Generar informe de ventas: Se generar� un archivo "informe.txt" con el mismo
formato que el punto 7.
10. Informar cantidad de ventas por cliente: Listar� por pantalla a los clientes
indicando la cantidad*/

int main()
{
    printf("Hello world!\n");
    return 0;
}
