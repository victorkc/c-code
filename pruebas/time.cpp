#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){

	system ("clear");
	
	time_t t1 = time(0);
	time_t t0 = time(0);

	//time_t tiempo = 
	double tiempo = difftime(t1, t0);

	printf("\n tiempo: %.lf", tiempo+7);

	printf("\n\n");
	return EXIT_SUCCESS;
}
