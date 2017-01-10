#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	int numero,
	    suma_div = 0,
	    div = 1;

	system("clear");
	printf("\n Introduce el número que quieras saber si es perfecto: ");
	scanf(" %i", &numero);

	do{
		if(numero % div == 0)
		suma_div += div;
		div++;
		
	}while (div < numero/2+1);

	if(suma_div == numero)
		printf("\n El número es perfecto.\n\n");
	else
		printf("\n El número no es perfecto.\n\n");

	return EXIT_SUCCESS;
}
