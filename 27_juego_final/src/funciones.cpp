#include "funciones.h"
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
jugar_otra_vez(bool *again, bool *fin, bool *fin2, bool *fin1, struct Pila *pila, time_t *tiempo_inicio, struct Nave *naveJugador){
	char letra = getch();

	if(letra == 'y'){
		naveJugador->coor.x = COLS/2;
		naveJugador->coor.y = LINES/2;

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


