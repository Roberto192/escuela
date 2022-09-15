#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define JUMPLINE printf("\n")

#define MAX 100
#define MAXCANT 4
#define MAXTOKEN 6

#define TRUE 1
#define FALSE 0

typedef int bool;


const char *convert(int);
int negacionU(int);
int negacion(int, int);
int conjuncion(int, int);
int disyuncion(int, int);
int condicional(int, int);
int bicondicional(int, int);

const char *convert(int valor){
	return (valor)? "VERDADERO" : "FALSO    ";
}

int negacionU(int v1){
	if (v1)  return FALSE;
	return TRUE;
}

int negacion(int v1, int v2){
	if (v1 == TRUE && v2 == TRUE){
		return FALSE;
	}

	if (v1 == FALSE && v2 == TRUE){
		return FALSE;
	}

	return TRUE;
}

int conjuncion(int v1, int v2){
	if(v1 == TRUE && v2 == TRUE){
		return TRUE;
	}

	return FALSE;
}

int disyuncion(int v1, int v2){

	if(v1 == FALSE && v2 == FALSE){
		return FALSE;
	}

	return TRUE;
}

int condicional(int v1, int v2){
	if(v1 == TRUE && v2 == FALSE){
		return FALSE;
	}

	return TRUE;
}

int bicondicional(int v1, int v2){
	if(v1 == v2){
		return TRUE;
	}

	return FALSE;
}

int solve(char *proposicion){
	int value
	int buffer;

	int len = strlen(proposicion)

	for (int i = 0; i < len; i++){
		switch(proposicion[i]){
			case '~':
				value = (proposicion[i + 1] == 'p')? TRUE: FALSE;
				value = negacionU(value);
			break;

			case '^':
				value = conjuncion((proposicion[i - 1] == 'p' )? TRUE : FALSE, (proposicion[i + 1] == 'q' )? TRUE : FALSE);
			break;

			case '_':
				value = disyuncion((proposicion[i - 1] == 'p' )? TRUE : FALSE, (proposicion[i + 1] == 'q' )? TRUE : FALSE);
			break;

			case '>':
				value = condicional((proposicion[i - 1] == 'p' )? TRUE : FALSE, (proposicion[i + 1] == 'q' )? TRUE : FALSE);
			break;

			case '=':
				value = bicondicional((proposicion[i - 1] == 'p' )? TRUE : FALSE, (proposicion[i + 1] == 'q' )? TRUE : FALSE);
			break;
		}

	}

	return value;
}