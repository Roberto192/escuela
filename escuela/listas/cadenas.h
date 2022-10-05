#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#ifdef __unix__

#include <termio.h>
#include <sys/ioctl.h>
#define STDINFD  0

char leerCaracter(int);

char leerCaracter(int echo) {
  char c;
  struct termio param_ant, params;

  ioctl(STDINFD,TCGETA,&param_ant);

  params = param_ant;
  if(echo){
  	params.c_lflag &= (ICANON|ECHO);
  }else{ 
  	params.c_lflag &= ~(ICANON|ECHO);
  }
  params.c_cc[4] = 1;

  ioctl(STDINFD,TCSETA,&params);

  fflush(stdin); fflush(stderr); fflush(stdout);
  read(STDINFD,&c,1);

  ioctl(STDINFD,TCSETA,&param_ant);
  return c;
}

#endif

#ifdef __WIN32

char leerCaracter(int);

char leerCaracter(int echo){
	return getwchar();
}

#endif

typedef struct lista listas;
typedef struct cadena cadenas;

struct cadena{
	char c;
	struct cadena *next;
};

struct cadena *crearCadena(char);
int agregarCadena(struct cadena **, char);
int imprimirCadena(struct cadena *);

struct cadena *crearCadena(char c){

	struct cadena *cad = (struct cadena *) malloc(sizeof(struct cadena *));

	if(cad == NULL){
		return NULL;
	}

	cad->c = c;
	cad->next = NULL;

	return cad;
}

int agregarCadena(struct cadena **cad, char c){

	struct cadena *aux = NULL;

	if(*cad == NULL){

		aux = crearCadena(c);
		*cad = aux;

		return 0;
	}else{
		agregarCadena(&(*cad)->next, c);
		return 1;
	}
	
	return -1;
}

int imprimirCadena(struct cadena *cad){
	
	if(cad == NULL){
		return -1;
	}

	putc(cad->c, stdout);
	imprimirCadena(cad->next);

	return 1;
}

int obtenerLongitud(struct cadena *cad){
	int i = 0;
	int bandera = 1;
	struct cadena **aux;

	aux = &cad;

	if(*aux == NULL){
		return 0;
	}

	while(bandera){
		if(cad->next == NULL){
			bandera = 0;
		}else{
			cad = cad->next;
		}
		i++;
	}
	/*aplicacion que te avisa cuando pasa la basura*/
	cad = *aux;
	return i;
}

char *obtenerCadena(struct cadena *cad){
	int lon = obtenerLongitud(cad);
	char *aux;
	int i = 0;

	if(lon == 0){
		return NULL;
	}

	aux = (char *) malloc(lon + 1);

	while(i < lon){
		aux[i++] = cad->c;
		cad = cad->next;
	}

	aux[i] = '\0';
	return aux;
}