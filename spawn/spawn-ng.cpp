#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define N 0x100
#define M 0x10
#define PROMPT "MA-TEOS$> "

	void
spawn(char buffer[N])
{
	char *argv[M];
	int i=0;
	pid_t hijo = 0;

	while( argv[i++] = strtok(buffer, " ") ) //argv es = a lo que devuelve strtok, separado por un espacio.
		buffer = NULL;

	strtok(argv[i-2], "\n"); // evita que el \n de problemas en el momento de ejecutar algo sin nombre. es -2 porque la última posicion del array es un NULL y recibe 3 parámetros y
							 // el último es el NULL con el \n.

	hijo = fork(); // se guarda el PID del padre. Significa que al hacer la mitosis, mijo/hijo dentrá NULL y mijo/padre valdrá el PID del hijo.
	if(hijo) // si mijo es NULL, se considera falso. Significa que en la función ha entrado el hijo.
		return;

	//execv("/usr/bin/firefox", buffer);
	//execv(argv[1], argv); // necesita la ruta de donde está firefox. EJEMPLO: /usr/bin/firefox
	execvp(argv[0], argv); //no necesita toda la ruta. Se deben poner dos valores, EJEMPLO: firefox www.google.com
	fprintf(stderr, "No he podido ejecutar: %s\n", argv[0]);
	exit(1);
}

int main(int argc, char *argv[]){

	char *buffer[N];
	system ("clear");

	while(1)
	{
		printf (PROMPT);
		fgets (buffer, N, stdin);
		spawn (buffer);
	}
	printf("\n\n");
	return EXIT_SUCCESS;
}
