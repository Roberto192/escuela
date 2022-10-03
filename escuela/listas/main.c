#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termio.h>
#include <sys/ioctl.h>
#include "lista.h"

typedef struct lista listas;
typedef struct cadena cadenas;

#define STDINFD  0

char getch(void);

int main(int argc, char const *argv[])
{
	
	int i;
	cadenas *miCadena = NULL;
	char buff;
	int bandera = 1;

	while(bandera){
		buff = getch();
		if(buff == '\n'){
			bandera = 0;
		}else{
			agregarCadena(&miCadena, buff);
		}
	}	

	imprimirCadena(miCadena);

	return 0;
}

char getch(void) {
  char c;
  struct termio param_ant, params;

  ioctl(STDINFD,TCGETA,&param_ant);

  params = param_ant;
  params.c_lflag &= ~(ICANON|ECHO);
  params.c_cc[4] = 1;

  ioctl(STDINFD,TCSETA,&params);

  fflush(stdin); fflush(stderr); fflush(stdout);
  read(STDINFD,&c,1);

  ioctl(STDINFD,TCSETA,&param_ant);
  return c;
}
