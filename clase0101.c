//	RIAG_ACT1_01
//	Programa que dice cual es el valor del medio
//	Matricula: 1292118 Nombre: Roberto Isaac Arias Guerrero
//	Fecha: 12/08/2022
#include <stdio.h>

int main(int argc, char const *argv[])
{
	
	int a,b,c;
	int my,md,mn;

	printf("\nDame el 1: ");
	scanf("%i",&a);
	printf("\nDame el 2: ");
	scanf("%i",&b);
	printf("\nDame el 3: ");
	scanf("%i",&c);

	if(a > b){
		printf("Hola 1\n");
		if(c > b){
			mn = b;
			if(a > c){
				my = a;
				md = c;
			}else{
				my = c;
				md = a;
			}
		}else{
			mn = c;
			md = b;
			my = a;
		}
	}else if(b > c){
		printf("Hola 2\n");
		my = b;
		if(a > c){
			md = a;
			mn = c;
		}else{
			md = c;
			mn = a;
		}
	}else{
		printf("Hola 3\n");
		my = c;
		md = b;
		mn = a;
	}

	printf("El de medio es: %i \n",md);

	return 0;
}