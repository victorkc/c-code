
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	FILE *tubo; // Stream

	tubo = fopen("iberos.txt", "w");

	printf("hola\n");

	fprintf(stdout, "hola\n");
	fprintf(tubo,"hola!\n");

	fclose(tubo); // Cierra el tubo.

	return EXIT_SUCCESS;
}
