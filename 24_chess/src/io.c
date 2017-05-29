#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <error.h>
#include <errno.h>

const char *good_chars = "TCAKQP-";

	void
print_usage (FILE * output)
{
	fprintf (output, USAGE, program_invocation_short_name);
}

	void
error_ocurred ()
{
	print_usage (stderr);
	error (-errno, errno, "%s\n", strerror (errno));
}

	int
repeat (void)
{
	char answer;
	int repeat;
	printf("\n\n Quieres repetir el programa? (s=1/n=0): ");
	scanf(" %i", &repeat);
	return repeat;
	//scanf(" %c %*[^\n]\n", &answer); //Con un conjunto de selección con %*(caracter de supresión de asignación) Lee todo y sólo guarda la primera letra.
	//return(tolower(answer) == 's'? 1: 0);
	/*if(tolower(answer) == 's')
		return 1;
	return 0;*/
}

	char
transform (char c)
{
	c = toupper (c);
	if (!strchr(good_chars, c))
		c = '\0';
	if (c == '-')
		c = ' ';
	return c;
}

void

load (const char *filename, char storage[SIZE][SIZE])
{
	FILE *pf;
	char c;
	int row = 0, col = 0;

	memset(storage, ' ', SIZE*SIZE);

	pf = fopen (filename, "r");
	if (!pf)
		error_ocurred ();

	while (!feof (pf) )
	{
		c = fgetc (pf);
		if (c == '\n'){
			col = 0;
			row++;
		}
		c = transform (c);

		if (c){
			storage[row][col] = c;
		col++;
		 }

	}

	fclose (pf);
}

	void
dump (char board[SIZE][SIZE])
{
	int i;
	int g;

	system("clear");
	for(i=0;i<SIZE;i++){
		for(g=0;g<SIZE;g++)
			printf("%c", board[i][g]);
		printf("\n");
	}
}

	void
ask_coordinates (int *y, int *x, const char *name)
{
	printf("\n Dime las coordernadas donde quieres colocar la torre.");
	printf("\n\n Eje y: ");
	scanf("%i", y);
	printf("\n Eje x: ");
	scanf("%i", x);
}
