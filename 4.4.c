/*4.4 Se ingresan las ventas de un comercio de insumos de computación. 
Por cada venta se ingresa:
• Número de cliente (entero de 4 dígitos no correlativos).
• Importe (mayor a cero).
• Número de vendedor (entero de 1 a 10).
El ingreso de datos finaliza con un número de cliente 999.*/
/*Se sabe que no son más de 100 clientes, la carga de los clientes 
se debe realizar al inicio del programa con la 
función CARGA_CLIENTE () y para cada uno se ingresa:
• Código de cliente (entero de 4 dígitos no correlativos).
• Nombre y Apellido (50 caracteres máximo).*/
/*Se solicita:
a. Determinar la cantidad de ventas realizadas por cliente.
b. La cantidad de ventas realizadas por vendedor.
c. Informar en forma ordenada por total facturado (modo descendente), el total facturado a cada 
cliente, informando:
CODIGO DE CLIENTE NOMBRE Y APELLIDO TOTAL FACTURADO
      XXXXX        XXXXXXXX       $ XXXXXXXXX,XX*/

#include <stdio.h>
#include <string.h>
#define cantClientes 100
#define largoNyA 51

typedef struct 
{
  int nro_cliente;
  float importe;
  int nro_vendedor;
}Venta;

int carga_cliente(int[], char[][largoNyA], int);
int leeryvalidar1(int, int, int, int, int, int, int);
float leeryvalidar2 (float);
int leeryvalidar3 (int, int);
int buscar (int[], int, int);
int buscarIgual (Venta[], int, int);
void carga_venta(Venta[], int[], int);
void informar (Venta[], char[][largoNyA], int);

int main ()
{
      int vCod[cantClientes], clientesCargados;
      char nya[cantClientes][largoNyA];
      clientesCargados=carga_cliente(vCod, nya, cantClientes);
      Venta vVenta[clientesCargados];
      carga_venta(vVenta, vCod, clientesCargados);
      informar (vVenta, nya, clientesCargados);
}

int leeryvalidar1(int LI, int LS, int a, int b, int c, int d, int x)
{
      int error=0, dato;
      do
      {
            if (error)
                  printf("Dato erroneo. Reingrese:\n");
            else
                  error=1;

            scanf("%d", &dato);
      } while (((dato<LI||dato>LS)&&(dato!=x))||(dato==a)||(dato==b)||(dato==c)||(dato==d));
      return dato;     
}

float leeryvalidar2 (float x)
{
      int error=0;
      float dato;
      do
      {
            if(error)
                  printf("Dato erroneo. Reingrese:\n");
            else
                  error=1;
            scanf("%f", &dato);
      } while (dato<=x);
      return dato;
}

int leeryvalidar3 (int LI, int LS)
{
      int error=0, dato;
      do
      {
            if(error)
                  printf("Dato erroneo. Reingrese:\n");
            else
                  error=1;
            scanf("%d", &dato);
      } while (dato<LI||dato>LS);
      return dato;
}

int buscar (int v[], int x, int ce)
{
      int i=0, pos=-1;
      while (pos==-1&&i<ce)
      {
            if (v[i]==x)
                  pos=i;
            else
                  i++;
      }
      return pos;
}

int buscarIgual (Venta v[], int x, int ce)
{
      int i=0, pos=-1;
      while (pos==-1&&i<ce)
      {
            if (v[i].nro_vendedor==x)
                  pos=i;
            else
                  i++;
      }
      return pos;
}

int carga_cliente(int v[], char nya[][largoNyA], int ce)
{
      int i=0, cod, pos;
      do
      {
            printf("Ingrese codigo de cliente:\n");
            cod=leeryvalidar1(1000, 9999, 1111, 2222, 3333, 4444, 999);
            pos=buscar(v, cod, ce);
            if (pos!=-1)
                  printf("Codigo repetido. Reingrese:\n");
      } while (pos!=-1);
      v[i]=cod;
      while (v[i]!=999&&i<ce)
      {
            printf("Ingrese nombre y apellido:\n");
            fflush(stdin);
            gets(nya[i]);
            i++;
            do
            {
                  printf("Ingrese codigo de cliente:\n");
                  cod=leeryvalidar1(1000, 9999, 1111, 2222, 3333, 4444, 999);
                  pos=buscar(v, cod, ce);
                  if (pos!=-1)
                        printf("Codigo repetido. Reingrese:\n");
            } while (pos!=-1);
            v[i]=cod;
      }
      return i;
}

void carga_venta(Venta v[], int c[], int ce)
{
      int i, pos, nroCliente;
      for (i=0; i<ce; i++)
      {
            printf("Ingrese numero de cliente:\n");
            nroCliente=leeryvalidar1(1000, 9999, 1111, 2222, 3333, 4444, 9999);
            pos=buscar(c, nroCliente, ce);
            v[i].nro_cliente=nroCliente;
            if (pos!=-1)
            {
                  printf("Ingrese importe:\n");
                  v[i].importe=leeryvalidar2(0);
                  printf("Ingrese numero de vendedor:\n");
                  v[i].nro_vendedor=leeryvalidar3(1, 10);
            }
            else
            {
                  printf("No existe el numero ingresado.\n");
                  printf("Ingrese numero de cliente:\n");
                  nroCliente=leeryvalidar1(1000, 9999, 1111, 2222, 3333, 4444, 9999);
                  pos=buscar(c, nroCliente, ce);
                  v[i].nro_cliente=nroCliente;
                  if (pos!=-1)
                  {
                        printf("Ingrese importe:\n");
                        v[i].importe=leeryvalidar2(0);
                        printf("Ingrese numero de vendedor:\n");
                        v[i].nro_vendedor=leeryvalidar3(1, 10);
                  }
            }
                  
      }
}

void informar (Venta v[], char nya[][largoNyA], int ce)
{
    int i;
    printf("\n%6s  %-21s%8s","CODIGO DE CLIENTE","NOMBRE Y APELLIDO","TOTAL FACTURADO");
    for (i=0; i<ce; i++)
    {
        printf("\n%6d  \t%-21s\t%8.2f", v[i].nro_cliente, nya[i], v[i].importe);
    }
}