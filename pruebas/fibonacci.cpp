#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char **argv){
	int previo_previo = 0;
	int previo = 1;
       	int ahora = 0;
       	int contador = 0;

		printf("%i \n", previo_previo);
		printf("%i \n", previo);

	do{

		ahora = previo_previo + previo;
		previo_previo = previo;
		previo = ahora;
		contador ++;
		printf("%i \n", ahora);
	}	while(contador < 100)



	return EXIT_SUCCESS;
}
