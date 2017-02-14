#include <stdio.h>
#include <stdlib.h>

void leer(double *base, double *exponente){

	printf("\n Base, Exponente: ");
	scanf(" %lf, %lf", base, exponente);
}

int main(int argc, char *argv[]){
    double base, exponente;
    system("clear");

    leer(&base, &exponente);

    printf("%lf, %lf", base, exponente);


    printf("\n\n");
    return EXIT_SUCCESS;
}
