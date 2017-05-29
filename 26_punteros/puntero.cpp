#include <stdio.h>
#include <stdlib.h>

enum 
Tfunciones {sumar=0, restar=1, mul=0};

int
suma (int a, int b)
{
  printf ("\n %i", a + b);
  return 0;
}

int
resta (int a, int b)
{
  printf ("\n %i", a - b);
  return 0;
}

int
multiplicar (int a, int b, int c)
{
  printf ("\n %i", a * b * c);
  return 0;
}

int
main (int argc, char *argv[])
{
  system ("clear");
  int a = 2;
  int b = 5;
  int c = 2;

  int *puntero = &a;

  int (*punt_funcion) (int, int) = &suma; // El primer int dice lo que devuelve, se indica el puntero y los 2 int los valores que se le pasan, al final iguala

  int (*punt_2var[3]) (int, int) = {&suma, &resta, NULL};
  int (*punt_3var[2]) (int, int, int) = {&multiplicar, NULL};

  (*punt_2var[sumar]) (a, b);
  (*punt_2var[restar]) (a, b);
  (*punt_3var[mul]) (a, b, c);

  *puntero = 5;
  printf ("\n %i", *puntero);

  (*punt_funcion) (a, b);

  printf ("\n\n");
  return EXIT_SUCCESS;
}
