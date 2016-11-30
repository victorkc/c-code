
#include <stdio.h>
#include <stdlib.h>

//Este programa te dice la letra de tu DNI.
//Se crea un char con todas las letras.
//Pedimos el DNI al usuario.
//Se divide entre 23 y guardamos el resto.
//Imprime la letra correspondiente dependiendo de la posición que le indicamos del resto.

int main(int argc, char *argv[]){

	char tabla[] = "TRWAGMYFPDXBNJZSQVHLCKE";

	int DNI, resto;

	system("clear");
	printf("\n\tIntroduzca tu DNI sin letra: ");
	scanf(" %i", &DNI);

	resto = DNI %23;
	
	printf("\n\tTu letra es la: %c\n\n", tabla[resto]);

	return EXIT_SUCCESS;
}
