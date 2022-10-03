#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __unix__
	#define CLEAR system("clear");
#endif

#ifdef __WIN32
	#define CLEAR system("cls");
#endif

#define TRUE 1
#define FALSE 2

#define MAX_UNIDADES 5

typedef int bool;

int tieneDerecho(int);
int calificaciones(int);
void alumnos();
void tablasDeMultiplicar();
void numeroXrango();
void embarcacion();
void repetirMateria();

int main(int argc, char const *argv[])
{
	char actividad[5];
	int opcion;
	int salir = 0;

	do
	{
		printf("1.- Actividad 1\n");
		printf("2.- Actividad 2\n");
		printf("3.- Actividad 3\n");
		printf("4.- Actividad 4\n");
		printf("5.- Actividad 5\n");
		printf("6.- Salir\n");
		printf("\n\n");
		printf("->");
		fgets(actividad, 5, stdin);
		if(strcmp(actividad, "\n") != 0){
			opcion = atoi(actividad);

			if(opcion == 6){
				salir = 1;
			}else{

				CLEAR;
				if(opcion == 1){
					alumnos();
					fgets(actividad, 5, stdin);
				}else{
					if(opcion == 2){
						tablasDeMultiplicar();
						fgets(actividad, 5, stdin);
					}else{
						if(opcion == 3){
							numeroXrango();
							fgets(actividad, 5, stdin);
						}else{
							if(opcion == 4){
								embarcacion();
								fgets(actividad, 5, stdin);
							}else{
								if(opcion == 5){
									repetirMateria();
									fgets(actividad, 5, stdin);
								}else{
									printf("Ingrese un valor valido\n");
								}
							}
						}
					}
				}
			}

		}

		CLEAR;
	} while (salir == 0);

	return 0;
}

bool tieneDerecho(int promedio){
	if(promedio < 50)
		return FALSE;

	return TRUE;
}

int calificaciones(int n){
	char cal[50];
	int promedio = 0, aux = 0;
	int i;

	for (i = 0; i < n; i++){
		
		printf("Ingrese la calificacion %i:\n",i + 1);
		printf("->");
		fgets(cal, 50, stdin);
		aux = atoi(cal);

		if(aux != 0){
			if(aux > 100){
				aux = 0;
				printf("Ingrese un valor valido entre [1 - 100]\n");
				--i;	
			}else{
				promedio += aux;
			}
			
		}else{
			--i;
			CLEAR;
		}	

	}

	return promedio/n;
}

void alumnos(){
	int i;
	int sinDerecho = 0;
	int cal;
	
	for (i = 0; i < 2; i++){
		printf("Calificaciones del alumno %i\n",i);
		cal = calificaciones(MAX_UNIDADES);
		if(tieneDerecho(cal) == FALSE){
			sinDerecho++;
		}
		CLEAR;
	}

	printf("Alumnos sin derecho a examen de nivelacion %d\n",sinDerecho);

}

void tablasDeMultiplicar(){

	char tablaDe[10];
	int num;
	int i;

	printf("Ingrese un numero del 1 al 10\n");
	fgets(tablaDe, 10, stdin);
	num = atoi(tablaDe);

	if(num){
		if(num > 10){
			printf("Error ingrese un valor del 1 al 10\n");
		}else{
			if(num < 0){
				printf("Error ingrese un valor positivo del 1 al 10\n");
			}else{
				for (i = 1; i <= 10; i++){
					printf("%2d x %2d = %2d\n",num,i,i*num);
				}
			}
		}
	}else{
		printf("Error ingrese un numero del 1 al 10\n");
	}

}

void numeroXrango(){

	char rango1[10], rango2[10];
	char nVeces[10];
	int r1,r2;
	int n;
	float res = 0;
	char num[10];
	int numero;
	int i;

	printf("Cuantos numeros desea digitar?\n");
	printf("->");
	fgets(nVeces, 10, stdin);

	n = atoi(nVeces);

	if(n){
		printf("Que rango desea digitar sus numeros\n");
		printf("Rango 1:\n");
		printf("->");
		fgets(rango1, 10, stdin);
		printf("Rango 2:\n");
		printf("->");
		fgets(rango2, 10, stdin);
		r1 = atoi(rango1);
		r2 = atoi(rango2);

		if(r1 < r2){
			for (i = 0; i < n; i++){
				printf("[%d] ->",i);
				fgets(num, 10, stdin);
				numero = atoi(num);

				if(numero >= r1){
					if(numero <= r2){
						res += (float) numero;
					}else{
						printf("Ingrese un numero con rango menor o igual que %d\n",r2);
						--i;
					}
				}else{
					printf("Ingrese un numero con rango mayor o igual que %d\n",r1);
					--i;
				}
			}

			printf("Suma de todo los numero %.2f\n",res);
			printf("Media aritmetica %.2f\n",res/n);
		}else{
			printf("Rango 1, debe ser menor que rango 2 y distinto de rango 2 y 0\n");
		}
	}else{
		printf("Ingrese un numero valido\n");
	}
}

void embarcacion(){
	
	char cantidadDePasajeros[10];
	char kilosTotalDePasajeros[10];
	int pasajeros = 0;
	int kilosTotales = 0;
	int i;
	int bandera = 0;
	int bandera2 = 1;

	for (i = 1; bandera2 == 1; i++){
		bandera = 0;

		do{
			printf("Ingrese el peso en kilos del pasajero %d:\n",i);
			printf("->");
			fgets(kilosTotalDePasajeros, 10, stdin);
			if(strcmp(kilosTotalDePasajeros, "\n") != 0){
				bandera = 1;
			}

			if(!atoi(kilosTotalDePasajeros)){
				bandera = 0;
			}
			CLEAR;
		} while (bandera != 1);
		kilosTotales += atoi(kilosTotalDePasajeros);
		if(!(i < 10)){
			bandera2 = 0;
		}else{
			if (kilosTotales > 805)
			{
				bandera2 = 2;
			}
		}
	}
	
	if(bandera2 == 2){
		printf("Se cumplio peso maximo\n");
	}else{
		if(bandera2 == 0){
			printf("Se cumplio cantidad maxima\n");
		}
	}

	printf("promedio peso: %dkg\n",kilosTotales/--i);
	
}

void repetirMateria(){
	int vecesCursadas = 1;
	int calificacion;
	int salir = 0;

	do
	{
		calificacion = calificaciones(3);
		if(vecesCursadas >= 3){
			printf("Alumno dado de baja temporal\n");
			salir = 1;
		}else{
			if(calificacion < 30){
				printf("Repetir materia\n");
				vecesCursadas++;
			}else{
				printf("Aprobado\n");
				salir = 1;
			}
		}
	} while (salir == 0);

}