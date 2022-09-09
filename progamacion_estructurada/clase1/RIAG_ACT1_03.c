//	clase1_03
//	Programa que muestra el factorial de un número entre el 1 y el 10
//	Nombre:Roberto Isaac Arias Guerrero Matricula:1292118
//	Fecha: 12/08/2022
#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, f=1;
	printf("Numero entre el 1 al 10: ");
	scanf("%i", &n);
	if (n > 0 && n < 11){
		while (n > 0){
			f *= n;
			--n;
		}
	}else{
		printf("El numero no esta entre el 1 y el 10");
		return 0;
	}
	printf("factorial: %i", f);
	return 0;
}
