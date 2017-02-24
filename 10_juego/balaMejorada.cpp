#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curses.h>

#define DELTA .1
#define X 0
#define Y 1

struct TCoordenada{
	double x;
	double y;
};

int main(int argc, char *argv[]){
	// a = aceleración, v = velocidad, s = altura.
	// En el struct de abajo hace referencia a que dentro de cada variable como por ejemplo "a", existen las variables "x" e "y". Para hacerle referencia puedo escribir por ejemplo a.x o a.y
		
	struct TCoordenada  a = {0., -10},
						v = {20., 40.},
						s = {0., 0.};

	double tiempo = 0.;

	system("clear");
	// Paso del tiempo.

	for(tiempo=0; s.y>=0.; tiempo+=DELTA){
		printf(" tiempo [%.2lfs] =>" 
				"v [%.2lfm/s, %.2lfm/s] => "
				"s: [%.2lfm, %.2lfm]\n\n", tiempo, v.y, v.x, s.y, s.x);

		v.y += a.y * DELTA;
		s.y += v.y * DELTA;

		v.x += a.x * DELTA;
		s.x += v.x * DELTA;

	}
	printf("\n\n");
	return EXIT_SUCCESS;
}
