/*3.4 Se ingresan código y precio unitario de los productos que vende un negocio. No se sabe la cantidad exacta
de productos, pero sí se sabe que son menos de 50. El código es alfanumérico de 3 caracteres y la carga de
los datos de productos termina con un código igual al “FIN”. Luego se registran las ventas del día y por cada
venta se ingresa el código de producto y cantidad de unidades vendidas terminando con una cantidad igual
a 0. Se solicita:
a. Calcular la recaudación total del día y el producto del cual se vendió menor cantidad de unidades.
b. Mostrar el listado de productos con su precio ordenado en forma alfabética por código de producto.*/

#include <stdio.h>
#include <string.h>

void cargaInicial (char [][4], float[], int);
int leeryvalidarint (int);
float leeryvalidarfloat (float);
int buscar (char [][4], char[], int);
//void minProd (int[], char[][4], int);


int main()
{
    int pos, uni, vUni[50], venta=0;
    char cod[50][4], buscarCod[4], recau=0;
    float vPrecio[50];
    printf("--CARGA INICIAL--\n");
    cargaInicial(cod, vPrecio, 50);
    printf("--VENTAS DEL DIA--\n");
    printf("Ingrese codigo de producto:\n");
    fflush(stdin);
    gets(buscarCod);
    pos=buscar(cod, buscarCod, 4);
    if (pos==-1)
    {
        printf("No existe el codigo ingresado.\n");
    }
    else
    {
        printf("Ingrese cantidad de unidades vendidas (0 para terminar):\n");
        uni=leeryvalidarint(0);
        while (uni!=0)
        {
            venta++;
            vUni[pos]+=uni;
            recau+=vUni[pos]*vPrecio[pos];
            printf("Ingrese codigo de producto:\n");
            fflush(stdin);
            gets(buscarCod);
            pos=buscar(cod, buscarCod, 4);
            if (pos==-1)
            {
                printf("No existe el codigo ingresado.\n");
            }
            else
            {
                printf("Ingrese cantidad de unidades vendidas (0 para terminar):\n");
                uni=leeryvalidarint(0);
            }
        }
        
    }
    //minProd(vUni, cod, venta);
}

void cargaInicial (char c[][4], float v[], int ce)
{
    int i=0;
    float precio;
    printf("Ingrese codigo del producto (3 carac, 'FIN' para terminar):\n");
    fflush(stdin);
    gets(c[i]);
    while (strcmpi(c[i], "FIN")!=0&&i<ce)
    {
        printf("Ingrese precio del producto:\n");
        precio=leeryvalidarfloat(0);
        v[i]=precio;
        i++;
        printf("Ingrese codigo del producto (3 carac, 'FIN' para terminar):\n");
        fflush(stdin);
        gets(c[i]);
    }
}

int buscar (char c[][4], char x[], int ce)
{
    int i=0, pos=-1;
    while (pos==-1&&i<ce)
    {
        if (strcmpi(c[i], x)!=0)
        {
            pos=i;
        }
        else
        {
            i++;
        }
    }
    return pos;
}

float leeryvalidarfloat (float x)
{
    int band=0;
    float dato;
    do
    {
        if (band==0)
        {
            scanf("%f", &dato);
        }
        else
        {
            printf("Dato erroneo. Reingrese:\n");
            scanf("%f", &dato);
        }
        
    } while (dato<=x);
    return dato;
}

int leeryvalidarint (int x)
{
    int band=0, dato;
    do
    {
        if (band==0)
        {
            scanf("%d", &dato);
        }
        else
        {
            printf("Dato erroneo. Reingrese:\n");
            scanf("%d", &dato);
        }
        
    } while (dato<x);
    return dato;
}

/*void minProd (int v[], char c[][4], int ce)
{
    int min, band=0, i;
    char pos;
    for (i=0; i<ce; i++)
    {
        if (band==0||v[i]<min)
        {
            min=v[i];
            pos=c[i];
            band=1;
        }
    }
    printf("El producto que recaudo la menor cantidad de unidades vendidas es: %c\n", pos);
}
*/