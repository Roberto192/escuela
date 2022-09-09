//	RIAG_ACT1_03
//	Programa da factorial del 1 al 10
//	Matricula: 1292118 Nombre: Roberto Isaac Arias Guerrero
//	Fecha: 12/08/2022
#include <stdio.h>

int main(int argc, char const *argv[])
{
	
	int n,f = 1;

	printf("Ingrese un numero del 1 al 10 : ");
	scanf("%i",&n);

	for (int i = n; i > 0 ; i--)
	{
		f *= i;
	}


	printf("Factorial: %i\n",f);

	return 0;
}
