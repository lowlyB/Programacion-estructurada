/*2.7 Una empresa desea registrar las ventas realizadas de cada uno de sus 20 productos a lo lardo del año. Los
productos están identificados por códigos numéricos de 3 cifras. Como primera información se ingresa el
precio unitario de cada uno de los productos y su código. Luego por cada venta se ingresa:
• Código de producto
• Día de venta
• Mes de venta
• Cantidad de unidades vendidas
El ingreso de datos finaliza con un código de producto igual a 0. Informar:
a. El detalle de unidades vendidas de cada producto en cada uno de los 12 meses.
b. El producto con el cual se obtuvo la mayor recaudación.
c. El trimestre de menor recaudación del año.*/

#include <stdio.h>
#define MES 12
#define PROD 3

int leeryvalidar (int, int, int);
int leeryvalidarPos (int);
void cargaInicial (int[], int[], int);
int buscar (int[], int, int);
void maxProducto (int[], int, int[]);
void minTrimestre (int[], int);
void mostrarM (int[][MES], int[], int, int);

int main()
{
    int m[PROD][MES]={{0}}, vPrecio[PROD], vCod[PROD], vSumaxFila[MES]={0}, vSumaxColumna[PROD]={0}, pos, cod, dia, mes, cant;
    cargaInicial(vPrecio, vCod, PROD);
    printf("--CARGA PEDIDO--\n");
    printf("Ingrese codigo de producto (100-999, 0 fin):\n");
    cod=leeryvalidar(100, 999, 0);
    pos=buscar(vCod, PROD, cod);
    if (pos==-1&&cod!=0)
    {
        printf ("Codigo inexistente.\n");
        printf("Ingrese codigo de producto (100-999, 0 fin):\n");
        cod=leeryvalidar(100, 999, 0);
        pos=buscar(vCod, PROD, cod);
    }
    
    while (cod!=0)
    {
        printf("Ingrese dia de venta:\n");
        dia=leeryvalidar(1, 31, 31);
        printf("Ingrese mes de venta:\n");
        mes=leeryvalidar(1, 12, 12);
        printf("Ingrese cantidad de unidades vendidas:\n");
        cant=leeryvalidarPos(0);
        m[pos][mes-1]+=cant;
        vSumaxFila[pos]+=cant*vPrecio[pos];
        vSumaxColumna[mes-1]+=cant*vPrecio[pos];
        printf("Ingrese codigo de producto (100-999, 0 fin):\n");
        cod=leeryvalidar(100, 999, 0);
        pos=buscar(vCod, PROD, cod);
    }
    
    mostrarM(m, vCod, PROD, MES);
    maxProducto(vSumaxFila, PROD, vCod);
    minTrimestre(vSumaxColumna, MES);
    return 0;
}

void cargaInicial (int vPrecio[], int vCod[], int ce)
{
    printf("--CARGA INICIAL DE PRECIOS Y CODIGOS---\n");
    int i, cod, pos, precio;
    for (i=0; i<ce; i++)
    {
        do
        {
            printf("Ingrese codigo de producto:\n");
            cod=leeryvalidar(100, 999, 999);
            pos=buscar(vCod, i, cod);
            if (pos!=-1)
            {
                printf("Dato repetido. Reingrese.\n");
            }
        } while (pos!=-1);
        vCod[i]=cod;
        printf("Ingrese precio del producto:\n");
        precio=leeryvalidarPos(0);
        vPrecio[i]=precio;
    }  
}

int leeryvalidar (int LI, int LS, int x)
{
    int dato, band=0;
    do
    {
        if (band==0)
        {
            scanf("%d", &dato);
            band=1;
        }
        else
        {
            printf("Dato erroneo. Reingrese:\n");
            scanf("%d", &dato);
        }
    } while ((dato>LS||dato<LI)&&(dato!=x));
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
        
    } while (x>dato);
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

void maxProducto (int vFila[], int ce, int vCod[])
{
    int i, max, pos, band=1;
    for (i=0; i<ce; i++)
    {
        if (band==1||vFila[i]>max)
        {
            max=vFila[i];
            pos=vCod[i];
            band=0;
        }
    }
    printf("\nEl producto de mayor recaudacion es %d y recaudo %d\n", pos, max);
}

void minTrimestre (int vC[], int ce)
{
    int i, band=0, min, pos, vTrim[4]={0};
    for (i=0; i<3; i++)
    {
        vTrim[0]+=vC[i];
    }
    for (i=3; i<6; i++)
    {
        vTrim[1]+=vC[i];
    }
    for (i=6; i<9; i++)
    {
        vTrim[2]+=vC[i];
    }
    for (i=9; i<ce; i++)
    {
        vTrim[3]+=vC[i];
    }

    for (i=0; i<5; i++)
    {
        if (band==0||min<vTrim[i])
        {
            min=vTrim[i];
            pos=i;
        }
    }
    printf("El trimestre de menor recaudacion del año es: %d\n", pos);
    
    
}

void mostrarM (int m[][MES], int v[], int f, int c)
{
    printf("--LISTADO PEDIDOS--\n");
    printf("COD/MES\t");
    int i, j;
    for (j=0; j<c; j++)
    {
        printf("MES %d\t", j+1);
    }
    printf("\n");
    for (i=0; i<f; i++)
    {
        printf("COD %d\t", v[i]);
        for (j=0; j<c; j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}

