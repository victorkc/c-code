#include <stdio.h>
#include <stdlib.h>

#define DELTA .1

int main(int argc, char *argv[]){
	double aceleracion = -10;
    double velocidad = 40.;
	double tiempo = 0.;
	double altura = 0.;

	system("clear");
// Paso del tiempo.

	for(tiempo=0; altura>=0.; tiempo+=DELTA){
		printf(" tiempo [%.2lfs] => velocidad [%.2lfm/s] => altura: %.2lf\n\n", tiempo, velocidad, altura);
		velocidad += aceleracion * DELTA;
	   	altura	  += velocidad * DELTA;
	}
	printf("\n\n");
	return EXIT_SUCCESS;
}
