/*2.8 Un consorcio desea controlar la cobranza de las expensas en un edificio de 5 pisos donde existen 15
departamentos en cada piso. El valor de las expensas es de $ 1000. Para registrar la cobranza se ingresa el
número de piso (1 a 5) y el número de departamento (correlativo de 1 a 15 en cada piso). El ingreso finaliza
con un piso igual a 99.
Al finalizar mostrar el dinero total recaudado y una tabla con una X indicando aquellos departamentos
deudores de la siguiente manera:
TOTAL RECAUDADO
DEPARTAMENTOS DEUDORES
PISO DPTO 1 DPTO2 … DPTO 15
PISO 1 X
PISO 2        X        X
PISO 3                 X
PISO 4 X      X
PISO 5 X               X
*/

#include <stdio.h>
#define PISOS 5
#define DPTO 10

int leeryvalidar (int, int, int);
int leeryvalidarPos (int);
void mostrarListado (char[][DPTO], int, int);

int main()
{
    int dpto, piso, exp;
    float recau=0;
    char mExp[PISOS][DPTO]={{' '}};
    printf("Ingrese su piso (1-5, 99 fin):\n");
    piso=leeryvalidar(1, 5, 99);
    while (piso!=99)
    {
        printf("Ingrese su departamento (1-15):\n");
        dpto=leeryvalidar(1, 15, 15);
        printf("Ingrese cuanto abono de expensas:\n");
        exp=leeryvalidarPos(0);
        recau+=exp;
        if (exp<1000)
        {
            fflush(stdin);
            mExp[piso-1][dpto-1]='X';
        }
        printf("Ingrese su piso (1-5, 99 fin):\n");
        piso=leeryvalidar(1, 5, 99);
    }

    printf("\tTOTAL RECAUDADO %.2f\n", recau);
    mostrarListado(mExp, PISOS, DPTO);
    return 0;
}

void mostrarListado (char m[][DPTO], int f, int c)
{
    printf("\tDEPARTAMENTOS DEUDORES\n");
    int i, j;
    printf("PISO/DPTO\t");
    for (j=0;j<c;j++)
    {
        printf("DPTO %d\t", j+1);
    }
    printf("\n");
    for (i=0;i<f;i++)
    {
        printf("PISO %d\t\t", i+1);
        for (j=0;j<c;j++)
        {
            printf("%c\t", m[i][j]);
        }
        printf("\n");
    }
    
}

int leeryvalidar (int LI, int LS, int x)
{
    int dato, band=0;
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
    } while ((dato>LS||dato<LI)&&(dato!=x));
    return dato;
}

int leeryvalidarPos (int x)
{
    int dato, band=0;
    do
    {
        if (band==0)
        {
            scanf ("%d", &dato);
            band=1;
        }
        else
        {
            printf("\nDato erroneo. Reingrese:\n");
            scanf("%d", &dato);
        }
        
    } while (x>dato);
    return dato;
}