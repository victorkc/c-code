#include <stdio.h>
#include <stdlib.h>

// Este programa almacena un número y dice si tiene un divisor o no.

int main(int argc, char *argv[]){

	int numero,
	    contador = 1,
	    encontrado = 1;

	system("clear");
	printf("\n Escribe el número del que quieras averiguar sus divisores: ");
	scanf(" %i", &numero);

	do{
		if(numero %contador == 0){
			printf("\n El divisor número %i es el %i", encontrado, contador);	
			encontrado ++;
			}
			contador ++;
	}while (contador < numero);
	printf("\n\n");

	return EXIT_SUCCESS;
}
