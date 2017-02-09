#include <stdio.h>
#include <stdlib.h>

// Métase 23<intro> para probar.

int multiplica(int op1, int op2){
    return op1*op2;
}

int main(int argc, char *argv[]){

    int a, b;
    system("clear");
    b = getchar() - '0';
    a = getchar() - '0';

    printf("%ix%i=%i\n", a, b, multiplica(a,b));


    printf("\n\n");
    return EXIT_SUCCESS;
}
