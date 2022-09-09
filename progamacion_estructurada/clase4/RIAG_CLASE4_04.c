//		RIAG_CLASE4_04
/*
4.- Programa en C que sirva para calcular el salario semanal de un trabajador donde se obtiene como dato de entrada las horas semanales trabajadas, el salario por hora.

	El programa deberá calcular el salario normal, salario extra y salario total, considerando lo siguiente:

	    Jornada Normal de 40 horas.
	    El salario normal se considera las horas trabajadas menores o igual a la jornada normal
	    Salario extra se considera las horas trabajadas mayores a la jornada normal y se pagan dobles las primeras 9 y triples a partir de la décima hora extra


	Nota: Desplegar todos los datos (Salario x hora, Horas Trabajadas, Salario normal, Salario extra y Salario Total)
*/
//		Nombre: Roberto Isaac Arias Guerrero Matricula: 1292118
//		2022/09/07

#include <stdio.h>
#include <stdlib.h>

#define doblesExtras(horas, salario) horas*salario*2
#define triplesExtras(horas, salario) horas*salario*3
#define NORMAL 40
#define DOBLE 49
#define TRIPLE 50

int main(int argc, char const *argv[])
{
	//Datos a pedir
	int horasTrabajadas;
	float salarioXhora;
	
	//Datos a mostrar
	float salarioNormal = 0, salarioExtra = 0, salarioTotal = 0;
	int horasNormales = 0, horasExtrasDobles = 0, horasExtrasTriples = 0;
	//Inicio de toda logica

	printf("Ingrese las horas trabajadas por semana\n");
	printf(":->");
	scanf(" %i",&horasTrabajadas);
	printf("Ingrese el salario por hora\n");
	printf(":->");
	scanf(" %f",&salarioXhora);

	if(horasTrabajadas >= NORMAL)
	{
		horasExtrasDobles = horasTrabajadas - NORMAL;
		salarioExtra = doblesExtras(horasExtrasDobles, salarioXhora);

		if(horasTrabajadas >= TRIPLE)
		{
			horasExtrasDobles = 9;
			horasExtrasTriples = horasTrabajadas - DOBLE;
			salarioExtra = doblesExtras(horasExtrasDobles, salarioXhora) + triplesExtras(horasExtrasTriples, salarioXhora);
		}
	}

	horasNormales = horasTrabajadas - horasExtrasDobles - horasExtrasTriples;
	salarioNormal = horasNormales * salarioXhora;
	salarioTotal = salarioNormal + salarioExtra;

	//Nota: Desplegar todos los datos (Salario x hora, Horas Trabajadas, Salario normal, Salario extra y Salario Total)
	printf("Salario por hora: %.2f%c",salarioXhora,10);
	printf("horas trabajadas: %i\n",horasTrabajadas);
	printf("Salario normal: %.2f\n",salarioNormal);
	printf("Salario Extra: %.2f\n",salarioExtra);
	printf("Salario total: %.2f\n",salarioTotal);

	//system("pause");//para sistema operativo windows
	system("read -p 'presione cualquier tecla para salir...'");//para sistema operativo linux

	return 0;
}