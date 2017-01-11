#include <stdio.h>
#include <stdlib.h>

// Programa que calcula el producto escalar de dos vectores de dimensión n.
int main(int argc, char *argv[]){

	int vector1 [2],
	    vector2 [2];

	system("clear");
	printf("\n Indica el vector 1 de la dimensión a: ");
	scanf(" %i", &vector1 [0]);
	printf("\n Indica el vector 2 de la dimensión a: ");
	scanf(" %i", &vector2 [0]);
	printf("\n Indica el vector 1 de la dimensión b: ");
	scanf(" %i", &vector1 [1]);
	printf("\n Indica el vector 2 de la dimensión b: ");
	scanf(" %i", &vector2 [1]);

	printf("\n El resultado es el %i.\n\n", vector1[0]*vector2[0] + vector1[1]*vector2[1]);



	return EXIT_SUCCESS;
}
