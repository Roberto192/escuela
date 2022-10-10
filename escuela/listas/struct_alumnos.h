
#include <stdlib.h>
#include <string.h>
#include "cadenas.h"

#define MAX_MATRICULA 12

struct alumno{

	char matricula[MAX_MATRICULA];
	struct alumno *next;

};

typedef struct alumno *alumnos;

alumnos crearAlumno(char *);
void agregarAlumno(alumnos *, char *);
void eliminar(alumnos *, char *);
void mostrar(alumnos);

alumnos crearAlumno(char *matricula){
	alumnos aux = (alumnos) malloc(sizeof(alumnos));

	strcpy(aux->matricula, matricula);
	aux->next = NULL;

	return aux;
}

void agregarAlumno(alumnos *alumnos_ref, char *matricula){
	int controlador = 1;
	int contador = 0;
	alumnos aux = NULL;
	alumnos anterior = *alumnos_ref;
	alumnos primerNodo = &(**alumnos_ref);
	
		if(*alumnos_ref != NULL){
			while(controlador == 1){
					if(*alumnos_ref != NULL){
			
					if(atol(matricula) > atol((*alumnos_ref)->matricula)){
						anterior = *alumnos_ref;
						*alumnos_ref = (*alumnos_ref)->next;
					}else{
						controlador = 0;
						if(contador == 0){
							anterior = crearAlumno(matricula);
							anterior->next = primerNodo;
							primerNodo = anterior;
							*alumnos_ref = primerNodo;
						}
					}
				
				}else{
					controlador = 0;
				}
				contador++;					
			}
	
		if(controlador == 0 && contador != 1){
			anterior->next = crearAlumno(matricula);
			anterior->next->next = (*alumnos_ref);
			*alumnos_ref = primerNodo;
		}

	}else{
		*alumnos_ref = crearAlumno(matricula);
	}	
}	



void mostrar(alumnos alumnos_ref){
	int i = 0;
	if(alumnos_ref == NULL){
		printf("Sin alumnos\n");
	}else{
		while(alumnos_ref != NULL){
			printf("[%d] %s\n",i++,alumnos_ref->matricula);
			alumnos_ref = alumnos_ref->next;
		}
	}
}

void eliminar(alumnos *alumnos_ref, char *matricula){
	int controlador = 1;
	alumnos anterior = *alumnos_ref;
	alumnos primerNodo = &(**alumnos_ref);
	
	
	while(controlador){
		if(*alumnos_ref != NULL){
			if(strcmp((*alumnos_ref)->matricula, matricula) == 0){
				anterior->next = (*alumnos_ref)->next;
				free(*alumnos_ref);
				controlador = 0;
			}else{
				anterior = *alumnos_ref;
				*alumnos_ref = (*alumnos_ref)->next;
			}
			
		}else{
			controlador = 0;
		}
	}
	
	*alumnos_ref = primerNodo;
}