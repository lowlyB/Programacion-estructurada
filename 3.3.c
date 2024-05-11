/*3.3 Ingresar nombre y DNI de los alumnos de un curso. 
Como máximo el curso puede tener 50 alumnos. 
La carga finaliza con un alumno de nombre FIN. Luego de cargar los alumnos se pide:
a. Ingresar nombres de a uno en uno y buscarlos. Si el nombre está en el curso mostrar 
su DNI y sino informar que no está. 
Seguir ingresando nombres hasta que se ingrese un nombre igual a 
NOBUSCARMAS.
b. Mostrar el listado de alumnos ordenado alfabéticamente de menor a mayor.*/

#include <stdio.h>
#include <string.h>

int cargaAlumnos (char[][11], int[], int);
int buscar (char[][11], char[], int);
void mostrarListado (char[][11], int);
int leeryvalidar (int, int);

int main ()
{
    char mNombre[50][11], buscarNombre[11];
    int pos, cant, dni[50];
    cant=cargaAlumnos(mNombre, dni, 50);
    printf("Reingrese un nombre del curso (hasta 10 caracteres, NOBUSCARMAS para cerrar):\n");
    fflush(stdin);
    gets(buscarNombre);
    while (strcmpi(buscarNombre, "NOBUSCARMAS")!=0)
    {
        pos=buscar(mNombre, buscarNombre, 50);
        if (pos!=-1)
        {
            printf("El nombre fue encontrado. Su DNI es: %d\n", dni[pos]);
        }
        else
        {
            printf("No se encontro el nombre ingresado.\n");
        }
        printf("Reingrese un nombre del curso (hasta 10 caracteres, NOBUSCARMAS para cerrar):\n");
        fflush(stdin);
        gets(buscarNombre);
    }
    
    mostrarListado(mNombre, cant);
}

int cargaAlumnos (char n[][11], int dni[], int ce)
{
    int dato, i=0;
    printf("Ingrese nombre (hasta 10 caracteres):\n");
    fflush(stdin);
    gets(n[i]);
    while (strcmpi(n[i], "FIN")!=0&&i<ce)
    {
        printf("Ingrese dni (hasta 8 caracteres):\n");
        dato=leeryvalidar(10000000, 99999999);
        dni[i]=dato;
        i++;
        printf("Ingrese nombre (hasta 10 caracteres):\n");
        fflush(stdin);
        gets(n[i]); 
    }
    return i;
}

int buscar (char n[][11], char buscarN[], int ce)
{
    int pos=-1, i=0;
    while (pos==-1&&i<ce)
    {
        if (strcmpi(n[i], buscarN)==0)
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

void mostrarListado (char n[][11], int ce)
{
    int i;
    printf("--LISTADO NOMBRES--\n");
    for (i=0; i<ce; i++)
    {
        puts(n[i]);
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
            printf("Dato erroneo. Reingrese:\n");
            scanf("%d", &dato);
        }
    } while (dato>LS||dato<LI);
    return dato;
}