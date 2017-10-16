#include "funciones.h"

	void
bordesJuego ()
{
	mvaddch(1,0, ACS_ULCORNER);
	mvaddch(1,COLS-1, ACS_URCORNER);
	mvaddch(LINES-1,COLS-1, ACS_LRCORNER);
	mvaddch(LINES-1,0, ACS_LLCORNER);
	for(int i=1; i<COLS-1; i++){
		mvaddch(1,i, ACS_HLINE);
		mvaddch(LINES-1,i, ACS_HLINE);
	}
	for(int i=2; i<LINES-1; i++){
		mvaddch(i,0, ACS_VLINE);
		mvaddch(i,COLS-1, ACS_VLINE);
	}
}

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
crearPoder (struct Pila *pilaPoder)
{
	static time_t ultima_creada = time(0);
	time_t ahora = time(0);

	if(difftime(ahora, ultima_creada) < 10)
		return;
	ultima_creada = ahora;

	if (pilaPoder->cima == MAX)
		return;

	/* Asigna coor aleatorias y el caracter del poder */
	pilaPoder->poder[pilaPoder->cima].coor.x = rand () % (COLS-3)+1;
	pilaPoder->poder[pilaPoder->cima].coor.y = rand () % (LINES-5)+3;
	pilaPoder->poder[pilaPoder->cima].dibujoPoder = 'P';
	pilaPoder->poder[pilaPoder->cima++].id = pilaPoder->cima;

}
	void
crearNave (struct Pila *pila)
{
	static time_t ultima_creada = time(0);
	time_t ahora = time(0);

	if(difftime(ahora, ultima_creada) < CREAR)
		return;
	ultima_creada = ahora;

	if (pila->cima == MAX)
		return;

	/*Asigna coor aleatorias, la funcion para perseguir al jugador y el caracter de la nave enemiga */
	pila->naveEnemiga[pila->cima].coor.x = rand () % (COLS-3)+1;
	pila->naveEnemiga[pila->cima].coor.y = rand () % (LINES-5)+3;
	pila->naveEnemiga[pila->cima].perseguir = &perseguirJugador;
	pila->naveEnemiga[pila->cima].dibujoNave = 'O';
	pila->naveEnemiga[pila->cima++].id = pila->cima;
}

	void
mostrarPila (struct Pila pila, struct Pila pilaPoder)
{
	for (int i = 0; i < pila.cima; i++)
		mvprintw (pila.naveEnemiga[i].coor.y, pila.naveEnemiga[i].coor.x, "%c",
				pila.naveEnemiga[i].dibujoNave);

	for (int i = 0; i < pilaPoder.cima; i++)
		mvprintw (pilaPoder.poder[i].coor.y, pilaPoder.poder[i].coor.x, "%c",
				pilaPoder.poder[i].dibujoPoder);
}

	void
explosion(double x, double y)
{
	static int fila=1, col=fila*2;
	static time_t ultima_creada = time(0);
	time_t ahora = time(0);
	static double diferencia, max = 18;
	static double expansion_fila = 0, expansion_col = 0;

	ultima_creada = ahora;
	diferencia = difftime(ahora, ultima_creada);
	//mvprintw(6,6, "%lf", x); 
	//mvprintw(7,6, "%lf", y); 

	if(fila < max){
		fila++;
		col=fila*2;
		expansion_fila -= 0.5;
		expansion_col --;

		//mvprintw(50, 50, "%i", diferencia);
		//mvprintw(30, 50, "%i", time_t(0));

		for(int i=0; i<fila+1; i++){
			for(int j=0; j<col+1; j++){
				if(i==0 || j==0 || i==fila || j==col)
					mvprintw(i+trunc(y)+expansion_fila, j+trunc(x)+expansion_col, "x"); 

			}
		}
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
	if (letra_movimiento == 'a'){
		if(naveJugador->coor.x == 1) return;
		naveJugador->coor.x--;
	}
	if (letra_movimiento == 'd'){
		if(naveJugador->coor.x == COLS-2) return;
		naveJugador->coor.x++;
	}
	if (letra_movimiento == 'w'){
		if(naveJugador->coor.y == 2) return;
		naveJugador->coor.y--;
	}
	if (letra_movimiento == 's'){
		if(naveJugador->coor.y == LINES-2) return;
		naveJugador->coor.y++;
	}
	if (letra_movimiento == 'p'){
		*fin = true;

	}

}
	void
activarPoder (struct Pila *pilaPoder, struct Nave *naveJugador)
{
	//mvprintw(6,6, "Has entrado a la función activarPoder");
	for(int i=0; i<pilaPoder->cima; i++)
		//if (Math.Truncate(x) == Math.Truncate(y))
		if((trunc(pilaPoder->poder[i].coor.x) == naveJugador->coor.x) && (trunc(pilaPoder->poder[i].coor.y) == naveJugador->coor.y)){
			explosion(pilaPoder->poder[i].coor.x, pilaPoder->poder[i].coor.y);
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
	mvprintw(0,1,"Puntos: %i", *puntos);
	mvprintw(0,13,"Valor COLS: %i LINES: %i", COLS, LINES);
}


