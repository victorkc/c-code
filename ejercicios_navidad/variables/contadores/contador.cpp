#include <stdio.h>
#include <stdlib.h>

// Este programa te imprime los números del 1 al 100.

int main(int argc, char *argv[]){

	system("clear");
	printf("\n");
	for(int contador = 0; contador < 100; contador++){
	printf("%i ", contador + 1);
	}
	printf("\n\n");

	return EXIT_SUCCESS;
}
