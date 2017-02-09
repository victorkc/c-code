#include <stdio.h>
#include <stdlib.h>

int suma(int op1, int op2){
    return op1 + op2;
}

int main(int argc, char *argv[]){
    int resultado;

    system("clear");

    resultado = suma(2, 3);
    printf("\n%i", resultado);

    printf("\n\n");
    return EXIT_SUCCESS;
}
