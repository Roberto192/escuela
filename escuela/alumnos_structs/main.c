#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "estructuras.h"
#include "ventanas.h"

#define MAX_ALUMNOS 10
#define MAX 3

int validarMatricula(char *);
void pedirDato(char *, int , char *, char *, int );
alumno crearAlumno(char *, char *, char *, char *, char *, int edad);
alumno pedirDatos(int, char *); 
void mostrarAlumnos(alumno *, int);
int buscarXmatricula(alumno *, char *, int);
int eliminarXmatricula(alumno *, char *, int);
int actualizarXmatricula(alumno *, char *, int);
char *upper(char *);
void menu();

int main(int argc, char const *argv[])
{
	
	alumno alumnos[MAX_ALUMNOS];
	alumno aux;

	int indice = 0;
	char opcion[MAX];
	char matriculaOpc[MAX_MATRICULA];
	int opcionEntera = 0;
	int salir = 0;

	while(!salir){
		menu();
		fgets(opcion, MAX, stdin);

		opcionEntera = atoi(opcion);

		if(opcionEntera == 6){
			salir = 1;
		}else{
			if(opcionEntera == 1){
				aux = pedirDatos(TRUE, NULL);
				alumnos[indice++] = aux;
				fgets(opcion, MAX, stdin);
			}else{
				if(opcionEntera == 2){
					mostrarAlumnos(alumnos, indice);
					fgets(opcion, MAX, stdin);
				}else{
					if(opcionEntera == 3){
						ponerTextoEnXY(10, 5, "Dame la matricula: ");
						fgets(matriculaOpc, MAX_MATRICULA, stdin);
						actualizarXmatricula(alumnos, matriculaOpc, indice);
						fgets(opcion, MAX, stdin);
					}else{
						if(opcionEntera == 4){
							
							pedirDato(matriculaOpc, MAX_MATRICULA, "Dame la matricula: ", "Ingrese una matricula correcta", TRUE);
							if(eliminarXmatricula(alumnos, matriculaOpc, indice) == FALSE){
								ponerColor(ERROR_COLOR);
								ponerTextoEnXY(10, 15, "Matricula no encontrada");
							}else{
								indice--;
								ponerColor(MAIN_COLOR);
								ponerTextoEnXY(10, 15, "Alumno eliminado satisfactoria mente");
							}
							ponerColor(RESET_COLOR);
							fgets(opcion, MAX, stdin);
						}else{
							if(opcionEntera == 5){

								pedirDato(matriculaOpc, MAX_MATRICULA, "Dame la matricula: ", "Matricula no valida", TRUE);
								opcionEntera = buscarXmatricula(alumnos, matriculaOpc, indice);
								if(opcionEntera != -1){
									iraXY(10, 5);
									printf("Matricula: %s",alumnos[opcionEntera].matricula);
									iraXY(10, 6);
									printf("Nombre: %s",alumnos[opcionEntera].nombre);
									iraXY(10, 7);
									printf("Apellido paterno: %s",alumnos[opcionEntera].apellidoPaterno);
									iraXY(10, 8);
									printf("Apellido materno: %s",alumnos[opcionEntera].apellidoMaterno);
									iraXY(10, 9);
									printf("Carrera: %s",alumnos[opcionEntera].carrera);
									iraXY(10, 10);
									printf("Edad: %d",alumnos[opcionEntera].edad);
								}else{
									ponerTextoCentradoY(15, "Matricula no encontrada");
								}

								fgets(opcion, MAX, stdin);
							}
						}
					}
				}
			}
		}
	}

	return 0;
}

char *upper(char *cadena){
	int i;
	int len = strlen(cadena);
	char *c = (char *) malloc(len);

	for(i = 0; i < len; i++){
		c[i] = toupper(cadena[i]);
	}

	return c;
}

alumno crearAlumno(char *mtrcl, char *nmbr, char *aplldptrn, char *aplldmtrn, char *crrr, int dd){
	alumno aux;

	char *mt = upper(mtrcl);
	char *nm = upper(nmbr);
	char *app = upper(aplldptrn);
	char *apm = upper(aplldmtrn);
	char *cr = upper(crrr);

	strcpy(aux.matricula, mt);
	strcpy(aux.nombre, nm);
	strcpy(aux.apellidoPaterno, app);
	strcpy(aux.apellidoMaterno, apm);
	strcpy(aux.carrera, cr);
	aux.edad = dd;

	return aux;
}

int validarMatricula(char *matricula){

	if(atol(matricula) < 999999){
		return FALSE;
	}

	return TRUE;
}

void pedirDato(char *dato, int size, char *msg, char *msgError, int isMat){
	int salir = FALSE;


	ponerCuadradoRelleno(MAXWIDHT/2 - 16, 1, MAXWIDHT/2 + 16, 13, ' ');
	
	do
	{
		ponerCuadradoRelleno(MAXWIDHT/2 - 16, 5, MAXWIDHT/2 + 16, 6, ' ');
		ponerTextoEnXY(MAXWIDHT/2-16, 5, msg);
		fgets(dato, size, stdin);
		if(isMat){
			if(validarMatricula(dato) == TRUE){
				salir = TRUE;
			}else{
				salir = FALSE;
				ponerColor(ERROR_COLOR);
				ponerTextoEnXY(MAXWIDHT/2-16, 4, msgError);
				ponerColor(RESET_COLOR);
			}
		}else{
			if(strcmp(dato, "\n") != 0){
				salir = TRUE;
			}else{
				salir = FALSE;
				ponerColor(ERROR_COLOR);
				ponerTextoEnXY(MAXWIDHT/2-16, 4, msgError);
				ponerColor(RESET_COLOR);
			}
		}

	} while (salir == FALSE);
}

