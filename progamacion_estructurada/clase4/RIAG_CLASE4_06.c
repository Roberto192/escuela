//		RIAG_CLASE4_06
/*
	6.- Programa en C que sirva para calcular el Total a pagar por consumo de agua, donde el dato de entrada son los M3 de agua consumidos, Tomar en cuenta que se cobra escalonada de la Siguiente manera:


	Rango1: 0 al 4 M3 $50 x facturación sin importar cuánto consumió en este rango

	Rango2: 5 a 15 M3 $8.00 x M3

	Rango3: 16 a 50 M3 $10.00 x M3

	Rango4: 51 M3 en adelante $11.00 x M3


	Nota: Desplegar SubTotal, Iva(16%), y Total a pagar.
*/
//		Nombre: Roberto Isaac Arias Guerrero Matricula: 1292118
//		2022/09/07
#include <stdio.h>
#include <stdlib.h>

#define rango1 50.00
#define rango2 8.00
#define rango3 10.00
#define rango4 11.00

#define IVA 0.16

int main(int argc, char const *argv[])
{
	//Datos a pedir
	int m3;
	//Datos a procesar
	float subtotal, impuesto, total;

	printf("Aguas consumida en metros cubicos\n");
	printf(":->");
	scanf(" %i",&m3);

	if(m3 >= 5){
		if(m3 > 15){
			if(m3 > 50){
				subtotal = rango1 + (rango2 * 10) + (rango3 * 34) + (rango4 * (m3 - 50));
			}else{
				subtotal = rango1 + (rango2 * 10) + (rango3 * (m3 - 15));
			}
		}else{
			subtotal = rango1 + (rango2 * (m3 - 4));
		}
	}else{
		subtotal = rango1;
	}

	impuesto = IVA * subtotal;
	total = impuesto + subtotal;

	//Nota: Desplegar SubTotal, Iva(16%), y Total a pagar.
	printf("Subtotal:\t%5.2f\n",subtotal);
	printf("Iva:     \t%5.2f\n",impuesto);
	printf("Total:   \t%5.2f\n",total);

	system("read -p ''");

	return 0;
}