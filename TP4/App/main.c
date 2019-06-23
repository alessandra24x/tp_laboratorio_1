#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "Venta.h"
#include "Producto.h"
#include "Controller.h"
#include "parser.h"
#include "utn.h"
/*
1. Alta de cliente : (se le pedirá nombre, apellido y DNI). Se generará un ID
automáticamente
2. Modificación de cliente: Se ingresa el ID y se permite cambiar el resto de los campos
3. Baja de cliente: Se ingresa el ID y el cliente se eliminará. No permitir esta acción si
hay ventas asociadas al cliente.
4. Listar clientes: Se imprimirá por pantalla la lista de clientes ordenados por Apellido.
5. Realizar una venta: Se pedirá el ID del cliente, luego se pedirá que se ingrese el
código del producto a comprar y la cantidad. Se generará un número único que
identifica a la venta.
6. Anular una venta: Se pedirá que se ingrese el ID de la venta y la misma se eliminará.
7. Informar ventas: Se imprimirá por pantalla las ventas realizadas.
8. Informar ventas por producto . Se pedirá que se ingrese el código de un producto y
se imprimirá por pantalla las ventas realizadas de dicho producto.
9. Generar informe de ventas: Se generará un archivo "informe.txt" con el mismo
formato que el punto 7.
10. Informar cantidad de ventas por cliente: Listará por pantalla a los clientes
indicando la cantidad*/

int main()
{
    printf("Hello world!\n");
    return 0;
}
