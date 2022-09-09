//	clase1_02
//	Programa que lea 3 numeros y despliega en orden ascendente
//	Nombre:Roberto Isaac Arias Guerrero Matricula:1292118
//	Fecha: 12/08/2022
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){

	int n1, n2, n3, menor, mitad, mayor;
	
	printf("Introduzca su primer numero: ");
	scanf("%i", &n1);
	printf("Introduzca su segundo numero: ");
	scanf("%i", &n2);
	printf("Introduzca su tercer numero: ");
	scanf("%i", &n3);
	
	if (n1 > n2){
		if (n1 > n3){
			mayor = n1;
			if (n3 > n2){
				menor = n2;
				mitad = n3;
			}else{
				menor = n3;
				mitad = n2;
			}
		}else{
			mayor = n3;
			mitad = n1;
			menor = n2;
		}
	}else{
		if (n2 > n3){
			mayor = n2;
			if (n3 > n1){
				menor = n1;
				mitad = n3;
			}else{
				menor = n3;
				mitad = n1;
			}
		}else{
			mayor = n3;
			mitad = n2;
			menor = n1;
		}
	}
	
	printf("%i %i %i", menor, mitad, mayor);
	
	return 0;
}
