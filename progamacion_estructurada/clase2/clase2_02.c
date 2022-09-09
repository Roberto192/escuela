//											clase2_02
//					programa que ingreses precion y te calcule el iva (%16) y su precio final		
//					Nombre: Roberto Isaac Arias Guerrero Matricula: 1292118
//										Fecha: 19/08/2022
//https://github.com/ErickBuster/Wi-Fi-Attack.git
#include <stdio.h>

#define IVA 0.16

int main(int argc, char const *argv[])
{
	
	float precio, precioTotal, ivaTotal;

	printf("Ingrese el precio del producto\n");
	scanf("%f",&precio);

	ivaTotal = precio * IVA;
	precioTotal = precio + ivaTotal;

	printf("Subtotal: %.2f\n", precio);
	printf("IVA: %.2f\n",IVA);
	printf("Precio total: %.2f\n",precioTotal);
	printf("IVA total %.2f\n",ivaTotal);


	return 0;
}