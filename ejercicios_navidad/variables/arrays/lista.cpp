#include <stdio.h>
#include <stdlib.h>

// Rellena una lista de 10 elementos con los números del 1 al 10.

int main(int argc, char *argv[]){
	
	int lista[10];

	system("clear");
	for(int i=0; i<10; i++){
		lista[i] = i+1;
		printf("\n%i", lista[i]);
	}
	printf("\n\n");

	return EXIT_SUCCESS;
}
