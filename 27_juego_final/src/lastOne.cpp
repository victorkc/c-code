#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ncurses.h>
#include <math.h>

#define MAX 300
#define MAXX 54
#define MAXY 203
#define VELOCIDAD 0.2 
#define CREAR 1


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
bool
salir_juego(bool *fin2, bool *jugar, bool *again, bool *fin1){
	char tecla;
	tecla = getch();

	if(tecla == 'p'){
		return *jugar = true, *fin2 = true, *again = true, *fin1 = true;
	}
	if(tecla == 10) // '10' significa la tecla enter, no funciona correctamente ni con \r ni \n como comentan
		return *jugar = true;

}

void vaciar_pila(struct Pila *pila){

		for(;pila->cima > 0;pila->cima--){

		pila->naveEnemiga[pila->cima].coor.x = -15;
		pila->naveEnemiga[pila->cima].coor.y = -15;
		pila->naveEnemiga[pila->cima].perseguir = 0;
		}
	return;
	}

bool
jugar_otra_vez(bool *again, bool *fin, bool *fin2, bool *fin1, struct Pila *pila, time_t *tiempo_inicio){
	char letra = getch();

	if(letra == 'y'){
		vaciar_pila(pila);
		*tiempo_inicio = time(0);
		return *again = false, *fin = false, *fin2 = false, *fin1 = true;
	}

	if(letra == 'n')
		return *again = true, *fin1 = true;

}

void cuento_puntos(int *puntos, time_t tiempo_inicio){
	time_t tiempo_pasado = time(0);

	*puntos = difftime(tiempo_pasado, tiempo_inicio);
	tiempo_inicio = time(0);
	mvprintw(1,0,"Puntos: %i", *puntos);
}
	

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
	pila.cima = 0;

	iniciarPantalla (&maxx, &maxy);
	naveJugador.dibujoNave = 'H';
	naveJugador.coor.y = LINES/2;
	naveJugador.coor.x = COLS/2;

	//poder.dibujoPoder = 'X';

	do
	{
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

			cuento_puntos(&puntos, tiempo_inicio);
			crearNave (&pila);
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
			mostrarPila (pila);
			mostrarNave (naveJugador);
			//mvprintw(6,6, "y: %.2lf, x: %.2lf", naveJugador.coor.y, naveJugador.coor.x);
			refresh ();		// Actualiza la pantalla para ver el caracter.

		}
		while (fin == false  && fin2 == false);
		erase();

		do{
				mvprintw(25,70, "Oh... Te han matado, has conseguido %i puntos.", puntos);
				mvprintw(26,70, "Quieres volver a intentarlo? Y=si, N=no");
				jugar_otra_vez(&again, &fin, &fin2, &fin1, &pila, &tiempo_inicio);
				//mvprintw(26,65, "Again: %s", again ? true : false);
				//mvprintw(27,65, "Fin: %s", fin ? true : false);
				refresh();
		}while(fin1 == false);
		fin1 = false; // para que al volver a jugar no casque a la segunda vuelta.
	}
	while(again == false);

	curs_set (1);
	endwin ();
	return EXIT_SUCCESS;
}
