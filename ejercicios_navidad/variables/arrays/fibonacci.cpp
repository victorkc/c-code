#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char **argv){
	int previo_previo = 1,
	    previo = 1,
	    ahora = 0,
	    contador = 0;
	char fibo[20];

	system("clear");

	printf("%i \n", previo_previo);
	printf("%i \n", previo);

	do{

		ahora = previo_previo + previo;
		previo_previo = previo;
		previo = ahora;
		fibo[contador] = ahora;
		printf("\n %i", fibo[contador]);
		contador ++;
	}	while(contador < 20);



	return EXIT_SUCCESS;
}
