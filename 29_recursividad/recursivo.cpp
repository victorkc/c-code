#include <stdio.h>
#include <stdlib.h>

int suma(int n){
	if(n == 0)
		return 0;
	return n + suma(n-1);
}

bool es_primo(int n, int divisor){
	if(divisor == 1)
		return true;
 return n%divisor != 0 && es_primo(n, divisor-1);
}

int main(int argc, char *argv[]){
	int n = 5;
	int divisor = n-1;
	int (*puntero_suma)(int n) = &suma;
	int solucion;

	system ("clear");

	if(es_primo(n, divisor) == true)
		printf(" Es primo.\n");
	else
		printf(" No es primo.\n");

	solucion = puntero_suma(n);
	printf(" %i\n", solucion);


	printf("\n\n");
	return EXIT_SUCCESS;
}
