//		clase3_03
//		Algoritmo que lea 4 calificaciones de un alumno, calcular y desplegar el promedio acompañado de la leyenda APROBADO o REPROBADO
//		Nombre: Robero=to Isaac Arias Guerrero Matricula: 1292118
//		Fecha: 2022-08-26

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int calificacion1, calificacion2, calificacion3, calificacion4;
	int promedio;

	printf("Programa para saber si estas reprobado o aprobado en base a 4 calificaciones del 0 - 100\n\n\n\n");
	printf("Ingrese la calificacion 1: ");
	scanf(" %i",&calificacion1);
	printf("Ingrese la calificacion 2: ");
	scanf(" %i",&calificacion2);
	printf("Ingrese la calificacion 3: ");
	scanf(" %i",&calificacion3);
	printf("Ingrese la calificacion 4: ");
	scanf(" %i",&calificacion4);

	promedio = (calificacion1 + calificacion2 + calificacion3 + calificacion4)/4;

	if(promedio >= 60)
		printf("%i Aprobado\n", promedio);
	else
		printf("%i Reprobado\n", promedio);
	return 0;
}