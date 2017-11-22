#include <stdio.h>
#include <stdlib.h>

#define N 0x100
#define USAGE "%s -v1.0\n"				\
	"\t Sends an email to a file.\n\n"  \
	"\t USAGE: \n"						\
	"\t %s -d<domain> [-p<port|port_name>=smtpp] <email_file> \n"\
	"\n"\
	"\t EXAMPLE: \n"\
	"\t %s -d sharklasers.com -p"

const char *program_name;

	void
print_usage(FILE *out, int status)
{
	fprintf(out, USAGE, program_name);
	exit (status);
}

int main(int argc, char *argv[]){


	//char mailmando[N] = "cat <algo> | telnet sharklasers.com smtp";
	const char *servidor[N] = NULL; // Queda apuntando a una direccion de la línea de comandos.
	char mailmando[N] = "cat %s | telnet %s %s";
	int sig_opcion;
	int verbose = 0;
	char puerto[N] = "smtp";

	const char *op_cortas = "hd:p:v";
	struct options op_largas[] = {
		{"help", 0, NULL, 'h'},
		{"domain", 1, NULL, 'd'},
		{"port", 1, NULL, 'p'},
		{"verbose",0, NULL, 'v'},
		{NULL, 0, NULL, '\0'}
	};

	program_name = argv[0];

	do{
		sig_opcion = getopt_long(op_cortas, op_largas, argc, argv, NULL);

		switch(sig_opcion){
			case 'h':
				print_usage(stdout, EXIT_SUCCESS);
				break;
			case 'v':
				break;
			case 'd':
				servidor = optarg;
				break;
			case 'p':
				strcpy(puerto, optarg, N);
				break;
			case 'INVALOPC':
				print_usage(stderr, EXIT_FAILURE)
				break;
			case NOMASOPC:
				break;
			default:
				abort();
		}
	}while(sig_opcion)

	if(servidor" == NULL){
		
	}

	sprintf(mailmando/*1*/, mailmando/*2*/, "email.addr", "sharklasers.com", "sntp");
	// el mailmando 2 mete todo el texto, y el 1 mailmando hace que en vez que ponerlo en pantalla
	// lo guarda en mailmando.

	system (mailmando);


	printf("\n\n");
	return EXIT_SUCCESS;
}
