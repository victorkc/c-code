#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 30
#define CANTIDAD(x) (sizeof( (x) ) / sizeof(char *) - 1)

const char *palabra[] = {
    	"patinaje",
    	"baloncesto",
    	"skyrim",
    	"estrambotico",
    	"escambroso",
    	"apoltronar",
    	NULL
};
	const char *elegida;
	char adivinado[MAX];
	int aleatoria,
	    vidas = 5,
	    hay_letra = 0;
	char posible_letra[2];
        char salir[] = {"*"};

void inicio(){ // Se mostrará el menú inicial del juego.
	system("clear");
	printf("\n Bienvenido al ahorcado! Tendrás que advinar una palabra introduciendo caracteres."
	       "\n Tendrás 5 vidas para equivocarte, si tus vidas llegan a 0, GAME OVER\n\n");
}

void generar_palabra(){ // Se genera la palabra aleatoria que se usará en el juego y en un array se ocupa con guiones.
	
	srand(time(NULL));
	aleatoria = rand() % CANTIDAD(palabra);
	elegida = palabra[aleatoria];

	for (int i=0; i<strlen(elegida); i++)	
		adivinado[i] = '-';
   
   	printf("\t%s\n", adivinado);
    	/*printf("\t%s\n\n", elegida); */ // Esta línea está para hacer comprobaciones con la palabra que hay que buscar escrita para ahorrar tiempo.

}

void pregunta(){ // Se realiza la pregunta al usuario sobre la letra que va a querer averiguar.
	printf("\n Te quedan %i vidas."
	       "\n Escribe una letra que creas que está en la palabra que debes averiguar: ", vidas);
	scanf(" %c", posible_letra);
	printf("\n%c\n\n", posible_letra[0]);	
}

void comparar_letra(){ // Comparo la letra introducida para saber si está en la palabra o no. Si la encuentra, sustituye el guión
		       // y coloca la letra correspondiente.
	inicio();
	int letra_encontrada = 0;

	printf("\t");
	for(int i=0; i<strlen(elegida); i++){
		if(posible_letra[0] == elegida[i]){
			adivinado[i] = posible_letra[0];
			letra_encontrada ++;
			hay_letra ++;
		}
  		printf("%c", adivinado[i]);
			}
	printf("\n");
    	/*printf("\t%s\n\n", elegida);*/ // Esta línea está para hacer comprobaciones con la palabra que hay que buscar escrita para ahorrar tiempo.
	if(letra_encontrada == 0){
		vidas --;
		printf("\n La letra %c no está en la palabra", posible_letra[0]);
	}
}

int main(int argc, char *argv[]){ //función principal donde meto todos los void.

    	inicio();
    	generar_palabra();
	do{
    		pregunta();
		comparar_letra();
		if(hay_letra == strlen(elegida)){
			printf("\n Enhorabuena!!! Has encontrado todas las letras de la palabra!!! Que bueno eres!!!\n\n");
			return EXIT_SUCCESS;
		}

	} while (vidas > 0);

	if(vidas == 0);
		printf("\n\n GAME OVER\n\n La palabra entera es %s", elegida);

	printf("\n\n");

    return EXIT_SUCCESS;
                                     
    }
