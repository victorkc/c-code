#include <stdio.h>
#include <stdlib.h>

// Este programa te pregunta la edad, la almacena y te la muestra.

int main(int argc, char *argv[]){
	int edad;

	system("clear");
	printf("\nCuál es tu edad?: ");
	scanf(" %i", &edad);
	printf("Me has dicho que tu edad es %i.\n\n", edad);

	return EXIT_SUCCESS;
}
