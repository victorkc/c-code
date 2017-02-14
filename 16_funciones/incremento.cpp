#include <stdio.h>
#include <stdlib.h>

void incrementa(int *a, int b){
   *a += b; 

}

int main(int argc, char *argv[]){

    int a = 2, b = 5;
	system("clear");

	incrementa(&a, 5);
	incrementa(&b, 3);
	incrementa(&a, -2);

	printf("\n\n");
	return EXIT_SUCCESS;
}
