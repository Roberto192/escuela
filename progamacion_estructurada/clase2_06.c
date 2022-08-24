//                                          clase2_06
//                      programa que calcule el precio de una parcela       
//                  Nombre: Roberto Isaac Arias Guerrero Matricula: 1292118
//                                      Fecha: 19/08/2022

#include <stdio.h>
#include <stdlib.h>

#define PRECIO_PARCELA 35.40

int main(int argc, char const *argv[])
{

	unsigned altura, largo;
	float precioTotal, perimetroAlambre;

	printf("Ingrese la altura de la parcela en metros: ");
	scanf("%u",&altura);
	printf("Ingrese lo largo de la parcela en metros: ");
	scanf("%u",&largo);

	precioTotal = (largo * altura) * PRECIO_PARCELA;
	perimetroAlambre = 2*(largo + altura);

	printf("Precio total por sembrar en %u x %u = %10.2f pesos\n",altura, largo, precioTotal);
	printf("Cantidad total de alambre a usar: %10.2f metros de largo\n\n",perimetroAlambre);

	system("pause>>null");
	return 0;
}