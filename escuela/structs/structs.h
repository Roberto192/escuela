#include <string.h>
#include <stdio.h>

#define MAX_MATRICULA 12
#define MAX_NOMBRE 50
#define MAX_APELLIDO 30
#define MAX_CARRERA 10

struct ALUMNO
{
	
	char matricula[MAX_MATRICULA];
	char nombre[MAX_NOMBRE];
	char apellidoPaterno[MAX_APELLIDO]; 
	char apellidoMaterno[MAX_APELLIDO];
	char carrera[MAX_CARRERA];

	int edad;

};

typedef struct ALUMNO alumno;


void agregar(alumno *, alumno, int);
int buscar(alumno *, char *, int);
void modificar(alumno *, alumno);
void eliminar(alumno *, char *);
void guardarCadena(char *, char *, int);
alumno crearAlumno(char *,char *,char *,char *, int,char *);

alumno crearAlumno(char *matricula, char *nombre, char *apellidoPaterno, char *apellidoMaterno, int edad, char *carrera){
	alumno aux;

	guardarCadena(&aux.matricula[0], matricula, MAX_MATRICULA);
	guardarCadena(&aux.nombre[0], nombre, MAX_NOMBRE);
	guardarCadena(&aux.apellidoPaterno[0], apellidoPaterno, MAX_APELLIDO);
	guardarCadena(&aux.apellidoMaterno[0], apellidoMaterno, MAX_APELLIDO);
	guardarCadena(&aux.carrera[0], carrera, MAX_CARRERA);

	aux.edad = edad;

	return aux;
}

void guardarCadena(char *cadena1,char *cadena2, int max){
	int i;

	for(i = 0; i < max - 1 || cadena2[i] != '\0'; i++){
		*cadena1 = cadena2[i];
		printf("%c",*cadena1);
		cadena1++;
	} 
}

void agregar(alumno *alumnos, alumno aux, int index){
	alumnos[index] = aux;
}

int buscar(alumno *alumnos, char *matricula, int max){
	int i;

	for (i = 0; i < max; i++){
		if(strcmp(alumnos[i].matricula, matricula) == 0){
			return i;
		}
	}

	return -1;
}