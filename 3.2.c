#include <stdio.h>
#include <string.h>

int main ()
{
    char vNombre[11], vApellido[11], vNyA[23];
    printf("Ingrese su nombre:\n");
    fflush(stdin);
    gets(vNombre);
    printf("Ingrese su apellido:\n");
    fflush(stdin);
    gets(vApellido);
    strcpy(vNyA, vNombre);
    strcat(vNyA, ", ");
    strcat(vNyA, vApellido);
    printf("Nombre y apellido ingresado:\n");
    printf("%s", vNyA);
}