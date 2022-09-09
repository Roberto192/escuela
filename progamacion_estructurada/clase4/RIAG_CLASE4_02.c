//		clase4_01
/*		2.- Programa en C que use un menú para realizar conversiones de unidades de medida, donde el usuario selecciona una opción y realizará la opción según sea su selección del menú.

		MENÚ

		1.- cm a pulgadas

		2.- cm a pies

		3.- Km a millas

		4.- Pulgadas a cm

		5.- pies a cm

		6.- millas a Km
*/		
//		Nombre: Roberto Isaac Arias Guerrero Matricula: 1292118
//		2022/08/31

#include <stdio.h>
#include <stdlib.h>

#define INCH 2.54
#define FT 30.48
#define ML 1.609

int main(int argc, char const *argv[])
{
	
	int tipoDeOperacion;
	float numero1;

	printf("\n\n\t\tMenu:\n\t\t1.- cm a pulgadas\n\t\t2.- cm a pies\n\t\t3.- Km a millas\n\t\t4.- Pulgadas a cm\n\t\t5.- pies a cm\n\t\t6.- millas a Km\n\n\t\t");
	scanf(" %i",&tipoDeOperacion);

	printf("Ingrese la unidad a convertir: ");
	scanf(" %f",&numero1);

	if(tipoDeOperacion ==  1){
		printf("%.3f / %.3f = %.3f inch", numero1, INCH, numero1 / INCH);
	}else{
		if(tipoDeOperacion == 2){
			printf("%.3f / %.3f = %.3f ft", numero1, FT, numero1 / FT);
		}else{
			if (tipoDeOperacion == 3)
			{	
				printf("%.3f / %.3f = %.3f millas", numero1, ML, numero1 / ML);
			}else{
				if(tipoDeOperacion == 4){
						printf("%.3f / %.3f = %.3f cm", numero1, INCH, numero1 * INCH);
				}else{
					if(tipoDeOperacion == 5){
						printf("%.3f * %.3f = %.3f cm", numero1, FT, numero1 * FT);
					}else{
						if(tipoDeOperacion == 6){
							printf("%.3f / %.3f = %.3f km", numero1, ML, numero1 * ML);
						}
					}
				}
			}
		}
	}

	printf("\n");


	system("read -p ''");

	return 0;
}