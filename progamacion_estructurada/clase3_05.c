// RIAG_clase3_05.c
/*
	5.- Algoritmo que lea 3 calificaciones calcule el promedio del alumno y desplegar: 

	 Si prom < 30 Repetir 

	 Si prom >=30 y prom <60 extraordinario 

	 Si prom >=60 y prom <70 suficiente 

	 Si prom >=70 y prom <80 Regular 

	 Si prom >=80 y prom <90 bien 

	 Si prom >=90 y prom <98 muy bien 

	 Si prom >=98 y prom <=100 excelente 

	 Si prom >100 Error en promedio 
*/
//		Nombre: Robero=to Isaac Arias Guerrero Matricula: 1292118
//		Fecha: 2022-08-26

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int calificacion1, calificacion2, calificacion3;
	int promedio;

	printf("Programa para saber si estas reprobado o aprobado en base a 4 calificaciones del 0 - 100\n\n\n\n");
	printf("Ingrese la calificacion 1: ");
	scanf(" %i",&calificacion1);
	printf("Ingrese la calificacion 2: ");
	scanf(" %i",&calificacion2);
	printf("Ingrese la calificacion 3: ");
	scanf(" %i",&calificacion3);

	promedio = (calificacion1 + calificacion2 + calificacion3 )/3;


	if(promedio < 30){
		printf("REPETIR\n");		
	}else{
		if(promedio < 60)
		{
			printf("EXTRAORDINARIO\n");
		}else{
			if (promedio < 70)
			{
				printf("SUFICIENTE\n");
			}else
			{
				if (promedio < 80)
				{
					printf("REGULAR\n");
				}else
				{
					if (promedio < 90)
					{
						printf("BIEN\n");
					}else
					{
						if (promedio < 98)
						{
							printf("MUY BIEN\n");
						}else
						{
							if (promedio > 100)
							{
								printf("ERROR DE PROMEDIO\n");
							}else
							{
								printf("EXCELENTE\n");
							}
						}
					}
				}
			}
		}
	}

}