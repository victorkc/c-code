#include <stdio.h>
#include <stdlib.h>

#define FILA 3
#define COL  3

int main(int argc, char *argv[]){
	int MX[FILA][COL] = {{1,2,3}, {4,5,6}, {7,8,9}};
	int MY[FILA][COL] = {{1,4,7}, {2,5,8}, {3,6,9}};
	int resultado=0;

	system("clear");

	for(int i=0; i<FILA; i++)
		for(int a=0; a<FILA; a++){
			for(int A=0; A<FILA; A++){
				resultado +=MX[i][A]*MY[A][a];
				if (A==FILA-1){
					printf(" %i", resultado);
					resultado=0;
				}

			}
			if(a==FILA-1)
				printf("\n");
		}


	printf("\n\n");
	return EXIT_SUCCESS;
}
