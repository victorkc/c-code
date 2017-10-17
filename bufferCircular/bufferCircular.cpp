#include <stdlib.h>
#include <stdio.h>

#define N 10

struct TQueue{
	int buffer[N]; //pila
	int summit;   //cima
	int head;     //cabeza
};

bool push(struct TQueue *b, unsigned char c)
{
	if(b->summit >=N) //si el buffer está lleno, no mete más datos.
	{
		printf("La cima está llena");
		return false;
	}
	if(b->summit == N) //Si llega al tope de la cima, baja al comienzo.
		b->summit = 0;
	if(b->summit == b->head-1) //Al dar la vuelta al buffer circular, si está a la altura del head menos una posición, no hace push.
	{
		printf("El buffer está lleno y la cima está a la misma altura que el head\n");
		return false;
	}
	b->buffer[b->summit++] = c;	
	//printf("Push: %c\n", b->buffer[b->summit-1]); //test del push correcto.
}

bool pop(struct TQueue *b) // Saca un caracter.
{
	printf("pop: %c\n", b->buffer[b->head++]);
}

void print(struct TQueue *b) //Imprime el buffer desde la cabecera.
{
	printf("Buffer: ");
	for(int i=b->head; i<b->summit; i++)
		printf("%c", b->buffer[i]);
	printf("\n");
}

int main(int argc, char *argv[]){
	unsigned char c;
	struct TQueue *b;
	struct TQueue lista;

	b = &lista;
	b->summit=0;
	b->head=0;	
	c = 'a';

	for(int i=0; i<5; i++)
		push(b, c+i);

	for(int i=0; i<3; i++)
		pop(b);
	for(int i=0; i<3; i++)
		push(b, c+i);


	print(b);

	return EXIT_SUCCESS;
}
