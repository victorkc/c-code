#include <stdio.h>
#include <stdlib.h>

// Inicializa una lista de enteros con los los códigos ascii de las letras de tu nombre. Añade el valor centinela 0 al final.

int main(int argc, char *argv[]){

	char nombre[] = {86,105,99,116,111,114,0};
	system("clear");

	printf("\n %s", nombre);

	printf("\n\n");
	return EXIT_SUCCESS;
}
