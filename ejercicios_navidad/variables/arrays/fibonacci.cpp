#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char **argv){
	int previo_previo = 1,
	    previo = 1,
	    ahora = 0,
	    contador = 0;
	int fibo[20];

	system("clear");

	printf("\n %i", previo_previo);
	printf("\n %i", previo);

	for(int contador=0; contador<20; contador++){

		ahora = previo_previo + previo;
		previo_previo = previo;
		previo = ahora;
		fibo[contador] = ahora;
		printf("\n %i", fibo[contador]);
		contador ++;
	};

	printf("\n\n");


	return EXIT_SUCCESS;
}
