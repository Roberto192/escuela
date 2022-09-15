#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

void imprimirMatriz(int [SIZE][SIZE]);
void tranversa(int [SIZE][SIZE]);
//carreteras magneticas donde los coches puedan pasar de gasolina a navegar por levitacion
void print(int *);
void tranversanew(int [SIZE][SIZE]);

int main(int argc, char const *argv[])
{
	
	int matriz[SIZE][SIZE] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

	print(&matriz[0][0]);
	tranversanew(matriz);
	printf("\n");
	print(&matriz[0][0]);

	printf("\n");
	system("read -p ''");

	return 0;
}

void print(int *matriz){
	for (int i = 0; i < SIZE*SIZE; i++)
	{
		if (i % 4 == 0){
			printf("\n");
		}
		printf(" %4i ",matriz[i]);
	}
}

void tranversanew(int matrizOriginal[SIZE][SIZE]){

	int buff[SIZE][SIZE];

	for (int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			buff[i][j] = matrizOriginal[j][i];
		}

	}

	for (int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			matrizOriginal[i][j] = buff[i][j];
		}
	}

}

void imprimirMatriz(int matriz[SIZE][SIZE]){

	for (int i = 0; i < SIZE; i++){
		printf("----------------\n");
		for (int j = 0; j < SIZE; j++){
			printf("|%2i|",matriz[i][j]);
		}
		printf("\n----------------\n");
	}

}

void tranversa(int matriz[SIZE][SIZE]){

	int matrizBuff[SIZE][SIZE];

	for (int i = 0; i < SIZE; i++){
		for (int j = 0; j < SIZE; j++){
			matrizBuff[i][j] = matriz[j][i];
		}
	}

}