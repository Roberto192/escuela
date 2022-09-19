//		RIAG_CLASE4_09
/*
		8.- Programa en C que sirva para el juego del CHINCHAMPU (Piedra, Papel, Tijera)
		para 1 jugador y la computadora

*/
//		Nombre: Roberto Isaac Arias Guerrero Matricula: 1292118
//		2022/09/07

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PIEDRA 1
#define PAPEL 2
#define TIJERA 3

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	//Datos a pedir
	int opcionJugador;
	//Datos a procesar 55 5169 4300 superlinea SANTANDER //opcion 4
	int opcionComputadora;

	printf("\t\t---- [ MENUwU ] ----\n\n");
	printf("\t\t--------------------\n");
	printf("\t\t| 1.- PIEDRA       |\n");
	printf("\t\t| 2.- PAPEL        |\n");
	printf("\t\t| 3.- TIJERA       |\n");
	printf("\t\t--------------------\n");
	printf("\n\n\n\n\n");
	printf("Jugador 1 :->");
	scanf(" %i",&opcionJugador);

	opcionComputadora = rand() % 3 + 1;
	printf("Jugador 2 :->%i\n",opcionComputadora);

	if(opcionComputadora == opcionJugador){
				printf("Empate!!!");
	}else{
		switch(opcionComputadora){
			case PIEDRA:
				if(opcionJugador == PAPEL){
					printf("Gana jugador 1");
				}else{
					printf("Gana jugador 2");
				}
			break;
			case PAPEL:
				if(opcionJugador == TIJERA){
					printf("Gana jugador 1");
				}else{
					printf("Gana jugador 2");
				}
			break;
			case TIJERA:
				if(opcionJugador == PIEDRA){
					printf("Gana jugador 1");
				}else{
					printf("Gana jugador 2");
				}
			break;
		}
	}

	printf("\n");
	system("read -p ''");

	return 0;
}
