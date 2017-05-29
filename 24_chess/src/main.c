#include <stdio.h>
#include <stdlib.h>

#include "general.h"
#include "io.h"


int is_empty (int row, int col, char board[SIZE][SIZE]);
int tower_check (int row, int col, char board[SIZE][SIZE]);

	int
main (int argc, char *argv[])
{
	char chess_board[SIZE][SIZE];
	int row, col;

	do
	{
		load (BOARD_FN, chess_board);
		dump (chess_board);
		do
		{
			ask_coordinates (&row, &col, "torre");
		}
		while (!is_empty (row, col, chess_board));
		tower_check (row, col, chess_board);
	}
	while (repeat ());


	return EXIT_SUCCESS;
}

	int
is_empty (int row, int col, char board[SIZE][SIZE])
{
	if(board[row][col] != ' '){
		printf("\n Ese espacio ya está en uso, dime unas coordenadas distintas.\n");
		return 0;
	}
	else
		printf("\n Has colocado la torre en las coordenadas y:%i, x:%i.\n", row, col);
	return 1;
}



//Función propia para verificar el tower_check.
int checkeo(int row, int col)
{
	printf("\n row:%i, col:%i", row, col);
}

void igualar(int first_row, int first_col, int *row, int *col){

	*row = first_row;
	*col = first_col;

}

	int
tower_check (int row, int col, char board[SIZE][SIZE])
{
	int not_found = 1;
	int first_row = row;
	int first_col = col;

	while(not_found != 0){
		row--;
		if(row < 0){
			not_found = 0;
			break;
		}
		if(board[row][col] != ' '){
			printf("\n Arriba Puedes comerte la ficha %c.", board[row][col]);
			not_found = 0;
		}
	}
	not_found = 1;
	igualar(first_row, first_col, &row, &col);
	while(not_found != 0){
		row++;
		if(row > 7){
			not_found = 0;
			break;
		}
		if(board[row][col] != ' '){
			printf("\n Abajo Puedes comerte la ficha %c.", board[row][col]);
			not_found = 0;
		}
	}
	igualar(first_row, first_col, &row, &col);
	not_found = 1;
	while(not_found != 0){
		col--;
		if(col < 0){
			not_found = 0;
			break;
		}
		if(board[row][col] != ' '){
			printf("\n A la izqierda puedes comerte la ficha %c.", board[row][col]);
			not_found = 0;
		}
	}
	igualar(first_row, first_col, &row, &col);
	not_found = 1;
	while(not_found != 0){
		col++;
		if(col > 7){
			not_found = 0;
			break;
		}
		if(board[row][col] != ' '){
			printf("\n A la derecha puedes comerte la ficha %c.", board[row][col]);
			not_found = 0;
		}
	}
}
