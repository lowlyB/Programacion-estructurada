/*ingresar una frase */
#include <stdio.h>
#include <string.h>

int main ()
{
    char frase [501];
    int tam, i=0, cont = 0;
    printf ("\n Ingrese una frase:\n");
    fflush (stdin);
    gets (frase);

    tam= strlen (frase);

    while (i<tam)
    {
        if (frase[i]==' ')
        {
        cont ++;
        }

        i++;
        
    }

    printf ("\n la cantidad de palabras son: %d", cont+1);

    return 0;
    

}
