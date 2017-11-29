#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>

#define MAX 0x100

/* get ppid - para conseguir pid del proceso padre 70
 * página 42
 * página 60
 * página 70
 * página 73
 * página 75
 * página 78
 * página 80
 * */

/* SIGNAL */
sig_atomic_t sigusr1_count = 0;

void handler(int signal_number)
{
	++sigusr1_count;
}


int main(int argc, char *argv[]){

	system ("clear");

	int child_status;
	struct sigaction sa;
	
	char* arg_list[] = {
	"ls", //nombre del programa.
	"-l",
	NULL};

	memset (&sa, 0, sizeof(sa));
	sa.sa_handler = &handler;
	sigaction(SIGUSR1, &sa, NULL);

	pid_t child_pid;
	//char argumento[MAX] = {argv[1]};

	printf("El nombre del programa: %s.\n", argv[0]);
	printf("El segundo argumento del programa: %s.\n\n", argv[1]);

	//printf("El ID del proceso es: %d\n", (int) getpid ());
	//printf("El PID proceso padre es: %d\n", (int) getppid ());

	printf("SIGURS1 fue usado %d veces\n", sigusr1_count);

	/* FORK */
	child_pid = fork();
	if(child_pid !=0)
	{
		printf("El PID de proceso PADRE: %d\n", (int) getpid ());
		printf("El ID proceso HIJO es: %d\n", (int) child_pid);
		kill(child_pid, SIGTERM); //Mata al hijo y no aparece por ello el printf de else.
	}
	else
		printf("Este el el proceso HIJO, con id %d\n", (int) getpid());
	
	spawn("ls", arg_list); //falta por declarar
	wait(&child_status);   //faltapor declarar
	if(WIFEXITED (child_status))
	printf("El proceso hijo acabó con normalidad, con código de salida %d\n", WEXITSTATUS(child_status));
	else
		printf("El proceso hijo tuvo un problema al salir.");

	printf("\n\n");
	return EXIT_SUCCESS;
}
