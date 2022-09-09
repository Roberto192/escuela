//											clase2_02
//							programa calcule el area de cuadrado	
//					Nombre: Roberto Isaac Arias Guerrero Matricula: 1292118
//										Fecha: 19/08/2022
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	
	unsigned lado, area;

	printf("Ingrese unos de los lados del cuadrado\n");
	scanf("%u",&lado);

	area = lado * lado;

	printf("El area de cuadrado es: %u * %u = %u\n",lado,lado,area);

	return 0;
}