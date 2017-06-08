#include <stdio.h>
#include <stdlib.h>

#define MAX 100


struct Nave{
	int x;
	int y;
	char dibujo;
};

struct Pila{

	struct Nave *naveEnemiga[MAX];
	int cima;
};

void push(struct Pila *pila, struct Nave *dato){
	pila->naveEnemiga[pila->cima] = dato;
	pila->cima++;

}

void
crear_nave(struct *Nave nave){
	struct Nave nave;
	char dibujo nave;

}

void pop{

}

int main(int argc, char *argv[]){

	system ("clear");
	struct Pila pila;

	crear_nave()


	printf("\n\n");
	return EXIT_SUCCESS;
}
