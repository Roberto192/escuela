#include "struct_alumnos.h"
#include <stdio.h>

void leerMatricula(char *, int);

int main(int argc, char const *argv[])
{
	char matricula[MAX_MATRICULA];
	alumnos estudiantes = NULL;
	int  i = 1, j = 1;
	char c;
	
	while(i){
		CLEAR;
		printf("Menu\n");
		printf("[1] Crear\n");
		printf("[2] eliminar\n");
		printf("[3] enlistar\n");
		printf("[4] salir\n");
		
		c = leerCaracter(0);
		
		if(c >= '1'){
			if(c <= '4'){
				CLEAR;
				switch(c){
					case '1':
						printf("Ingrese la matricula: ");
						leerMatricula(matricula, MAX_MATRICULA);
						agregarAlumno(&estudiantes, matricula);
					break;
					case '2':
						printf("Ingrese la matricula a borrar\n");
						leerMatricula(matricula, MAX_MATRICULA);
						eliminar(&estudiantes, matricula);
						leerCaracter(0);
					break;
					case '3':
						mostrar(estudiantes);
						leerCaracter(0);

					break;
					case '4':
						printf("Seguros que quieres salir (y/n)\n");
						
						j = 1;
						while(j){
							c = leerCaracter(0);
							if(c == 'y'){
								i = 0;
								j = 0;
							}
							
							if(c == 'n'){
								j = 0;
							}
						}
				}
			}
		}
	}
		
	return 0;
}

void leerMatricula(char *matricula, int tam){
	int i = 0;
	int bandera = 1;
	char c;	
	
	while(bandera){
		
		c = leerCaracter(0);
				
		if(c >= '0'){
			if(c <= '9'){
				printf("%c",c);
				matricula[i++] = c;		
			}
		}

		if(i >= tam){
			bandera = 0;
		}
				
		if(c == '\r'){
			if(i >= tam - 6){
				bandera = 0;
			}
		}
	}		
	matricula[i] = '\0';

}