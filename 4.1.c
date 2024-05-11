/*4.1 Una empresa que vende neumáticos desea realizar un programa para actualizar el total de ventas del mes
de sus productos. Para ello primeramente se ingresan la información de los productos formados por:
• Código (5 caracteres).
• Precio (real).
• Descripción (30 caracteres).
• Cantidad de unidades vendidas (al mes anterior, entero).
• Importe Total Vendido (al mes anterior, real).
Se sabe que la empresa no vende más de 50 productos. El ingreso de la carga de productos finaliza con un
producto con descripción “FIN”.
Luego ingresan las ventas del mes:
• Código de Producto (5 caracteres).
• Cantidad pedida.
El ingreso de datos de las ventas finaliza con una cantidad igual a 0. Se solicita:
a. Actualizar la información de los productos con las ventas realizadas en el mes.
b. Al finalizar, mostrar el listado de productos actualizado, informando:
DESCRIPCION CANTIDAD UNIDADES IMPORTE TOTAL
               VENDIDAS        VENDIDO

XXXXXXX          XXXX          $XXXXX,XX

*/

#include <stdio.h>
#include <string.h>
#define TAM 50

typedef struct
{
    char codigo[6];
    float precio;
    char descripcion[31];
    int uniVendidas;
    float impoTotal;   
}Producto;

int cargaProductos (Producto[], int);
int leeryvalidarInt (int);
float leeryvalidarFloat (float);
int busqueda (Producto[], char[], int);
void mostrarProductos (Producto[], int);

int main()
{
    Producto vProductos[TAM];
    int cantProductos, cantPedida, pos, i=0;
    char cod[6];
    cantProductos=cargaProductos(vProductos, TAM);
    printf("--VENTAS DEL MES--\n");
    printf("Ingrese la cantidad de productos pedidos:\n");
    cantPedida=leeryvalidarInt(0);
    while (cantPedida!=0)
    {
        printf("Ingrese el codigo del producto:\n");
        fflush(stdin);
        gets(cod);
        pos=busqueda(vProductos, cod, cantProductos);
        if (pos!=-1)
        {
            for (i=0; i<cantProductos; i++)
            {
                if (strcmpi(vProductos[i].codigo, cod)==0)
                {
                    vProductos[i].uniVendidas=0;
                    vProductos[i].impoTotal=0;
                    vProductos[i].uniVendidas+=cantPedida;
                    vProductos[i].impoTotal+=vProductos[i].precio*cantPedida;
                }
            }
            
            printf("Ingrese la cantidad de productos pedidos:\n");
            cantPedida=leeryvalidarInt(0);         
        }
        else
        {
            printf("Codigo inexistente.\n");
        }
    }

    mostrarProductos(vProductos, cantProductos);
    return 0;
}

int cargaProductos (Producto v[], int ce)
{
    int i=0;
    printf("Ingrese la descripcion del producto:\n");
    fflush(stdin);
    gets(v[i].descripcion);
    while (strcmpi(v[i].descripcion, "FIN")!=0&&i<ce)
    {
        printf("Ingrese el codigo del producto:\n");
        fflush(stdin);
        gets(v[i].codigo);
        printf("Ingrese el precio del producto:\n");
        v[i].precio=leeryvalidarFloat(0);
        printf("Ingrese cantidad de unidades vendidas:\n");
        v[i].uniVendidas=leeryvalidarInt(0);
        printf("Ingrese el importe total vendido el mes anterior:\n");
        v[i].impoTotal=leeryvalidarFloat(0);
        i++;
        printf("Ingrese la descripcion del producto:\n");
        fflush(stdin);
        gets(v[i].descripcion);
    }
    return i;
}

int leeryvalidarInt (int x)
{
    int error=0, dato;
    do
    {
        if (error)
            printf("Dato invalido. Reingrese:\n");
        else
            error=1;
        scanf("%d", &dato);
    } while (dato<x);
    return dato;
}

float leeryvalidarFloat (float x)
{
    int error=0;
    float dato;
    do
    {
        if (error)
            printf("Dato invalido. Reingrese:\n");
        else
            error=1;
        scanf("%f", &dato);
    } while (dato<=x);
    return dato;
}

int busqueda (Producto v[], char c[], int ce)
{
    int i=0, pos=-1;
    while (pos==-1&&i<ce)
    {
        if (strcmpi(v[i].codigo, c)==0)
            pos=i;
        else
            i++;
    }
    return pos;
}

void mostrarProductos(Producto v[], int ce)
{
    int i;
    printf("--LISTADO--\n");
    printf("\n%6s  %-21s%8s","Descripcion","Cant uni vend","Impor total vendido");
    for (i=0;i<ce;i++)
        
            printf("\n%6s  \t%-21d\t%8.2f",v[i].descripcion, v[i].uniVendidas, v[i].impoTotal);
    
}