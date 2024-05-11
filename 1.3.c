/*1.4 Se ingresan DNI y nota de un parcial de los alumnos de un curso. El ingreso de datos finaliza con un DNI
negativo. Se sabe que como máximo pueden presentarse a rendir 60 alumnos. Tenga en cuenta que no
pueden existir 2 o más alumnos con el mismo DNI.
Mostrar el Listado de alumnos con su correspondiente DNI y la nota obtenida (en forma de listado), ordenado
de mayor a menor por nota.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargaDNI (int[], int);
int buscarIgual (int[], int, int);
int leeryvalidar (int, int);
void mostrarListado (int[], int[], int);

int main ()
{
    int vDNI[60], vNota[60], i, nota;
    printf("Ingrese dni completo:\n");
    cargaDNI(vDNI, 60);
    while (vDNI[i]>0)
    {
        printf("Ingrese nota:\n");
        nota=leeryvalidar(1, 10);
        vNota[i]=nota;
        i++;
    }
    mostrarListado(vDNI, vNota, 60);
    return 0;
}

void cargaDNI (int v[], int ce)
{
    int i, pos, dni;
    for (i=0; i<ce; i++)
    {
       do
       {
            scanf("%d", &dni);
            pos=buscarIgual(v, 60, i);
            if (pos!=-1)
            {
                printf("Dato repetido. Reingrese:\n");
            }
       } while (pos!=-1);
        v[i]=dni;   
    }
    
    
}

int buscarIgual (int v[], int ce, int x)
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

int leeryvalidar (int LI, int LS)
{
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
    } while ((dato<LI||dato>LS)&&(dato!=0));
    return dato;
}