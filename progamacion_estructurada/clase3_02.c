//		clase3_02
//		lgoritmo que lea un número entero, y desplegar si el número es “PAR” o “IMPAR”
//		Nombre: Robero=to Isaac Arias Guerrero Matricula: 1292118
//		Fecha: 2022-08-26

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int numero;

	printf("Programa para saber si un numero es par o impar\n\n\n");
	printf("Ingrese el numero: ");
	scanf(" %i",&numero);

	if(numero % 2 == 0)
		printf("PAR\n");
	else
		printf("IMPAR\n");


	return 0;
}