#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ncurses.h>
#include <math.h>
#include "funciones.h"


	int
main (int argc, char *argv[])
{
	srand (time (NULL));
	int maxy;
	int maxx;

	int puntos;
	time_t tiempo_inicio = time(0);

	bool fin = false;
	bool jugar = false;
	bool fin2 = false;
	bool fin1 = false;
	bool again = false;

	struct Nave naveJugador;
	//struct Poder poder;
	struct Pila pila;
	struct Pila pilaPoder;

	pila.cima = 0;
	pilaPoder.cima = 0;

	iniciarPantalla (&maxx, &maxy);
	naveJugador.dibujoNave = 'H';
	naveJugador.coor.y = LINES/2;
	naveJugador.coor.x = COLS/2;

	//poder.dibujoPoder = 'X';

	do
	{
		bordesJuego();
		/*Texto introducción al juego + instrucciones de las teclas*/
		mvprintw(20,65, "Bienvenido! Este es el juego The last one, donde vas a manejar una nave.");
		mvprintw(21,65, "Tu objetivo es  sobrevivir el  máximo de  tiempo que  puedas  acumulando ");
		mvprintw(22,65, "puntos de tiempo o destruyendo tantos enemigos como puedas.");
		mvprintw(24,65, "Los  controles  para mover la nave son: w-arriba, s-abajo, a-izquierda y");
		mvprintw(25,65, "d-derecha, si quieres salir del juego, pulsa la letra 'p'");
		mvprintw(26,65, "Mucha suerte!!");
		mvprintw(28,65, "Pulsa enter para empezar o la letra 'p' para salir del juego...");

		refresh ();		// Actualiza la pantalla para ver el caracter.
		salir_juego(&fin2, &jugar, &again, &fin1);

	}
	while(jugar == false);
	tiempo_inicio = time(0);
	do
	{	

		do
		{

			bordesJuego();
			cuento_puntos(&puntos, tiempo_inicio);
			//crearNave (&pila);
			crearPoder (&pilaPoder);
			/* Movimiento de los actores */
			for (int i = 0; i < pila.cima; i++)
				(pila.naveEnemiga[i].perseguir (&pila.naveEnemiga[i], naveJugador));

			/* Resolución de conflictos */
			fin = muerteJugador(&pila, &naveJugador); /*Debe ir antes del movimiento del jugador
														porque si el jugador pulsa la p para salir
														del juego se sobreescribe al no matarle
														ninguna nave*/

			movimiento (&naveJugador, &fin); /* Esto va despues de las naves, porque si no las
												naves calculan el movimiento respecto de dónde
												va a ir el jugador (anticipan el futuro) y eso
												no es justo para el jugador */

						/* Pintado */
			erase();
			//explosion();
			mostrarPila (pila, pilaPoder);
			mostrarNave (naveJugador);
			activarPoder (&pilaPoder, &naveJugador); /* Función que checkea que el jugador está
													   encima de alguno de los poderes, si es 
													   así, en las coordernadas del poder se 
													   ejecuta el poder.*/


			//mvprintw(6,7, "Ha pasado la línea de llamada a la función activarPoder.");

			//mvprintw(6,6, "y: %.2lf, x: %.2lf", naveJugador.coor.y, naveJugador.coor.x);
			//mvprintw(7,6, "y: %.2lf, x: %.2lf", pilaPoder.poder[0].coor.y, pilaPoder.poder[0].coor.x);
			//refresh ();		// Actualiza la pantalla para ver el caracter.

		}
		while (fin == false  && fin2 == false);
		erase();

		do{
			bordesJuego();
			mvprintw(25,75, "Oh... has perdido, conseguiste %i puntos.", puntos);
			mvprintw(26,75, "Quieres volver a intentarlo? y=si, n=no");
			jugar_otra_vez(&again, &fin, &fin2, &fin1, &pila, &tiempo_inicio, &naveJugador);
			refresh();
		}while(fin1 == false);
		fin1 = false; // para que al volver a jugar no casque a la segunda vuelta.
	}
	while(again == false);

	curs_set (1);
	endwin ();
	return EXIT_SUCCESS;
}
