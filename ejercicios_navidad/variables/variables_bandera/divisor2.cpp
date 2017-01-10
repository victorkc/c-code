#include <stdio.h>
#include <stdlib.h>

// Este programa almacena un número y dice si tiene un divisor o no.

int main(int argc, char *argv[]){

	int numero,
	    contador = 2;

	system("clear");
	printf("\n Escribe el número del que quieras averiguar si tiene un divisor: ");
	scanf(" %i", &numero);

	do{
		if(numero %contador == 0){
			printf("\n El número tiene un posible divisor aparte del 1 y él mismo\n\n");	
			return EXIT_SUCCESS;
		}
		contador ++;
	}while (contador < numero-1);

	printf("\n El número no tiene un posible divisor aparte del 1 y él mismo");
	printf("\n\n");

	return EXIT_SUCCESS;
}
