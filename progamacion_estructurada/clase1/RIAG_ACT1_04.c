//	clase1_04
//	Programa que lea 3 numeros y muestra la tabla de multiplicar
//	Nombre:Roberto Isaac Arias Guerrero Matricula:1292118
//	Fecha: 12/08/2022
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){

	int n, i=1;

	printf("Numero entre el 1 al 10: ");
	scanf("%i", &n);
	
	if (n > 1 && n < 11){
		while (i < 11){
			printf("%ix%i=%i\n", n,i,n*i);
			++i;
		}
	}else{
		printf("El numero no esta entre el 1 y el 10");
		return 0;
	}
	
	return 0;
}
