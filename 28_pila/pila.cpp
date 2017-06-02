#include <stdio.h>
#include <stdlib.h>

#define MAX 100


struct Nave{
	int x;
	int y;
};

struct Pila{

	struct Nave *naveEnemiga[MAX];
	int cima;
};

void push(struct Pila *pila, struct Nave *dato){
	pila->naveEnemiga[pila->cima] = dato;
	pila->cima++;

}

void pop{

}

int main(int argc, char *argv[]){

	system ("clear");

	printf("\n\n");
	return EXIT_SUCCESS;
}
