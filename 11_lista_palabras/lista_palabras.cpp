#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declara un array de N caracteres que se llame buffer.
// Declara una variable que sea un puntero a una palabra.
// Pide al usuario el nombre y guárdalo en la palabra buffer.
// Reservar espacio para la palabra que ha metido el usuario.
// Lo que devuelva malloc se guarda en palabra.
// Copia lo que hay en buffer a palabra.
// Imprime la palabra.
// Libera la memoria de palabra.

#define N 0x100

int main(int argc, char *argv[]){
	char buffer[N];
	char *palabra;
	palabra = buffer;

	system("clear");
	printf("\n Nombre: ");
	fgets(buffer, N, stdin);
	
	palabra = (char *) malloc (strlen(buffer) +1);
	strcpy (palabra, buffer);

	printf("\n %s", palabra);
	free (palabra);

	printf("\n\n");
	return EXIT_SUCCESS;
}
