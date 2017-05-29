#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ncurses.h>

#define MAX 100
#define MAXX 54
#define MAXY 203

struct TCoordenadas{
	double x;
	double y;
};

struct TNave{
	struct TCoordenadas coor;
	char dibujoNave;
};

struct TPoder{
	struct TCoordenadas coor;
	char dibujoPoder;
};
int crearNave(struct TNave naveEnemiga[MAX]){ //Asigna coor aleatorias a las naves en x e y.
	for(int i=0; i<MAX; i++){
		naveEnemiga[i].coor.x = 30;//rand() %MAXX;
		naveEnemiga[i].coor.y = 30;//rand() %MAXY;
		//printf("\n coor x: %i, coor y: %i", naveEnemiga[i].coor.x, naveEnemiga[i].coor.y); // Imprime las 100 naves.
	}
}

void iniciarPantalla(int *maxx, int *maxy){			//ncurses

	WINDOW *w;
	w = initscr();				//inicia la pantalla
	curs_set(0); 				//Desactiva cursor
	noecho();					//Sin mostrar el caracter pulsado
	keypad(stdscr,1);			//Teclas especiales
	halfdelay(1);				//Hace que getch no interrumpa la ejecución del programa
	getmaxyx(w, *maxx, *maxy);	//Tamaño de la pantalla

}

void terminarPantalla(){
	curs_set(1);
	clear();
	endwin();
}

void perseguirJugador(struct TNave naveEnemiga[MAX], struct TNave *naveJugador){
	if(naveEnemiga[0].coor.x > naveJugador->coor.x)
		naveEnemiga[0].coor.x-=0.3;
	if(naveEnemiga[0].coor.y > naveJugador->coor.y)
		naveEnemiga[0].coor.y-=0.3;
	if(naveEnemiga[0].coor.x < naveJugador->coor.x)
		naveEnemiga[0].coor.x+=0.3;
	if(naveEnemiga[0].coor.y < naveJugador->coor.y)
		naveEnemiga[0].coor.y+=0.3;

}

void mostrarNave(struct TNave naveJugador){
	mvprintw(naveJugador.coor.y, naveJugador.coor.x, "%c", naveJugador.dibujoNave);
}

void movimiento(struct TNave *naveJugador){
	char letra_movimiento;
	letra_movimiento = getch();
	if(letra_movimiento == 'a')
	naveJugador->coor.x--;	
	if(letra_movimiento == 'd')
	naveJugador->coor.x++;
	if(letra_movimiento == 'w')
	naveJugador->coor.y--;	
	if(letra_movimiento == 's')
	naveJugador->coor.y++;
}

void mostrarEnemigo(struct TNave naveEnemiga[MAX]){
	mvprintw(naveEnemiga[0].coor.y, naveEnemiga[0].coor.x, "%c", naveEnemiga[0].dibujoNave);
}

int main(int argc, char *argv[]){
	int maxy;
	int maxx;
	srand(time(NULL));

	struct TNave naveJugador;
	struct TPoder poder;
	struct TNave naveEnemiga[MAX];	

	naveJugador.dibujoNave = 'H';
	naveEnemiga[0].dibujoNave = 'O';
	naveJugador.coor.y = 25;
	naveJugador.coor.x = 102;

	poder.dibujoPoder = 'X';

	crearNave(naveEnemiga);
	iniciarPantalla(&maxx, &maxy);
	do{
	mostrarEnemigo(naveEnemiga);
	mostrarNave(naveJugador);
	movimiento(&naveJugador);

	perseguirJugador(naveEnemiga, &naveJugador);
	//mvprintw(6,6, "x: %i y: %i", naveEnemiga.coor.x, naveEnemiga.coor.y); //averigua el tamaño de la pantalla.
	clear();
	refresh(); // Actualiza la pantalla para ver el caracter.
	}while(1);

}