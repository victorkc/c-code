#include <stdio.h>
#include <stdlib.h>

#define N 50



int main(int argc, char *argv[]){
	double numero[N];
	double x;
	int num_coeficientes, potencia =  1;
	double resultado = 0;

	system("clear");
	printf("\n Cuántos coeficientes vas a introducir?:");
	scanf(" %i", &num_coeficientes);

	printf("\n Dime el valor de x:");
	scanf(" %lf", &x);

	for(int cont=0; cont<num_coeficientes; cont++ ){
		printf("\n Dime un número: ");
		scanf(" %lf", &numero[cont]);
	}

	for(int pos=0; pos<=num_coeficientes; pos++, potencia *=x)
		resultado += potencia * numero[pos]; 
	printf("\n %.2lf", resultado);	

	printf("\n\n");
	return EXIT_SUCCESS;
}
