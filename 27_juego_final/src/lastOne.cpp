#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ncurses.h>
#include <math.h>

#define MAX 100
#define MAXX 54
#define MAXY 203
#define VELOCIDAD 0.2 
#define CREAR 2


struct Coordenadas
{
	double x;
	double y;
};

struct Nave
{
	struct Coordenadas coor;
	char dibujoNave;
	void (*perseguir) (struct Nave *, struct Nave);
};

struct Pila
{
	struct Nave naveEnemiga[MAX];
	int cima;
};

/*struct Poder
  {
  struct Coordenadas coor;
  char dibujoPoder;
  };
  */

	void
perseguirJugador (struct Nave *naveEnemiga, struct Nave naveJugador)
{

	if (naveEnemiga->coor.x > naveJugador.coor.x)
		naveEnemiga->coor.x -= VELOCIDAD;
	if (naveEnemiga->coor.y > naveJugador.coor.y)
		naveEnemiga->coor.y -= VELOCIDAD;
	if (naveEnemiga->coor.x < naveJugador.coor.x)
		naveEnemiga->coor.x += VELOCIDAD;
	if (naveEnemiga->coor.y < naveJugador.coor.y)
		naveEnemiga->coor.y += VELOCIDAD;
}



	void
iniciarPantalla (int *maxx, int *maxy)
{				//ncurses

	WINDOW *w;
	w = initscr ();		//inicia la pantalla
	curs_set (0);			//Desactiva cursor
	noecho ();			//Sin mostrar el caracter pulsado
	keypad (stdscr, 1);	//Teclas especiales
	halfdelay (1);		//Hace que getch no interrumpa la ejecución del programa
	*maxx = COLS;
	*maxy = LINES;

}

	void
crearNave (struct Pila *pila)
{
	static int creadas = 0;
	static time_t ultima_creada = time(0);
	time_t ahora = time(0);

	  if(difftime(ahora, ultima_creada) < CREAR)
		return;
	ultima_creada = ahora;

	if (pila->cima == MAX)
		return;

	/*Asigna coor aleatorias, la funcion para perseguir al jugador y el caracter de la nave enemiga */
	pila->naveEnemiga[pila->cima].coor.x = rand () % COLS;
	pila->naveEnemiga[pila->cima].coor.y = rand () % LINES;
	pila->naveEnemiga[pila->cima].perseguir = &perseguirJugador;
	pila->naveEnemiga[pila->cima++].dibujoNave = 'O';
	creadas++;
}

	void
mostrarPila (struct Pila pila)
{
	for (int i = 0; i < pila.cima; i++)
	{
		mvprintw (pila.naveEnemiga[i].coor.y, pila.naveEnemiga[i].coor.x, "%c",
				pila.naveEnemiga[i].dibujoNave);
	}
}

	void
mostrarNave (struct Nave naveJugador)
{
	mvprintw (naveJugador.coor.y, naveJugador.coor.x, "%c",
			naveJugador.dibujoNave);
}

	void
movimiento (struct Nave *naveJugador, bool *fin)
{
	char letra_movimiento;
	letra_movimiento = getch ();
	if (letra_movimiento == 'a')
		naveJugador->coor.x--;
	if (letra_movimiento == 'd')
		naveJugador->coor.x++;
	if (letra_movimiento == 'w')
		naveJugador->coor.y--;
	if (letra_movimiento == 's')
		naveJugador->coor.y++;
	if (letra_movimiento == 'p'){
		*fin = true;

	}

}

/* Devuelve true si se lo cargan */
	bool
muerteJugador (struct Pila *pila, struct Nave *naveJugador)
{
	for(int i=0; i<pila->cima; i++)
		//if (Math.Truncate(x) == Math.Truncate(y))
		if((trunc(pila->naveEnemiga[i].coor.x) == naveJugador->coor.x) && (trunc(pila->naveEnemiga[i].coor.y) == naveJugador->coor.y))
			return true;

	return false;
}

	int
main (int argc, char *argv[])
{
	srand (time (NULL));
	int maxy;
	int maxx;
	long int tempo = 0;
	bool fin = false;

	struct Nave naveJugador;
	//struct Poder poder;
	struct Pila pila;
	pila.cima = 0;

	iniciarPantalla (&maxx, &maxy);
	naveJugador.dibujoNave = 'H';
	naveJugador.coor.y = 25;
	naveJugador.coor.x = 102;

	//poder.dibujoPoder = 'X';

	do
	{
		crearNave (&pila);
		/* Movimiento de los actores */
		for (int i = 0; i < pila.cima; i++)
			(pila.naveEnemiga[i].perseguir) (&pila.naveEnemiga[i], naveJugador);

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
		mostrarPila (pila);
		mostrarNave (naveJugador);
		mvprintw(6,6, "y: %.2lf, x: %.2lf", naveJugador.coor.y, naveJugador.coor.x);
		mvprintw(7,6, "y: %.2lf, x: %.2lf", pila.naveEnemiga[0].coor.y, pila.naveEnemiga[0].coor.x);
		mvprintw(8,6, "naveEnemiga coor y trunc: %.2lf", trunc(pila.naveEnemiga[0].coor.y));
		//mvprintw(6,6, "y: %i, x: %i", naveJugador.coor.y, naveJugador.coor.x);
		//mvprintw(7,6, "y: %i, x: %i", pila.naveEnemiga[0].coor.y, pila.naveEnemiga[0].coor.x);
		refresh ();		// Actualiza la pantalla para ver el caracter.

	}
	while (fin == false);
	curs_set (1);
	endwin ();
	return EXIT_SUCCESS;
}
