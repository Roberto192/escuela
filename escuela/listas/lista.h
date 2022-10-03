#include <stdio.h>
#include <stdlib.h>

struct lista{

	char *num;
	int index;
	struct lista *next;
};

struct cadena{
	char c;
	int index;
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