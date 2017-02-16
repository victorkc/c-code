#include <stdio.h>
#include <stdlib.h>

#define INCREMENTO 0.001

double x_cuadrado(double x){

	return x*x;
}

double aceleracion(double x){

	return printf("\n %lf", ((x_cuadrado(x+INCREMENTO)) - x_cuadrado(x))/INCREMENTO);

}

int main(int argc, char *argv[]){
	double op1;

    system("clear");
	printf("\n Di el valor de la derivada x que quieres averiguar: ");
	scanf(" %lf", &op1);
	aceleracion(op1);
	

    printf("\n\n");
    return EXIT_SUCCESS;
}
