#include <stdio.h>
#include <stdlib.h>

#define DELTA .1

int main(int argc, char *argv[]){
	double aceleracion_x =  0.;
	double velocidad_x = 	20.;
	double altura_x = 		0.;

	double aceleracion_y = -10;
	double velocidad_y = 	40.;
	double altura_y =	    0.;


	double tiempo = 0.;

	system("clear");
	// Paso del tiempo.

	for(tiempo=0; altura_y>=0.; tiempo+=DELTA){
		printf(" tiempo [%.2lfs] =>" 
				"velocidad [%.2lfm/s, %.2lfm/s] => "
				"altura: [%.2lfm, %.2lfm]\n\n", tiempo, velocidad_y, velocidad_x, altura_y, altura_x);

		velocidad_y += aceleracion_y * DELTA;
		altura_y    += velocidad_y * DELTA;

		velocidad_x += aceleracion_x * DELTA;
		altura_x    += velocidad_x * DELTA;

	}
	printf("\n\n");
	return EXIT_SUCCESS;
}
