//2.1 Ingresar una matriz de 3x3 por teclado y un número entero. Realizar el producto de la matriz por la constante

#include <stdio.h>
#define F 3
#define C 3

void cargaM (int [][3], int, int);
void multiplicar (int [][3], int, int, int);
void mostrarM (int[][3], int, int);

int main ()
{
    int m[3][3], num;
    cargaM(m, F, C);
    printf ("Ingrese escalar:\n");
    scanf ("%d", &num);
    multiplicar (m, F, C, num);
    mostrarM (m, F, C);
}

void cargaM (int m[][3], int f, int c)
{
    int i, j;
    for (i=0; i<f; i++)
    {
        for (j=0; j<c; j++)
        {
            printf ("Ingrese un numero para la posicion [%d][%d]:\n", i, j);
            scanf ("%d", &m[i][j]);
        }
    }
}

void multiplicar (int m[][3], int f, int c, int esc)
{
    int i, j;
    for (i=0; i<f; i++)
    {
        for (j=0; j<c; j++)
        {
            m[i][j]=(m[i][j]*esc);
        }
    }
}

void mostrarM (int m[][3], int f, int c)
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