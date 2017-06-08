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
crear_nave(struct Pila *pila){
	for(int i = 0; i<MAX; i++){
	pila->naveEnemiga[i]->x = 5;
	pila->naveEnemiga[i]->y = 5;
	pila->naveEnemiga[i]->dibujo = 'K';
	}

}


int main(int argc, char *argv[]){

	system ("clear");
	struct Pila pila;

	crear_nave(&pila);


	printf("\n\n");
	return EXIT_SUCCESS;
}
