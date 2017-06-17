#ifndef __FUNCIONES_H__
#define __FUNCIONES_H__

#ifdef __cplusplus
extern "C" {
#endif

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
perseguirJugador (struct Nave *naveEnemiga, struct Nave naveJugador);

	void
iniciarPantalla (int *maxx, int *maxy);

	void
crearNave (struct Pila *pila);
	
	void
mostrarPila (struct Pila pila);

	void
mostrarNave (struct Nave naveJugador);

	void
movimiento (struct Nave *naveJugador, bool *fin);

	bool
muerteJugador (struct Pila *pila, struct Nave *naveJugador);

	bool
salir_juego(bool *fin2, bool *jugar, bool *again, bool *fin1);
	
	void 
vaciar_pila(struct Pila *pila);

	bool
jugar_otra_vez(bool *again, bool *fin, bool *fin2, bool *fin1, struct Pila *pila, time_t *tiempo_inicio, struct Nave *naveJugador);
	
	void 
cuento_puntos(int *puntos, time_t tiempo_inicio);


#ifdef __cplusplus
}
#endif

#endif
