#include <stdio.h>
#include <stdlib.h>

// Rellena una lista de 10 elementos con los cuadrados de los números naturales. 1, 4, 9, 16, ...

int main(int argc, char *argv[]){
	
	int lista[10];

	system("clear");
	for(int i=0; i<10; i++){
		lista[i] = i+1;
		printf("\n%i", lista[i]*lista[i]);
	}
	printf("\n\n");

	return EXIT_SUCCESS;
}
