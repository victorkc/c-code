#include <stdio.h>
#include <stdlib.h>

#define DELTA 0.001
#define MAX 10
#define AcelX 0
#define AcelY -10

int main(int argc, char *argv[]){
	double velocidad_x, velocidad_y;

	system("clear");

	printf("\n Introduce la velocidad x e y:");
	scanf(" %lf%lf", &velocidad_x, &velocidad_y);
	for(int x = 0; x<MAX; x++){
		printf(" %lf\n", velocidad_x += AcelX*DELTA);
		printf(" %lf\n\n", velocidad_y += AcelY*DELTA);
	}
	printf("\n\n");
	return EXIT_SUCCESS;
}
