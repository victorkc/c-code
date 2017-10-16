#include <stdio.h>
#include <stdlib.h>

void cuadrado(int *fila, int *col){

	for(int i=0; i<*fila+1; i++){
		for(int j=0; j<*col+1; j++){
			if(i==0 || j==0 || i==*fila || j==*col)
				printf("x"); 
			else
				printf(" ");

		}
			printf("\n");
	}
			printf("\n");
			*fila +=1;
			*col = *fila*2;

}

int main(int argc, char *argv[]){
	int fila = 1, col = fila*2;

	system ("clear");

	for(int i=0; i<9; i++)
	cuadrado(&fila, &col);

	printf("\n\n");
	return EXIT_SUCCESS;
}
