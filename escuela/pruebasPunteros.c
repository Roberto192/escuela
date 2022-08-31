#include <stdio.h>
#include <stdlib.h>

#define CANTIDAD 10
#define DIV 4

void dividirArreglo(int *, int, int);

int main(int argc, char const *argv[])
{
	
	int arreglo[CANTIDAD] = {100,200,300,400,500,600,700,800,900,1000};

	for (int i = 0; i < CANTIDAD; i++){
		printf("%i\n",arreglo[i]);
	}

	dividirArreglo(arreglo, CANTIDAD, DIV);
	printf("\n\n\nDivididos entre %i\n\n\n",DIV);

	for (int i = 0; i < CANTIDAD; i++){
		printf("%i\n",arreglo[i]);
	}

	getchar();

	return 0;
}

void dividirArreglo(int arreglo[], int cantidad, int entre){
	for (int i = 0; i < cantidad; ++i)
	{
		arreglo[i] /= entre;
	}
}