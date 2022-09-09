//		clase3_04
//		Algoritmo que a través de opciones (1.- HOMBRE 2.- MUJER ) preguntar al usuario cual es su SEXO y desplegar la leyenda “HOLA, ERES HOMBRE ”, “ HOLA, ERES MUJER”
//		Nombre: Robero=to Isaac Arias Guerrero Matricula: 1292118
//		Fecha: 2022-08-26

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int sexo;

	printf("Cual es tu sexo? (1.- HOMBRE 2.- MUJER )\n");
	scanf(" %i",&sexo);

	if(sexo == 1)
		printf("HOLA, ERES HOMBRE\n");
		if (sexo == 2)
			printf("HOLA, ERES MUJER\n");


}