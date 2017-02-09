#include <stdio.h>
#include <stdlib.h>

// Programa en el que usamos un menú.

#define MAX 3

int menu(){
	printf("\n Bienvenido al menú de las opciones, de entre las siguientes, elige la opción que más te guste:");
}

const char *opciones[] = {
	"League of legends",
	"Counter strike global offensive",
	"Minecraft",
	NULL
};

int main(int argc, char *argv[]){

    system("clear");

    for(int i=0; i<MAX; i++)
	printf("\n %s", opciones[1]);

    char opcion = menu();
	switch(opcion){
		case 1: 
		    printf("\n Has elegido la opción %s", opciones[1]);
		case 2: 
		    printf("\n Has elegido la opción %s", opciones[2]);
		case 3: 
		    printf("\n Has elegido la opción %s", opciones[3]);
	}

    printf("\n\n");
    return EXIT_SUCCESS;
}
