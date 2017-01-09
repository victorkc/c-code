#include <stdio.h>
#include <stdlib.h>

// Programa que pregunta 10 números y dice el menor.

int main(int argc, char *argv[]){

	int contador = 2,
	    num_bajo,
	    candidato;

	system("clear");
	printf("\n Introduce el número 1: ");
	scanf(" %i", &num_bajo);

	do{
		printf("\n Introduce el número %i: ", contador);
		scanf(" %i", &candidato);
		if(num_bajo > candidato)
			num_bajo = candidato;
		contador++;

	}while (contador < 11);
	printf("\n El número más bajo de todos los que has introducido es el %i\n\n", num_bajo);

	return EXIT_SUCCESS;
}