alumno pedirDatos(int pM, char *__matricula){
	char matricula[MAX_MATRICULA];
	char nombre[MAX_NOMBRE];
	char apellidoPaterno[MAX_APELLIDO];
	char apellidoMaterno[MAX_APELLIDO];
	char carrera[MAX_CARRERA];
	char edad[MAX_EDAD];

	if(pM == TRUE){
		pedirDato(matricula, MAX_MATRICULA, "Ingrese la matricula: ", "Ingrese un valor valido de matricula", TRUE);
	}else{

		if(__matricula != NULL){
			strcpy(matricula, __matricula);
		}else{
			ponerTextoEnXY(10, 5, "Error de programacion");
			exit(-1000);
		}

	}

	pedirDato(nombre, MAX_NOMBRE, "Ingrese el nombre: ", "Ingrese un nombre valido", FALSE);
	pedirDato(apellidoPaterno, MAX_APELLIDO, "Ingrese el apellido paterno: ", "Ingrese un apellido valido", FALSE);
	pedirDato(apellidoMaterno, MAX_APELLIDO, "Ingrese el apellido materno: ", "Ingrese el a", FALSE);
	pedirDato(carrera, MAX_CARRERA, "Ingrese la carrera: ", "Ingrese una carrera validar", FALSE);
	pedirDato(edad, MAX_EDAD, "Ingrese la edad: ", "Ingrese una edad valida", FALSE);

	ponerTextoCentradoY(15, matricula);
	ponerTextoCentradoY(16, nombre);
	ponerTextoCentradoY(17, apellidoPaterno);
	ponerTextoCentradoY(18, apellidoMaterno);
	ponerTextoCentradoY(19, carrera);
	ponerTextoCentradoY(20, edad);

	return crearAlumno(matricula, nombre, apellidoPaterno, apellidoMaterno, carrera, atoi(edad));
}

void mostrarAlumnos(alumno *alumnos, int max){
	int i;

	ponerTextoEnXY(1, 3, "Matricula   Nombre\t\t Carrera  Edad");

	if(max != 0){
		for (i = 0; i < max; i++){
			//ponerTextoEnXY(1, 5 + i, alumnos[i].matricula);
			//ponerTextoEnXY(13, 5 + i, alumnos[i].nombre);
			//ponerTextoEnXY(34, 5 + i, alumnos[i].carrera);
			//iraXY(45, 5 + i);
			//printf("%d",alumnos[i].edad);
		}
	}else{
		ponerTextoEnXY(1, 5, "No hay alumnos creados");
	}

}

int buscarXmatricula(alumno *alumnos, char * matricula, int max){
	int i;

	for(i = 0; i < max; i++){
		if(strcmp(alumnos[i].matricula, matricula) == 0){
			return i;
		}
	}

	return -1;
}

int eliminarXmatricula(alumno *alumnos, char *matricula, int max){
	int indice = buscarXmatricula(alumnos, matricula, max);
	int i;

	if(indice != -1){
		for (i = indice; i < max - 1; i++){
			alumnos[i] = alumnos[i + 1]; 
		}

		return TRUE;
	}

	return FALSE;
}

int actualizarXmatricula(alumno *alumnos, char *matricula, int max){
	int indice = buscarXmatricula(alumnos, matricula, max);

	if(indice != -1){
		char *nombre = alumnos[indice].nombre;
		char *apellidoP = alumnos[indice].apellidoPaterno;
		char *apellidoM = alumnos[indice].apellidoMaterno;
		char *carrera = alumnos[indice].carrera;
		int edad = alumnos[indice].edad;

		alumnos[indice] = pedirDatos(FALSE, matricula);
		return 1;
	}else{
		ponerColor(ERROR_COLOR);
		ponerTextoEnXY(10, 16, "La matricula no existe");
		ponerColor(RESET_COLOR);
	}

	return 0;
}

void menu(){
	rellenarColorDeLaConsola(RESET_COLOR);
	ponerColor(ERROR_COLOR);
	ponerCuadradoConTextoCentradoEnXY("Menu UwU", MAXWIDHT/2 - 16, 4, MAXWIDHT/2 + 16, 13, 3);
	ponerColor(MESAGE_COLOR);
	ponerTextoCentradoY(5, "[1] Crear          ");
	ponerTextoCentradoY(6, "[2] Mostrar        ");
	ponerTextoCentradoY(7, "[3] Actualizar     ");
	ponerTextoCentradoY(8, "[4] Eliminar       ");
	ponerTextoCentradoY(9, "[5] Buscar         ");
	ponerTextoCentradoY(10, "[6] Guardar y Salir");
	iraXY(MAXWIDHT/2 - 15, 12);
	ponerColor(MAIN_COLOR);
	printf("->");
	ponerColor(RESET_COLOR);
}