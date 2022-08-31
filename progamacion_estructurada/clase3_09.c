//			RIAG_clase3_08
//			8.- Algoritmo que lea 3 números y desplegar en forma ascendente
//			Nombre: Robero=to Isaac Arias Guerrero Matricula: 1292118
//			Fecha: 2022-08-26

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int a, b, c;

	printf("Dame tres numeros\n");
	printf("Numero 1: ");
	scanf(" %i",&a);//1
	printf("Numero 2: ");
	scanf(" %i",&b);//2
	printf("Numero 3: ");
	scanf(" %i",&c);//0

	if(a < b){
		if (a < c)
		{
			if (b < c)
			{
				printf("%i\n%i\n%i\n",a,b,c);
			}else{
				printf("%i\n%i\n%i\n",a,c,b);
			}
		}else
		{
			if(b < c){
				printf("%i\n%i\n%i\n",a,b,c);
			}else{
				printf("%i\n%i\n%i\n",c,a,b);
			}
		}
	}else
	{
		if(a < c){
			if (b < c)
			{
				printf("%i\n%i\n%i\n",b,a,c);
			}else{
				printf("%i\n%i\n%i\n",b,c,a);
			}
		}else{
			if(b < c)
			{
				printf("%i\n%i\n%i\n",b,c,a);
			}else
			{
				printf("%i\n%i\n%i\n",c,b,a);
			}
		}
	}

	return 0;
}