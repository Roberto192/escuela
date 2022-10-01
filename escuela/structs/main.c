/*
	crud //create read update deleted

	MENUWU

	agregar //create
	buscar //read
	modificar //update
	borrar //delete

*/

#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "main.h"

#define MAX_OPCIONES 10
#define MAX_ALUMNOS 10

#define LIMPIAR ponerCuadradoRelleno(0, 0, 60, 60, ' ')

alumno pedirDatos(){

	char matricula[MAX_MATRICULA];
	char nombre[MAX_NOMBRE];
	char apellidoPaterno[MAX_APELLIDO];
	char apellidoMaterno[MAX_APELLIDO];
	char carrera[MAX_CARRERA];
	char edad[3];

	ponerTextoCentradoY(15, "Dame el numero de la matricula: ");
	fgets(matricula, MAX_MATRICULA, stdin);
	LIMPIAR;

	ponerTextoCentradoY(15, "Dame el nombre del alumno: ");
	fgets(nombre, MAX_NOMBRE, stdin);
	LIMPIAR;

	ponerTextoCentradoY(15, "Dame el apellido paterno: ");
	fgets(apellidoPaterno, MAX_APELLIDO, stdin);
	LIMPIAR;

	ponerTextoCentradoY(15, "Dame el apellido materno: ");
	fgets(apellidoMaterno, MAX_APELLIDO, stdin);
	LIMPIAR;

	ponerTextoCentradoY(15, "Dame la edad: ");
	fgets(edad, 3, stdin);
	LIMPIAR;

	ponerTextoCentradoY(15, "Dame el nombre de la carrera: ");
	fgets(carrera, MAX_CARRERA, stdin);
	LIMPIAR;

	return crearAlumno(matricula, nombre, apellidoPaterno, apellidoMaterno, atoi(edad), carrera);
}

void mostrar(alumno *alumnos, int max){
	int i;

	if(max != 0){
		for (i = 0; i < max; i++){
			iraXY(8, i + 10);
			printf("%s",alumnos[i].matricula);
		}
	}else{
		iraXY(8, i + 10);
		printf("No hay alumnos registrados");
	}

	fgets(NULL, 0, stdin);
}

int main(int argc, char const *argv[])
{

	char opcion[MAX_OPCIONES];
	int opc;
	int salir = 0;
	int index = 0;

	alumno alumnos[MAX_ALUMNOS];
	alumno aux;

	while(!salir){
		menu();/*muestra menu*/
		fgets(opcion, MAX_OPCIONES, stdin);/*obtenemos datos*/
		opc = atoi(opcion);/*convertimos a entero*/
		LIMPIAR;/*limpiamos pantalla*/
		if(opc == 7){/*si es 7 no hacemos nada y se sale*/
			salir = 1;/*asignamos a salir como 1 para salir*/
		}else{
			if(opc == 1){/*si es 1 creamos un alumno*/
				aux = crearAlumno("1292118", "Roberto Isaac", "Arias", "Guerrero", 20, "ISYTE");
				agregar(alumnos, aux, index++);
			}else{
				if(opc == 2){
					ponerTextoCentradoY(15, "Encontrado en el indice");
					iraXY(15, 10);
					printf("%d",buscar(alumnos, "1292118", index));
				}else{
					if(opc == 3){
						mostrar(alumnos, index);
					}else{
						if(opc == 4){

						}else{
							if(opc == 5){

							}else{
								if(opc == 6){

								}else{
									ponerTextoCentradoY(15, "Error digite un valor valido");
								}
							}
						}
					}
				}
			}
		}
	}

	return 0;
}
