#include <stdlib.h>
#include <stdio.h>

#include "funciones.h"

int
main(int argc, char *argv[]){

	char POrigen, PDestino;
	intro();
	seleccionPlanetas(&POrigen, &PDestino);
	resolucion(&POrigen, &PDestino);

	return EXIT_SUCCESS;

}
