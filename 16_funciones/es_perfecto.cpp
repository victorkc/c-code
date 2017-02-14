#include <stdio.h>
#include <stdlib.h>

bool es_perfecto(int n){
    int suma_divisores = 1;
    for(int cont=2; cont<n; cont++)	
	if (n%cont == 0)
	    suma_divisores += cont;
    if (suma_divisores == n)
	return true;
    return false;
}

int main(int argc, char *argv[]){

    int numero;
    system("clear");

    printf("\n El número %i %ses perfecto\n", 4, 
	    es_perfecto(4)? "" : "no ");

    printf("\n\n");
    return EXIT_SUCCESS;
}
