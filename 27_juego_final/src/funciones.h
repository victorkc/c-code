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

#define MAX 500
#define MAXX 54
#define MAXY 203
#define VELOCIDAD 0.1 
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
	int id;
};

struct Poder
{
  struct Coordenadas coor;
  char dibujoPoder;
  int id;
};

struct Pila
{
	struct Nave naveEnemiga[MAX];
	struct Poder poder[MAX];
	int cima;
};


void bordesJuego ();
void perseguirJugador (struct Nave *naveEnemiga, struct Nave naveJugador);
void iniciarPantalla (int *maxx, int *maxy);
void explosion(int x, int y);
void crearNave (struct Pila *pila);
void crearPoder(struct Pila *pila);
void mostrarPila (struct Pila pila, struct Pila pilaPoder);
void mostrarNave (struct Nave naveJugador);
void movimiento (struct Nave *naveJugador, bool *fin);
void vaciar_pila(struct Pila *pila);
void activarPoder(struct Pila *pilaPoder, struct Nave *naveJugador);

bool muerteJugador (struct Pila *pila, struct Nave *naveJugador);
bool salir_juego(bool *fin2, bool *jugar, bool *again, bool *fin1);
bool jugar_otra_vez(bool *again, bool *fin, bool *fin2, bool *fin1, struct Pila *pila, time_t *tiempo_inicio, struct Nave *naveJugador);
void cuento_puntos(int *puntos, time_t tiempo_inicio);

#ifdef __cplusplus
}
#endif

#endif
