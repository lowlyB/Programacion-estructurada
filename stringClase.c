#include <stdio.h>
#include <string.h>

int busqueda (char[], int);


int main()
{
    char nombre1[11], apellido1[11], nombre2[11], apellido2[11], ayn1[23], ayn2[23], band=0;
    printf("Ingrese nombre\n");
    fflush(stdin);
    gets(nombre1);
    printf("Ingrese apellido:\n");
    fflush(stdin);
    gets(apellido1);
    strcpy(nombre2, nombre1);
    do
    {
        if (band==0)
        {
            printf("Ingrese nuevamente apellido:\n");
            fflush(stdin);
            gets(apellido2);
            band=1;
        }
        else
        {
            printf("Apellido distinto. Reingrese.\n");
            fflush(stdin);
            gets(apellido2);
        }
    } while (strcmpi(apellido2, apellido1)!=0);
    
    strcpy(ayn1, nombre1);
    strcat(ayn1, apellido1);
    strcpy(ayn2, nombre1);
    strcat(ayn2, ", ");
    strcat(ayn2, apellido1);

    printf("NOMBRE %s\n", nombre1);
    printf("APELLIDO %s\n", apellido1);
    printf("NOMBRE Y APELLIDO 1: %s\n", ayn1);
    printf("NOMBRE Y APELLIDO 2 %s\n", ayn2);

}

