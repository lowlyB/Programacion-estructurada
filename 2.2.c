/* 2.2 Ingresar una matriz de 5x4 por teclado. Realizar una función que genere un vector con la suma por fila de
dicha matriz y otra función que calcule la suma por columna en otro vector.*/

#include <stdio.h>
#define F 5
#define C 4

void cargaM (int[][4], int, int);
void SxF (int [][4], int[], int, int);
void SxC (int[][4], int [], int, int);
void mostrar (int[][4], int[], int[], int, int);

int main ()
{
    int m[F][C], vSxF[F]={0}, vSxC[C]={0};
    cargaM(m, F, C);
    SxF(m, vSxF, F, C);
    SxC(m, vSxC, F, C);
    mostrar (m, vSxF, vSxC, F, C);
}

void cargaM (int m[][4], int f, int c)
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

void SxF (int m[][4], int v[], int f, int c)
{
    int i, j;
    for (i=0; i<f; i++)
    {
        for (j=0; j<c; j++)
        {
            v[i]+=m[i][j];
        }  
    }
}

void SxC (int m[][4], int v[], int f, int c)
{
    int i, j;
    for (j=0; j<c; j++)
    {
        for (i=0; i<f; i++)
        {
            v[j]+=m[i][j];
        }  
    }
}

void mostrar (int m[][4], int vf[], int vc[], int f, int c)
{
    int i, j;
    printf("--MATRIZ TOTAL--\n");
    for (i=0; i<f; i++)
    {
        for (j=0; j<c; j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    printf ("\nSUMA POR FILA\n");
    for (i=0; i<f; i++)
    {
        printf("%d\t", vf[i]);
    }
    printf("\n");

    printf ("\nSUMA POR COLUMNA\n");
    for (i=0; i<c; i++)
    {
        printf("%d\t", vc[i]);
    }
    printf("\n");
    
}



