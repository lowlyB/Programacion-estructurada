/*Una librería dispone de una lista con 250 artículos. De cada uno conoce:
• Código del articulo (entero, de 4 cifras). validar
• Precio (float &gt; 0). validar
• Stock (entero).
Se solicita desarrollar la codificación en lenguaje “C” que permita:
a. Declarar y cargar en un vector de estructuras, los datos referentes a los artículos.
b. Ingresar un código de articulo y mostrar el precio y el stock en caso de existir en el vector de
estructura. La búsqueda del código de articulo realizarla a través de una función.
c. Informar los códigos de los artículos con stock inferior a 5 unidades./
*/ 
#include <stdio.h>
#include <ctype.h>

#define cant 5 / reemplazar por 250*/


struct articulo
{ int codigo;
  float precio;
  int stock;
};

int busqueda (struct articulo [],int ,int);
int leeyvalida(int li,int ls);

int main()
{ struct articulo art[cant];
  int i, codigo, pos;

  for(i=0;i<cant;i++)
  {
      printf("Articulo:");
      art[i].codigo=leeyvalida(1000,9999);
       printf("precio:");
       scanf("%f",&art[i].precio);
       printf("stock:");
       scanf("%d",&art[i].stock);

  }

  printf("Codigo de articulos menores a tres unidades \n");
    for(i=0;i<cant;i++)
  {
      if(art[i].stock<5)
        printf("Codigo %d\n",art[i].codigo);

  }


  printf("Ingrese el codigo a buscar");
  scanf("%d",&codigo);

  pos=busqueda(art,codigo,cant);
  if (pos!=-1)
    printf("Codigo %d precio %f stock %d",art[pos].codigo,art[pos].precio, art[pos].stock);

return 0;}

int leeyvalida(int li,int ls)
{
    int valor;
    do{scanf("%d",&valor);}
     while(valor<li || valor>ls);
return valor;
}

int busqueda (struct articulo art [],int valor ,int can)
{
    int pos=-1; int i=0;

    while(pos==-1 && i<can)

        {
            if(art[i].codigo==valor)
                pos=i;
            else
                i++;
        }
    return pos;}