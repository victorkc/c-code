#include <stdio.h>
#include <stdlib.h>

// En este programa se pide una letra, se almacena y te la muestra.

int main(int argc, char *argv[]){
	char letra[1];

	system("clear");
	printf("\nCuál es la letra que quieres guardar?: ");
	scanf(" %c", &letra[0]);
	printf("Me has dicho que tu letra es %c.\n\n", letra[0]);

	return EXIT_SUCCESS;
}
