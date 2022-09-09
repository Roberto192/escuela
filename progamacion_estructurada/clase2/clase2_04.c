//											clase2_02
//						programa que calcule el area de trapecio		
//					Nombre: Roberto Isaac Arias Guerrero Matricula: 1292118
//										Fecha: 19/08/2022

#include <stdio.h>

int main(int argc, char const *argv[])
{
	
	int altura, baseMenor, baseMayor;
	float area;

	printf("Ingrese la altura del trapecio: ");
	scanf("%u",&altura);
	printf("Ingrese la base menor: ");
	scanf("%u",&baseMenor);
	printf("Ingrese la base mayor: ");
	scanf("%u",&baseMayor);

	area = (float)  (baseMayor + baseMenor)*altura/2;

	printf("El area del trapecio es: \n\n(%u + %u)%u\n---------- = %.2f \n    2\n\n",baseMayor, baseMenor, altura, area);

	return 0;
}