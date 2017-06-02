#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ncurses.h>

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
	void (*perseguir)(struct Nave *, struct Nave) ;
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
	keypad (stdscr, 1);		//eclas especiales
	halfdelay (1);		//Hace que getch no interrumpa la ejecución del programa
	*maxx = COLS;
	*maxy = LINES;

}

	void
terminarPantalla (bool *fin)
{
	curs_set (1);
	clear ();
	*fin = true;
}

	void
crearNave (struct Pila *pila)
{	  
	static int creadas = 0;
	static clock_t ultima_creada = clock();
	clock_t ahora = clock();

	if((ahora-ultima_creada)/1000 < CREAR)
		return;
	ultima_creada = ahora;

	if(pila->cima == MAX)
		return;

	/*Asigna coor aleatorias, la funcion para perseguir al jugador y el caracter de la nave enemiga*/
	pila->naveEnemiga[pila->cima].coor.x = rand () % COLS;
	pila->naveEnemiga[pila->cima].coor.y = rand () % LINES;
	pila->naveEnemiga[pila->cima].perseguir = &perseguirJugador;
	pila->naveEnemiga[pila->cima++].dibujoNave = 'O';
	creadas++;
}
	void
mostrarPila (struct Pila pila)
{
	for(int i=0; i<pila.cima; i++){
		mvprintw (pila.naveEnemiga[i].coor.y, pila.naveEnemiga[i].coor.x, "%c", pila.naveEnemiga[i].dibujoNave);
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
	if (letra_movimiento == 'p')
		terminarPantalla(fin);
}

	void
muerteJugador(struct Pila *pila, struct Nave *naveJugador, bool *fin)
{
	//for(int i=0; i<pila->cima; i++)
		/*if((pila.naveEnemiga[i].coor.x == naveJugador.coor.x)&&*pila.naveEnemiga[i].coor.y == naveJugador.coor.y){*/
			//terminarPantalla(fin);
			//mvprintw(6,6, "y: %i, x: %i", naveJugador->coor.y, naveJugador->coor.x);
		//}
	
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

	mvprintw(6,6, "y: %i, x: %i", naveJugador.coor.y, naveJugador.coor.x);
	//poder.dibujoPoder = 'X';

	do
	{
		crearNave (&pila);
		mostrarPila (pila);
		mostrarNave (naveJugador);
		movimiento (&naveJugador, &fin);
		//muerteJugador(&pila, &naveJugador, &fin);
	//mvprintw(6,6, "y: %i, x: %i", naveJugador.coor.y, naveJugador.coor.x);

		for(int i=0; i<pila.cima; i++)
			(pila.naveEnemiga[i].perseguir)(&pila.naveEnemiga[i], naveJugador);
		clear ();
		refresh ();		// Actualiza la pantalla para ver el caracter.
	}
	while (fin==false);
	endwin ();

}
