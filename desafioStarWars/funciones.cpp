#include "funciones.h"

void
intro(){ //Introducción al programa.

	system ("clear");

printf("\n\t\t ¡Bienvenido al programa de resolución de viajes de Star Wars!"
		"\n\n\t\t Para saber la ruta entre planetas tendrás que escribir el "
		"\n\t\t nombre del planeta origen y destino para que el programa te" 
		"\n\t\t lo indique."
		"\n\t\t Esta versión sólo te permite averiguar el tiempo de trayecto"
	    "\n\t\t entre planetas adyacentes con una posición de distancia.");

}

void
seleccionPlanetas(char *origen, char *destino){ //petición de planeta origen y destino.

printf("\n\n\t\t Escribe la letra del planeta de origen: ");
scanf("%c", origen);
printf("\n\n\t\t Escribe la letra del planeta de destino: ");
scanf("%c", destino);
}

void
resolucion(char *destino, char *origen){

}
