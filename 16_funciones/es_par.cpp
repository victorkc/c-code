#include <stdio.h>
#include <stdlib.h>

bool es_par(int n){
    return n % 2 == 0;
}

int main(int argc, char *argv[]){

    int numero;
    system("clear");

    printf("\n Numero: ");
    scanf(" %i", &numero);
    printf("\n Tu número %ses par\n", 
	    es_par(numero)? "" : "no ");

    printf("\n\n");
    return EXIT_SUCCESS;
}
