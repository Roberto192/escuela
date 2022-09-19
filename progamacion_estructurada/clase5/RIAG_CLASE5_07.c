#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 35

void repetir40numeros();
void repetirNnumeros(int);
void tabla1_20(int);

int main(int argc, char const *argv[])
{
	
	srand(time(NULL));	

	repetir40numeros();
	printf("\n");
	repetirNnumeros(N);
	printf("\n");
	tabla1_20(10);

	printf("\n");
	system("read -p ''");

	return 0;
}

void repetir40numeros(){

	int numero;
	int cantPares = 0;
	int sumaPar = 0;
	int sumaImpar = 0;
	int i;

	for(i = 0; i < 40; i++){
		numero = rand() % 200;

		if (numero % 2 == 0){
			printf("%i: El numero es %i es par\n",i + 1,numero);
			sumaPar += numero;
			cantPares++;
		}else{
			printf("%i: El numero es %i es impar\n",i + 1,numero);
			sumaImpar += numero;
		}
	}

	printf("Numero pares totales: %i\n",cantPares);
	printf("Suma de numeros pares: %i\n",sumaPar);
	printf("Numero impares totales: %i\n",40 - cantPares);
	printf("Suma de numeros impares: %i\n",sumaImpar);

}

void repetirNnumeros(int n){

	int numero;
	int pivot;
	int i;

	pivot = numero = rand() % 200;

	for(i = 0; i < n; i++){
		numero = rand() % 100 + 100;

		if (numero > pivot)
		{
			pivot = numero;
		}

		printf("Numero %i : %i\n",i + 1, numero);
	}

	printf("Numero mayor es: %i\n",pivot);
}

void tabla1_20(int n){
	int i;

	if(n > 0 && n <= 20){
		for(i = 1; i <= n; i++){
			printf("%2i * %2i = %2i\n",n,i,n * i);
		}
	}
}