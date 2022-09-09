//		clase4_01
/*		1.- Programa en C que use un menú para realizar las 4 operaciones básicas, donde el usuario introduce 2 números enteros y realizará la operación según sea su selección del menú.

		MENÚ

		1.- Suma

		2.- Resta

		3.- Multiplicación

		4.-División
*/		
//		Nombre: Roberto Isaac Arias Guerrero Matricula: 1292118
//		2022/08/31

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	
	int tipoDeOperacion;
	int numero1, numero2;

	printf("\n\n\t\tMenu:\n\t\t1. Suma\n\t\t2. Resta\n\t\t3. Multiplicacion\n\t\t4. Division\n\n\t\t");
	scanf(" %i",&tipoDeOperacion);

	printf("Ingrese el primer numero: ");
	scanf(" %i",&numero1);
	printf("Ingrese el segundo numero: ");
	scanf(" %i",&numero2);

	if(tipoDeOperacion ==  1){
		printf("%i + %i = %i", numero1, numero2, numero1 + numero2);
	}else{
		if(tipoDeOperacion == 2){
			printf("%i - %i = %i", numero1, numero2, numero1 - numero2);
		}else{
			if (tipoDeOperacion == 3)
			{	
				printf("%i * %i = %i", numero1, numero2, numero1 * numero2);
			}else{
				if(tipoDeOperacion == 4){
					printf("%i / %i = %.9f", numero1, numero2,(float) numero1 / numero2);
				}
			}
		}
	}

	printf("\n");

	system("read -p ''");

	return 0;
}