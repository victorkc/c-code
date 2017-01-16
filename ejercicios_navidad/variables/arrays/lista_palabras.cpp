#include <stdio.h>
#include <stdlib.h>

// Imprime una lista de palabras.

int main(int argc, char *argv[]){

	char palabra[][20] = {"Pan","Tortilla","Lechuga"};

	system("clear");
	printf("\n");

	for(int i=0; i<3; i++){
	printf("\n %s", palabra[i]);
	};

	printf("\n\n");
	return EXIT_SUCCESS;
}
