/*2.4 La empresa de turismo GUADALAJARA VIAJES comercializa 10 diferentes tours a través de 15 agencias en todo
el país. Diariamente cada agencia envía la cantidad de ventas efectuadas de cada tour, indicando agencia,
tours y la cantidad de pasajes. Algunas agencias envían 0 en la cantidad cuando no existen pasajes para un
tour determinado, pero no en todas.
La información que se envía tiene los siguientes datos que se ingresan en forma desordenada:
• Código de agencia (de 1 a 15)
• Código de tour (1 a 10)
• Cantidad de pasajes (0 a 20)
Informar:
a. El total de pasajes vendidos por tour en cada agencia.
b. El número de agencia que obtuvo la máxima cantidad de pasajes vendidos. (puede repetirse)*/

#include <stdio.h>
#define TOUR 10
#define AGEN 15

void cargaM (int[][TOUR], int, int);
int leeryvalidar (int, int);
int maxAgencia (int[], int);
void buscarMax (int[], int, int);
void mostrarM (int[][TOUR], int, int);

int main ()
{
    int mViajes[AGEN][TOUR]={{0}}, vAgencia[AGEN]={0};
    int agencia, tour, cant, max;
    printf("Ingrese codigo de agencia (1-15, 0 para salir):\n");
    agencia=leeryvalidar(0, 15);
    while (agencia!=0)
    {
        printf("Ingrese codigo de tour:\n");
        tour=leeryvalidar(1, 10);
        printf("Ingrese cantidad de pasajes:\n");
        cant=leeryvalidar(0, 20);
        mViajes[agencia-1][tour-1]+=cant;
        vAgencia[agencia-1]+=cant;
        printf("Ingrese codigo de agencia (1-15, 0 para salir):\n");
        agencia=leeryvalidar(0, 15);
    }
    mostrarM (mViajes, AGEN, TOUR);
    max=maxAgencia(vAgencia, AGEN);
    buscarMax(vAgencia, AGEN, max);
}

int leeryvalidar (int LI, int LS)
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
    } while (dato>LS||dato<LI);
    return dato;
    
}

void mostrarM (int m[][TOUR], int f, int c)
{
    int i, j;
    printf("--VIAJES--\n");
    printf("AGE/TOUR\t");
    for (j=0; j<c; j++)
    {
        printf("TOUR %d\t", j+1);
    }
    printf ("\n");
    for (i=0; i<f; i++)
    {
        printf("AGE %d\t\t", i+1);
        for (j=0; j<c; j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}

int maxAgencia (int v[], int ce)
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
            printf("El numero de agencia que obtuvo la maxima cantidad de pasajes vendidos fue %d\n", i+1);
        }
    }
}