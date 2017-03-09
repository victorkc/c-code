#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curses.h>

#define DELTA .1
#define X 0
#define Y 1

#define XC 20
#define YC 20

struct TCoordenada{
	double x;
	double y;
};

int main(int argc, char *argv[]){
	// a = aceleración, v = velocidad, s = altura.
	// En el struct de abajo hace referencia a que dentro de cada variable como por ejemplo "a", existen las variables "x" e "y". Para hacerle referencia puedo escribir por ejemplo a.x o a.y
		
	struct TCoordenada  a = {0., -10},
						v = {6., 13.},
						s = {0., 0.};

	double tiempo = 0.;

	system("clear");
	initscr(); // Inicia el ncurse.
	curs_set(0); //Apaga el cursor para que no se vea.

	// Paso del tiempo.
	for(tiempo=0; s.y>=0.; tiempo+=DELTA){

		v.y += a.y * DELTA;
		s.y += v.y * DELTA;

		v.x += a.x * DELTA;
		s.x += v.x * DELTA;

		// Enseñar la animación del recorrido de la bala.
		
		clear(); // Limpia el terminal.
		mvprintw(YC-s.y, XC+s.x, "O"); // Comando como printf.
		refresh(); // Actualiza la pantalla para ver qué ocurre, ya que sino no se imprimirá nada por pantalla.
		usleep(100000); // Instrucción para ordenar que se pause el programa, se indica en microsegundos, añadimos 1000 microsegundos que equivalen a 1 milisegundo + 00 para que sea 1 segundo.
	}

	usleep(2000000);
	curs_set(1); // Vuelve a encender el cursor.
	endwin(); // Fin de Ncurse

	printf("\n\n");
	return EXIT_SUCCESS;
}
