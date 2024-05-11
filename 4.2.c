/*4.2 Un laboratorio dispone de una lista con sus 50 medicamentos. De cada uno conoce:
• Código del medicamento (entero, de 3 cifras).
• Precio (real).
• Stock (entero).
Se solicita:
a. Declarar un tipo de dato que contenga la información del medicamento.
b. Declarar un vector de estructura de tipo de datos creado en a.
c. Cargar en un sector de estructuras, los datos referentes a los medicamentos. Función INGRESO.
d. Consultar el precio según código del medicamento. Función BUSQUEDA_MEDI.
e. Informar los códigos de los medicamentos cuyo stock es inferior a 10 unidades. Función INFORME.*/

#include <stdio.h>
#include <string.h>
#define TAM 3

typedef struct 
{
    int codMed;
    float precioMed;
    int stockMed;
}Medicamento;

void ingreso(Medicamento[], int);
int busqueda_medi(Medicamento[], int, int);
int sinDuplicado(Medicamento[], int, int);
void informe(Medicamento[], int);
int leeryvalidar1(int, int);
int leeryvalidarInt(int);
float leeryvalidarFloat(float);

int main()
{
    Medicamento vMedi[TAM];
    int pos, cod;
    ingreso(vMedi, TAM);
    printf("Ingrese el codigo para averiguar el precio:\n");
    cod=leeryvalidar1(100,999);
    pos=busqueda_medi(vMedi, cod, TAM);
    if (pos!=-1)
    {
        printf("El precio del codigo %d ingresado es %.2f\n", cod, vMedi[pos].precioMed);
    }
    else
    {
        printf("El codigo ingresado no existe.\n");
    }
    informe(vMedi, TAM);
    return 0;
}

void ingreso(Medicamento v[], int ce)
{
    int i, pos, cod;
    for (i=0; i<ce; i++)
    {
        do
        {
            printf("Ingrese codigo del medicamento:\n");
            cod=leeryvalidar1(100, 999);
            pos=busqueda_medi(v, cod, ce);
            if (pos!=-1)
            {
                printf("Codigo repetido. Vuelva a intentarlo.\n");
            }
        } while (pos!=-1);
        v[i].codMed=cod;
        printf("Ingrese precio del medicamento:\n");
        v[i].precioMed=leeryvalidarFloat(0);
        printf("Ingrese stock del medicamento:\n");
        v[i].stockMed=leeryvalidarInt(0);    
    }
    
}

int busqueda_medi(Medicamento v[], int x, int ce)
{
    int i=0, pos=-1;
    while (pos==-1&&i<ce)
    {
        if (v[i].codMed==x)
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

void informe(Medicamento v[], int ce)
{
    int i;
    for (i=0; i<ce; i++)
    {
        if (v[i].stockMed<10)
        {
            printf("\nEl codigo %d tiene un stock inferior a 10 unidades\n", v[i].codMed);
        }
    }
}

int leeryvalidar1 (int LI, int LS)
{  
    int num, error=0;
    do{
        if(error)
            printf("Valor incorrecto, vuelva a intentarlo:\n");
        else
            error = 1;

        scanf("%d", &num);
    }while(num<LI || num>LS);

    return num;
}

float leeryvalidarFloat(float x)
{
    float num;
    int error=0;
    do
    {
        if (error)
        {
            printf("Valor incorrecto, vuelva a intentarlo:\n");
        }
        else
        {
            error=1;
        }
        scanf("%f", &num);
    } while (num<x);
    return num;
}

int leeryvalidarInt(int x)
{
    int num, error=0;
    do
    {
        if (error)
        {
            printf("Valor incorrecto, vuelva a intentarlo:\n");
        }
        else
        {
            error=1;
        }
        scanf("%d", &num);
    } while (num<x);
    return num;
}