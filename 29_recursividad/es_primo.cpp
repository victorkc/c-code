#include <stdio.h>
#include <stdlib.h>

bool es_primo(int numero, int divisor){
	if(divisor == 1)
		return true;
	return numero%divisor != 0 && es_primo(numero,divisor-1);
}

int suma_naturales(int n){
	if(n==0)
		return 0;
	return n+suma_naturales(n-1);
}

void imprimir_cadena(const char *p){
	if(*p == '\0')
		return;
	printf("%c", *p);
	return imprimir_cadena(p+1);

}

void imprimir_cadena2(const char *p){
	if(*p == '\0'){
		printf("\n");
		return;
	}
		printf("%c", *p);
		imprimir_cadena(p+1);
	
}

int main(int argc, char *argv[]){

	system("clear");

	if(es_primo(5, 4) == true)
		printf("\n Es primo.");
	else
		printf("\n No es primo.");
	
	printf("\n %i\n", suma_naturales(3));

	imprimir_cadena(" Victor");
	imprimir_cadena2(" Victor");
	
	printf("\n\n");
	return EXIT_SUCCESS;

}
