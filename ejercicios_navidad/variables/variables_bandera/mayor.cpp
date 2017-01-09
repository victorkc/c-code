#include <stdio.h>
#include <stdlib.h>

// Programa que pregunta 10 números y dice el mayor.

int main(int argc, char *argv[]){

	int contador = 2,
	    num_alto,
	    candidato;

	system("clear");
	printf("\n Introduce el número 1: ");
	scanf(" %i", &num_alto);

	do{
		printf("\n Introduce el número %i: ", contador);
		scanf(" %i", &candidato);
		if(num_alto < candidato)
			num_alto = candidato;
		contador++;

	}while (contador < 11);
	printf("\n El número más alto de todos los que has introducido es el %i\n\n", num_alto);

	return EXIT_SUCCESS;
}
