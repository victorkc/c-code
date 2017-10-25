#ifndef __FUNCIONES_H__
#define __FUNCIONES_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>

	void intro(){ //Introducción al programa.

		system ("clear");

		printf("\n\t ¡Bienvenido al programa de resolución de viajes de Star Wars!"
				"\n\n\t Para saber la ruta entre planetas tendrás que escribir el "
				"\n\t nombre del planeta origen y destino para que el programa te" 
				"\n\t lo indique."
				"\n\t Esta versión sólo te permite averiguar el tiempo de trayecto"
				"\n\t entre planetas adyacentes con una posición de distancia."
				"\n\t Los planetas a viajar son desde la \"a\" hasta la \"i\"");

	}

	void
		seleccionPlanetas(char *origen, char *destino){ //petición de planeta origen y destino.

			printf("\n\n\t Escribe la letra del planeta de origen: ");
			scanf(" %c", origen);

			printf("\n\n\t Escribe la letra del planeta de destino: ");
			scanf(" %c", destino);
			printf("\n\n");

		}

	void
		resolucion(char *origen, char *destino){ // Aquí se guardan en una tabla las diferentes combinaciones de planetas a los que viajar.
			char tablaPlanetas[2][13] = {{'a','a','j','h','h','e','e','e','i','d','d','c','f'},
				{'j','b','h','i','e','f','b','d','d','b','c','b','g'}};

			int tiempoViaje[13] = {4,5,4,2,5,3,6,10,3,5,3,4,1}; // Se guardan los tiempos de viaje correspondiendo a la tabla.

			for(int i=0;i<2;i++)
				for(int j=0;j<13;j++)
				{
					if(tablaPlanetas[i][j] == *origen && tablaPlanetas[i+1][j] == *destino) // Si las posiciones del origen y destino coniciden, te dan el tiempo de viaje.
						printf("\n\t Tu viaje de %c hasta %c tarda %i horas.\n\n", *origen, *destino, tiempoViaje[j]);
				}
		}
	void
		reiniciar(bool *volver){ // Pregunta al usuario si quiere buscar otra ruta.
			char reiniciar;
		printf("\t ¿Quieres averiguar el tiempo de otra ruta? (s=si, n=no): ");
		scanf(" %c", &reiniciar);
		if(reiniciar == 'n')
			*volver = false;
		printf("\n");
		}



#ifdef __cplusplus
}
#endif

#endif 
