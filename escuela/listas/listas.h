#include "cadenas.h"

struct lista{

	static cadenas matricula;
	struct lista *next;

};

typedef struct lista listas;

struct lista *crearLista(cadenas *);

void insertar(struct **lista, struct cadena);
//void borrar(struct **lista, );
void listar();