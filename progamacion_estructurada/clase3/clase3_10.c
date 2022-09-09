//			RIAG_clase3_10.c
/*			
			Programa que sirva para calcular el salario semanal de un trabajador donde se obtiene

			como dato de entrada las ​ horas semanales​ trabajadas, el ​ salario por hora​ .

			El programa deberá calcular el ​ salario normal​ , ​ salario extra​ y ​ salario total​ , considerando

			lo siguiente:

			● Jornada Normal de 40 horas.

			● El salario normal se considera las horas trabajadas menores o igual a la jornada

			normal

			● Salario extra se considera las horas trabajadas mayores a la jornada normal y se

			pagan dobles las primeras 9 y triples a partir de la décima hora extra


			Nota:​ Desplegar todos los datos (Salario x hora, Horas Trabajadas, Salario normal, Salario

			extra y Salario Total)
*/
//			Nombre: Robero=to Isaac Arias Guerrero Matricula: 1292118
//			Fecha: 2022-08-26

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	//datos a pedir

	int horasTrabajadas;
	float salarioXhoras;

	//datos a calcular

	int horasNormales = 0, horasExtrasDobles = 0, horasExtrasTriples = 0, horasExtras = 0;
	float salarioTotal = 0, salarioExtra = 0, salarioNormal = 0;

	printf("Programa que dice el salario en base a las horas trabajadas a la semana\n");
	printf("Ingrese las horas trabajadas: ");
	scanf(" %i",&horasTrabajadas);
	printf("Ingrese el salario por hora: ");
	scanf(" %f",&salarioXhoras);

	if(horasTrabajadas <= 40){
		horasNormales = horasTrabajadas;
	}else{
		horasNormales = 40;
		horasExtrasDobles = horasTrabajadas - horasNormales;
		if(horasExtrasDobles > 9){
			horasExtrasTriples = horasExtrasDobles - 9;
			horasExtrasDobles = 9;
			horasExtras = horasExtrasDobles + horasExtrasTriples;
		}
	}
	
	salarioNormal = horasNormales * salarioXhoras;

	if(horasExtrasDobles > 0){
		salarioExtra = horasExtrasDobles * salarioXhoras * 2;
		salarioTotal += salarioExtra;
		if(horasExtrasTriples > 0){
			salarioExtra += horasExtrasTriples * salarioXhoras * 3;
		}
	}

	salarioTotal = salarioNormal + salarioExtra;

	printf("Horas trabajadas: %i\nHoras Normales: %i\nHoras Extras: %i\nSalario Normal: %.2f\nSalario Extra %.2f\nSalario Total: %.2f\n",horasTrabajadas,horasNormales,horasExtras,salarioNormal,salarioExtra,salarioTotal);


	return 0;
}