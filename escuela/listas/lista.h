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