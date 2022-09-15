#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

#define MAX 100
#define MAXCANT 4
#define MAXTOKEN 7

#define TRUE 1
#define FALSE 0


const char *convert(int);
int negacionU(int);
int negacion(int, int);
int conjuncion(int, int);
int disyuncion(int, int);
int condicional(int, int);
int bicondicional(int, int);
//prototipos
TOKENS *getTokens(char *);
int notToken(char);

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


int notToken(char var){
	char tokens[MAXTOKEN] = {'~','^','_','>','<','='};
	for (int i = 0; i < MAXTOKEN; i++){
		if(var == tokens[i]){
			return 1;
		}
	}

	return 0;
}

char **breakup(char *proposicion){
	char *lProposicion = (char *) malloc(sizeof(proposicion)/2);
	char *rProposicion = (char *) malloc(sizeof(proposicion)/2);
	int l;
	int r;
	int sizeText = strlen(proposicion);
	static char *buff[2];

	for (int i = 0; i < sizeText; i++){
		if(proposicion[i] ==  '='){
			l = i - 1;
			r = i + 1;
			for (int j = 0; j <= l; j++){
				lProposicion[j] = proposicion[j];
			}
			printf("\n");
			for (int j = r; j <= sizeText; j++){
				rProposicion[j - r] = proposicion[j];
			}
			buff[0] = lProposicion;
			buff[1] = rProposicion;
			return buff;
		}
	}

	return NULL;
}

TOKENS *getTokens(char *proposicion){
	char tokens[MAXTOKEN] = {'~','^','_','>','<','='};
	static TOKENS buff[MAXTOKEN];
	int pos = 0;
	int par;

	for(int i = 0; i < strlen(proposicion); i++){
		for (int j = 0; j < MAXTOKEN; j++){
			if(proposicion[i] == tokens[j]){
				buff[pos].type = tokens[j];
				buff[pos].pos = i;
				buff[pos].L = i - 1;
				buff[pos].R = i + 1;
				buff[pos].Lchar = proposicion[buff[pos].L];
				buff[pos].Rchar = proposicion[buff[pos].R];
				buff[pos].priority = 1;
				pos++;
			}
		}
	}

	for (int i = 0; i < pos; ++i)
	{
		buff[i].size = pos;
	}

	return buff;
}

int resolve(char *proposicion, int len){

	TOKENS *tok;
	int value = 0;

	tok = getTokens(proposicion);

	for (int i = 0; i < tok[0].size; i++){
		printf("%i: %i %c %i %i %i\n",i,tok[i].L,tok[i].type,tok[i].R,tok[i].pos,tok[i].priority);
	}

	return value;
}