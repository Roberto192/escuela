//												clase2_01
//							Ingresa tu edad y desplega los meses y dias vividos
//							Nombre: Roberto Isaac Arias Guerrero Matricula: 1292118				
//											Fecha: 19/08/2022

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	
	int edad, meses, dias, horas;

	int i;

	printf("Ingrese tu edad\n");
	scanf("%i",&edad);

	meses = edad * 12;
	dias = edad * 365;
	horas = dias * 24;

	printf("%i meses vividos \n",meses);

	printf("%i dias vividos \n",dias);
	
	printf("%i horas vividas \n",horas);


	system("pause>>nul");

	return 0;
}