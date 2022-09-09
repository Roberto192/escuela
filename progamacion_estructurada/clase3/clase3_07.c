//			RIAG_clase3_07
//			Algoritmo que lea 3 números y desplegar cuál número es el menor y su valor
//			Nombre: Robero=to Isaac Arias Guerrero Matricula: 1292118
//			Fecha: 2022-08-26

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int a, b, c;

	printf("Dame tres numeros\n");
	printf("Numero 1: ");
	scanf(" %i",&a);
	printf("Numero 2: ");
	scanf(" %i",&b);
	printf("Numero 3: ");
	scanf(" %i",&c);

	if(a < b){
		if (a < c)
		{
			printf("El numero 1 es el menor\n");
		}else
		{
			printf("El numero 3 es el menor\n");
		}
	}else
	{
		if(b < c){
			printf("El numero 2 es el menor\n");
		}else{
			printf("El numero 3 es el menor\n");
		}
	}
	return 0;
}