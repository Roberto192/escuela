#include <stdio.h>

int valorMayor(int numeros[]){
	if(numeros[0] > numeros[1] && numeros[0] > numeros[2]){

		return numeros[0];

	}

	if(numeros[1] > numeros[0] && numeros[1] > numeros[2]){

		return numeros[1];

	}

	if(numeros[2] > numeros[0] && numeros[2] > numeros[1]){

		return numeros[2];

	}

	return 0;
}

int valorMenor(int numeros[]){
	if(numeros[0] < numeros[1] && numeros[0] < numeros[2]){

		return numeros[0];

	}

	if(numeros[1] < numeros[0] && numeros[1] < numeros[2]){

		return numeros[1];

	}

	if(numeros[2] < numeros[0] && numeros[2] < numeros[1]){

		return numeros[2];

	}

	return 0;
}

void primerPrograma(){

	int i,numeros[3];

	for (i = 0; i < 3; i++){

		printf("Dame un numero entero ");
		scanf("%d",&numeros[i]);
	
	}

	printf("El numero mayor es, %d",valorMayor(numeros));

	printf("\n");
}

void segundoPrograma(){

	int i,numeros[3];

	for (i = 0; i < 3; i++){

		printf("Dame un numero entero ");
		scanf("%d",&numeros[i]);
	
	}

	int nMayor = valorMayor(numeros);
	int nMenor = valorMenor(numeros);

	for(i = 0; i < 3; i++){
		if(numeros[i] != nMayor && numeros[i] != nMenor){
			printf("El numero de valor medio es, %d",numeros[i]);
		}
	}

	printf("\n");
}

int main(int argc, char const *argv[])
{

	int numeros[3], buff, i, j;
	int suma = 0;
	int anterior = 0;
	int actual = 1;

	for (int i = 0; i < 3; i++)
	{
		printf("Ingrese un valor ");
		scanf("%d",&numeros[i]);
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 2; j++)
		{
			if(numeros[j] < numeros[j + 1]){
				buff = numeros[j + 1];
				numeros[j + 1] = numeros[j];
				numeros[j] = buff;
			}
		}
	}


	printf("El numero mayor es, %d \n",numeros[0]);
	printf("El numero de valor medio es, %d \n",numeros[1]);

	for (int i = 0; i < 4; i++)
	{
		printf("%d\n",i+1);
	}

	for (int i = 0; i < 100; i++){

		anterior = actual;
		actual = suma;
		suma = anterior + actual;

		printf("%d ",actual);

	}

	printf("\n");

	return 0;
}

