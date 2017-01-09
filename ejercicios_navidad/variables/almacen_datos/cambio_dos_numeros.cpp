#include <stdio.h>
#include <stdlib.h>

//Este programa almacena dos números y te los devuelve escritos en el orden contrario al que los hayas introducido.

int main(int argc, char *argv[]){
	int numero1, numero2;

	system("clear");
	printf("\n Escribe el primer número: ");
	scanf(" %i", &numero1);
	printf("\n Escribe el segundo número: ");
	scanf(" %i", &numero2);
	printf("\n Te los devuelvo al revés como indica el programa: %i y %i\n\n", numero2, numero1);

	return EXIT_SUCCESS;
}
