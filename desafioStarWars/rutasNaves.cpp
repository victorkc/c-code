#include <stdlib.h>
#include <stdio.h>

#include "funciones.cpp"

int
main(int argc, char *argv[]){

	char POrigen, PDestino;
	bool volver=true;
	do{
		intro();
		seleccionPlanetas(&POrigen, &PDestino);
		resolucion(&POrigen, &PDestino);
		reiniciar(&volver);

	}while(volver==true);

			return EXIT_SUCCESS;

	}
