/*2.3 Cargar de forma aleatoria una matriz de 5 x 8 con números de 2 cifras. Determinar el máximo valor
almacenado en la matriz indicando cuantas veces se repite y en que posiciones.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define F 5
#define C 8

void cargaM (int[][C], int, int, int);
void mostrarM (int[][C], int, int);
int maxM (int[][C], int, int);
void buscarMax (int[][C], int, int, int);

int main ()
{
    int m[F][C], max;
    srand(time(NULL));
    cargaM(m, F, C, 100);
    mostrarM (m, F, C);
    max=maxM(m, F, C);
    buscarMax(m, F, C, max);
}

void cargaM(int m[][C], int f, int c, int cifra)
{
    int i, j;
    for (i=0; i<f; i++)
    {
        for (j=0; j<c; j++)
        {
            m[i][j]=rand()%cifra;
        }
    }
}

void mostrarM (int m[][C], int f, int c)
{
    int i, j;
    printf("--MATRIZ COMPLETA--\n");
    for (i=0; i<f; i++)
    {
        for (j=0; j<c; j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}

int maxM (int m[][C], int f, int c)
{
    int i, j, max=m[0][0];
    for (i=0; i<f; i++)
    {
        for (j=1; j<c; j++)
        {
            if (m[i][j]>max)
            {
                max=m[i][j];
            }
        }
    }
    return max;   
}

void buscarMax (int m[][C], int f, int c, int x)
{
    int i, j, cont=0;
    printf ("\nEl maximo es %d\n", x);
    for (i=0; i<f; i++)
    {
        for (j=0; j<c; j++)
        {
            if (m[i][j]==x)
            {
                printf("El maximo se encontro en la posicion [%d][%d]\n", i+1, j+1);
                cont++;
            }
        }
    }
    printf("El maximo se encontro %d veces\n", cont);  
}
