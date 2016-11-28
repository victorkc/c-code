
#include <stdio.h>
#include <stdlib.h>

int main(){

	int amarillo,
	    rojo,
	    azul,
	    volver = 1;

		//Preguntamos los tres colores primarios
		//Comparamos los tres valores y en función de ello nos dan distintos colores.
		//Ej. amarillo = 0, rojo = 0, azul = 1, da 001, por lo que sólo vemos el color azul.
		//Pregunto si quiero volver a adivinar otro color.
	do{
		printf("\nVes el color amarillo? (no=0, si=1)\n");
		scanf(" %i", &amarillo);
	
		printf("\nVes el color rojo? (no=0, si=1)\n");
		scanf(" %i", &rojo);
	
		printf("\nVes el color azul? (no=0, si=1)\n");
		scanf(" %i", &azul);
		
		if (amarillo == 0 && rojo == 0 && azul == 0)
			
			printf("\nEstás viendo el color negro\n\n");
	
		if (amarillo == 0 && rojo == 0 && azul == 1)
		
			printf("\nEstás viendo el color azul\n\n");
	
		if (amarillo == 0 && rojo == 1 && azul == 0)
			
			printf("\nEstás viendo el color rojo\n\n");
	
		if (amarillo == 0 && rojo == 1 && azul == 1)
			
			printf("\nEstás viendo el color morado\n\n");
	
		if (amarillo == 1 && rojo == 0 && azul == 0)
			
			printf("\nEstás viendo el color amarillo\n\n");
	
		if (amarillo == 1 && rojo == 0 && azul == 1)
			
			printf("\nEstás viendo el color verde\n\n");
	
		if (amarillo == 1 && rojo == 1 && azul == 0)
			
			printf("\nEstás viendo el color naranja\n\n");
	
		if (amarillo == 1 && rojo == 1 && azul == 1)
			
			printf("\nEstás viendo el color blanco\n\n");

		printf("Quieres volver a jugar? (no=0, si=1):");
		scanf(" %i", &volver);
		system("clear");
	   }while (volver == 1);

return EXIT_SUCCESS;
}
