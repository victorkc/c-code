#include <stdio.h>
#include <stdlib.h>

// En este programa se pide un nombre al usuario, se almacena y lo muestra por pantalla.

int main(int argc, char *argv[]){
	char nombre[30];

	printf("\n Dime el nombre que quieres guardar: ");
	scanf(" %s", nombre);
	printf("\n El nombre que has escrito es %s\n\n", nombre);

	return EXIT_SUCCESS;
}
