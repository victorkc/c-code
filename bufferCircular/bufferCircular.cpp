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
	if(b->summit >=N)
		return false;
	b->buffer[b->summit++] = c;	
	printf("Push: %c\n", b->buffer[b->summit-1]);
}

bool pop(struct TQueue *b)
{
	printf("%c\n", b->buffer[b->head++]);
}

void print(struct TQueue *b)
{
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
	print(b);

	return EXIT_SUCCESS;
}
