/*4.3 Se sabe que como máximo en una comisión de Elementos de Programación hay 80 alumnos. De cada
alumno se conoce:
• Número de DNI (entero).
• Apellido y Nombre (80 caracteres).
• Nota1, Nota2 (entero).
• Nota Promedio (real, calculado según Nota1 y Nota2).
Se solicita:
a. Declarar un tipo de dato que contenga la información del alumno.
b. Declarar un vector de estructuras del tipo de dato creado en el punto a.
c. Cargar en un vector de estructuras, los datos referentes a los alumnos de la comisión, esta
información termina con DNI igual al 0. Función INGRESO.
d. Indicar cuántos alumnos aprobaron (ambos parciales con nota >= 4 y cuántos reprobaron la
materia. Función RESULTADO.
e. Informar los datos de los alumnos de (DNI – Apellido y Nombre – Nota Promedio) de los alumnos.
PROMOCIONADOS (ambas notas >= 7). Función INFORME_PROMO.*/

#include <stdio.h>
#include <string.h>
#define TAM 5

typedef struct
{
    int dni;
    char ayp[81];
    int nota1;
    int nota2;
    float prom;
}Alumno;

int ingreso (Alumno[], int);
int leeryvalidar (int, int, int);
void resultado (Alumno[], int);
int busqueda(Alumno[], int, int);
void informe_promo (Alumno[], int);

int main()
{
    Alumno vAlumnos[TAM];
    int cantCargados;
    cantCargados=ingreso(vAlumnos, TAM);
    resultado(vAlumnos, cantCargados);
    informe_promo(vAlumnos, cantCargados);
}

int ingreso(Alumno v[], int ce)
{
    int i=0, dni, pos;
    
    do
    {
        printf("Ingrese dni:\n");
        dni=leeryvalidar(10000000, 99999999, 0);
        pos=busqueda(v, dni, ce);
        if (pos!=-1)
        {
            printf("Nro de dni repetido. Reingrese:\n");
        }
    } while (pos!=-1);
    v[i].dni=dni;
    while (v[i].dni!=0&&i<ce)
    {
        printf("Ingrese apellido y nombre:\n");
        fflush(stdin);
        gets(v[i].ayp);
        printf("Ingrese nota 1:\n");
        v[i].nota1=leeryvalidar(1, 10, 10);
        printf("Ingrese nota 2:\n");
        v[i].nota2=leeryvalidar(1, 10, 10);
        v[i].prom=(v[i].nota1+v[i].nota2)/2.0;
        i++;
        do
        {
            printf("\n");
            printf("Ingrese dni:\n");
            dni=leeryvalidar(10000000, 99999999, 0);
            pos=busqueda(v, dni, ce);
            if (pos!=-1)
            {
                printf("Nro de dni repetido. Reingrese:\n");
            }
        } while (pos!=-1);
        v[i].dni=dni;
    }
    return i;
}

void resultado(Alumno v[], int ce)
{
    int i, aprobados=0, reprobados=0;
    for (i=0; i<ce; i++)
    {
        if (v[i].nota1>=4&&v[i].nota2>=4) //arreglar aprobados
        {
            if (v[i].nota1<7&&v[i].nota2>=7) 
            {
                aprobados++;
            }
            else
            {
                if (v[i].nota2>=7&&v[i].nota1<7)
                {
                    aprobados++;
                }
                
            }
        }
        else
        {
            reprobados++;
        }
    }
    printf("\nCantidad de alumnos aprobados: %d\nCantidad de alumnos reprobados: %d", aprobados, reprobados);
}

void informe_promo(Alumno v[], int ce)
{
    int i;
    printf("\n--PROMOCIONADOS--\n");
    for (i=0; i<ce; i++)
    {
        if (v[i].nota1>=7&&v[i].nota2>=7)
        {
            printf("DNI: %d\nApellido y nombre: %s\nNota promedio: %.1f\n", v[i].dni, v[i].ayp, v[i].prom);
        }
    }
    
    
}

int leeryvalidar(int LI, int LS, int x)
{  
    int num, error=0;
    do{
        if(error)
            printf("Valor incorrecto, vuelva a intentarlo:\n");
        else
            error = 1;

        scanf("%d", &num);
    }while((num<LI||num>LS)&&(num!=x));
    return num;
}

int busqueda(Alumno v[], int x, int ce)
{
    int i=0, pos=-1;
    while (pos==-1&&i<ce)
    {
        if (v[i].dni==x)
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