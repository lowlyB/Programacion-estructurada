/*1.1 Cargar de forma aleatoria un vector de 20 elementos con números de 3 cifras.
a. Mostrar el menor valor e indicar cuantas veces se repite
b. Mostrar el mayor valor e indicar en que posición/posiciones se encuentra*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargaVec (int[], int, int);
void mostrarVec (int[], int);
int minimo (int[], int);
int buscarMin (int[], int, int);
int maximo (int[], int);
void buscarMaxPos (int[], int, int);


int main()
{
    int vec[20], min, cont, max;
    srand(time(NULL));
    cargaVec (vec, 20, 1000);
    mostrarVec (vec, 20);
    min=minimo (vec, 20);
    cont=buscarMin (vec, 20, min);
    printf ("El minimo es %d y se repite %d veces.\n", min, cont);
    max=maximo (vec, 20);
    printf("El maximo es %d\n", max);
    buscarMaxPos (vec, 20, max);
    return 0;
}

void cargaVec (int v[], int ce, int max)
{
    int i;
    for (i=0; i<ce; i++)
    {
        v[i]=rand()%max; 
    }
}

void mostrarVec (int v[], int ce)
{
    int i;
    printf ("---VECTOR ALEATORIO---\n");
    for (i=0; i<ce; i++)
    {
        printf("%d\n", v[i]);
    }
}

int minimo (int v[], int ce)
{
    int i, min=v[0];
    for (i=1; i<ce; i++)
    {
        if (v[i]<min)
        {
            min=v[i];
        }
    }
    return min;
}

int buscarMin (int v[], int ce, int min)
{
    int i, cont=0;
    for (i=0; i<ce; i++)
    {
        if (v[i]==min)
        {
            cont++;
        }
    }
    return cont;
}

int maximo (int v[], int ce)
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

void buscarMaxPos (int v[], int ce, int dato)
{
    int i=0, pos=-1;
    while (pos==-1&&i<ce)
    {
        if (v[i]==dato)
        {
            pos=i;
            printf ("El maximo se encontro en la posicion %d\n", pos+1);
        }
        else
        {
            i++;
        } 
    }
}