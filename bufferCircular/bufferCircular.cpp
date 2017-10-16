#include <stdlib.h>
#include <stdio.h>

#define N 7

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
}

bool pop(struct TQueue *b)
{
	printf("%c", b->buffer[b->head++]);
}

void print(struct TQueue *b)
{
	for(int i=0; i<N; i++)
		printf("%c", b->buffer[i]);
}

int main(int argc, char *argv){
	unsigned char c;
	struct TQueue bufferCirular
	{
		char buffer[N];
		int summit=0;
		int head=0;	
	}
	int *b;
	*b = bufferCircular;

	c = 'a';

	for(int i=0; i<5; i++)
	{
		push(&b, c+i);
	}
	pop(&b);
	print(&b);

	return EXIT_SUCCESS;
}
