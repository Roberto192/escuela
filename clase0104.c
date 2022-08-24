//	RIAG_ACT1_04
//	Programa de tabla de multiplicar
//	Matricula: 1292118 Nombre: Roberto Isaac Arias Guerrero
//	Fecha: 12/08/2022
#include <stdio.h>

int main(int argc, char const *argv[])
{

	int n;

	printf("\t\tDame un numero del 1 al 10 para\n\t\tdar la tabla de multiplicar\n\n\t\t");
	scanf("%i",&n);
	if(n > 0 && n <= 10){
		printf("\n");

		for (int i = 1; i <= 10; i++)
		{
			printf("\t\t%i * %i = %i\n",n,i,n * i);
		}
	}else{
		printf("\t\tOtro numero\n");
	}

	return 0;
}