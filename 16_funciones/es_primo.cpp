#include <stdio.h>
#include <stdlib.h>

bool es_primo(int n){
    for(int cont=2; cont<n; cont++)	
	if (n%cont == 0)
	    return false;
    
    return true;
}

int main(int argc, char *argv[]){

    int numero;
    system("clear");

    printf("\n El número %i %ses primo\n", 8, 
	    es_primo(8)? "" : "no ");

    printf("\n\n");
    return EXIT_SUCCESS;
}
