#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	int suma = 0,
	    acumulador = 0,
	    numero;

	system("clear");

	do{
		acumulador++;
		printf("\n Escribe el número %i ", acumulador);
		scanf(" %i", &numero);
		suma += numero;

	}while(acumulador < 10);

	printf("\n La media de los números que has introducido es %i\n\n", suma/acumulador);
	
	return EXIT_SUCCESS;
}
