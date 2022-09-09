//	clase1_01
//	Programa que lea 3 numeros y despliegue el del medio
//	Nombre:Roberto Isaac Arias Guerrero Matricula:1292118
//	Fecha: 12/08/2022
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
	
	int n1, n2, n3, med;
	
	printf("Introduzca su primer numero: ");
	scanf("%i", &n1);
	printf("Introduzca su segundo numero: ");
	scanf("%i", &n2);
	printf("Introduzca su tercer numero: ");
	scanf("%i", &n3);
	
	if (n1 > n2){
		if (n1 > n3){
			if (n3 > n2){
				med = n3;
			}else{
				med = n2;
			}
		}else{
			med = n1;
		}
	}else{
		if (n2 > n3){
			if (n3 > n1){
				med = n3;
			}else{
				med = n1;
			}
		}else{
			med = n2;
		}
	}
	
	printf("valor medio: %i", med);
	
	return 0;
}
