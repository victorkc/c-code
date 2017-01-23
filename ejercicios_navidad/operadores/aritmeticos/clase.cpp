#include <stdio.h>
#include <stdlib.h>

//En una clase con 17 alumnos por fila y 10 filas (Sí, 170 alumnos. ¡Qué desconcierto en la fp!) haz un programa que pregunte el número de lista e indique al alumno la fila y la columna que le corresponden (los alumnos empiezan a numerar por el número 1).)

int main(int argc, char *argv[]){

	int numero = 0,
	    alumno,
	    fila = 0,
	    col = 0;

	system("clear");
	printf("\n Cual es tu número de lista?: ");
	scanf(" %i", &alumno);

	for(fila=1; fila<11; fila++){
		for(col=1; col<18; col++){
			numero ++;
			if(numero == alumno)
			printf("\n Tu posición es la fila %i y la columna %i.", fila, col);
		}
			if(numero == alumno)
			printf("\n Tu posición es la fila %i y la columna %i.", fila, col);
	}

	printf("\n\n");
	return EXIT_SUCCESS;
}
