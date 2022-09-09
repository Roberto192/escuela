//		RIAG_CLASE4_07
/*
	7- En la materia programación estructurada se aplican 5 exámenes, calcular el promedio final de la materia donde la calificación menor de los exámenes se anula y el promedio se calcula en base a 4 exámenes.

	Desplegar el promedio final.
*/
//		Nombre: Roberto Isaac Arias Guerrero Matricula: 1292118
//		2022/09/07

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	//Datos a pedir
	int calificacion1, calificacion2, calificacion3, calificacion4, calificacion5, sumaCalificaciones, pivote;
	//Datos a procesar
	int promedioFinal;

	printf("Ingrese la primera calificacion\n");
	printf(":->");
	scanf(" %i",&calificacion1);

	printf("Ingrese la segunda calificacion\n");
	printf(":->");
	scanf(" %i",&calificacion2);

	printf("Ingrese la tercera calificacion\n");
	printf(":->");
	scanf(" %i",&calificacion3);

	printf("Ingrese la cuarta calificacion\n");
	printf(":->");
	scanf(" %i",&calificacion4);

	printf("Ingrese la quinta calificacion\n");
	printf(":->");
	scanf(" %i",&calificacion5);

	pivote = calificacion1;
	sumaCalificaciones = calificacion1 + calificacion2 + calificacion3 + calificacion4 + calificacion5;

	if(calificacion2 < pivote){
		pivote = calificacion2;
	}

	if(calificacion3 < pivote){
		pivote = calificacion3;
	}

	if(calificacion4 < pivote){
		pivote = calificacion4;
	}

	if(calificacion5 < pivote){
		pivote = calificacion5;
	}

	promedioFinal = (sumaCalificaciones - pivote) / 4;

	printf("Promedio Final: %i\n",promedioFinal);

	system("read -p ''");

	return 0;
}