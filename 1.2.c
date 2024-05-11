/*1.2 Una empresa debe registrar los pedidos recibidos de cada uno sus 10 productos a lo largo del día. Cada
producto está identificado por un código de 4 cifras. Los códigos deben ingresarse al inicio del programa
mediante la función IngresaCódigos y no pueden repetirse.
Por cada pedido se recibe:
• Código de producto
• Cantidad de unidades solicitadas
Se puede recibir más de un pedido por producto.
La carga de pedidos finaliza cuando se ingresa un producto igual a 0
Al finalizar se debe:
a) Emitir un listado con código y cantidad de unidades solicitadas de cada producto.
b) El / los productos del cual se solicitaron mayor cantidad de unidades.
c) El / los productos del cual se solicitaron menos cantidad de unidades.
*/
/*Este ejercicio recuiqere como primer proceso cargar los 10 productos (sin repetición) en un vector.

Luego, Se preocede a cargar las cantidades soclicitadas. 
Entonces, se ingresa el código de producto, si existe en el vector cargado anteriormente se pide la cantidad y 
esa cantidad se acumula en otro vector (paralelo al vector de productos) en la posición que retorno la función de búsqueda. 
Si no existe, se indica con mensaje aclaratorio que no existe y se pide el próximo ingreso.*/

#include <stdio.h>
#define TAM 5

void ingresaCodigos (int[], int);
int buscar (int[], int, int);
int leeryvalidar (int, int, int);
int leeryvalidarPos (int);
void mostrarListado (int[], int[], int);
int maxUni (int[], int);
void buscarMax (int[], int, int, int);



int main ()
{
    int vCod[TAM], vCant[TAM]={0}, cant, cod, pos;
    ingresaCodigos (vCod, TAM);
    printf("--PEDIDO--\n");
    printf("Ingrese codigo de producto (1000-9999, 0 termina):\n");
    cod=leeryvalidar(1000, 9999, 0);
    pos=buscar(vCod, TAM, cod);    
    if (pos==-1)
    {
        printf("Codigo inexistente.\n");
        printf("Ingrese codigo de producto (1000-9999, 0 termina):\n");
        cod=leeryvalidar(1000, 9999, 0);
        pos=buscar(vCod, TAM, cod); 
    }
    while (cod!=0)
    {
        printf("Ingrese cantidad de unidades solicitadas (>=0):\n");
        cant=leeryvalidarPos(0);
        vCant[pos]+=cant;   
        printf("Ingrese codigo de producto (1000-9999, 0 termina):\n");
        cod=leeryvalidar(1000, 9999, 0);
        pos=buscar(vCod, TAM, cod);
    }

    
    mostrarListado (vCod, vCant, TAM);
    return 0;
}

void ingresaCodigos (int v[], int ce)
{
    printf("--CARGA INICIAL--\n");
    int i, pos, cod;
    for (i=0; i<ce; i++)
    {
        do
        {
            printf ("Ingrese codigo de producto (1000-9999):\n");
            cod=leeryvalidar(1000, 9999, 9999);
            pos=buscar (v, i, cod);
            if (pos!=-1)
            {
                printf("Dato repetido. Reingrese:\n");
            }
        } while (pos!=-1);
        v[i]=cod;
    }   
}

int leeryvalidar (int LI, int LS, int x){
    int band=0, dato;
    do
    {
        if (band==0)
        {
            scanf("%d", &dato);
            band=1;
        }
        else
        {
            printf ("Dato erroneo. Reingrese.\n");
            scanf ("%d", &dato);
        }
    } while ((dato<LI||dato>LS)&&(dato!=x));
    return dato;
}

int leeryvalidarPos (int x)
{
    int dato, band=0;
    do
    {
        if (band==0)
        {
            scanf ("%d", &dato);
            band=1;
        }
        else
        {
            printf("\nDato erroneo. Reingrese:\n");
            scanf("%d", &dato);
        }
        
    } while (dato<x);
    return dato;
}

int buscar (int v[], int ce, int x)
{
    int i=0, pos=-1;
    while (pos==-1&&i<ce)
    {
        if (v[i]==x)
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

void mostrarListado (int v1[], int v2[], int ce)
{
    int i;
    printf ("\n---LISTADO---\n");
    for (i=0; i<ce; i++)
    {
        printf("%d\t", v1[i]);
        printf("%d\n", v2[i]);
    }
}

/*
int maxUni (int v[], int ce)
{
    int i, max=v[0];
    for (i=1; i<ce; i++)
    {
        if (v[i]>max)
        {
            max=v[i];
        }
    }
    return max;
}

void buscarMax (int v[], int ce, int x)
{
    int i;
    for (i=0; i<ce; i++)
    {
        if (v[i]==x)
        {
            printf("El maximo de unidades vendidas fue del producto %d\n", pos);
        }
    }
}
*/
