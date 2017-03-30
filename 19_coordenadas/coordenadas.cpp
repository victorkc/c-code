#include <stdio.h>
#include <stdlib.h>

#define FILA 4
#define COL  4

typedef struct TCoordenada{
	int x;
	int y;
} Coordenada;

Coordenada a2s(Coordenada pos){
	Coordenada s_pos;
	s_pos.x = 2 * pos.x;
	s_pos.y = 2 * pos.y;

	return s_pos;
}

int main(int argc, char *argv[]){
int fila = FILA;
int col = COL;

Coordenada posicion = {2,3}, buffer;

	buffer = a2s(posicion);

    system("clear");

    printf("\n\n");
    return EXIT_SUCCESS;
}
