//			RIAG_clase3_08
//			8.- Algoritmo que lea 3 números y desplegar cuál número es del medio y su valor
//			Nombre: Robero=to Isaac Arias Guerrero Matricula: 1292118
//			Fecha: 2022-08-26

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int a, b, c;

	printf("Dame tres numeros\n");
	printf("Numero 1: ");
	scanf(" %i",&a);//3 3
	printf("Numero 2: ");
	scanf(" %i",&b);//2 2
	printf("Numero 3: ");
	scanf(" %i",&c);//1 5

	if(a < b){
		if (a < c)
		{
			if (b < c)
			{
				printf("El numero 2 es el del medio\n");
			}else{
				printf("El numero 3 es el del medio\n");
			}
		}else{
			printf("El numero 1 es el del medio\n");
		}
	}else
	{
		if(a < c){
			printf("El numero 1 es el del medio\n");
		}else
		{
			if(b < c)
			{
				printf("El numero 3 es el del medio\n");
			}else
			{
				printf("El numero 2 es el del medio\n");
			}
		}
	}
	return 0;
}