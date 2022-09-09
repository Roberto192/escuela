//		RIAG_CLASE4_08
/*
		8.- Programa en C que sirva para el juego del CHINCHAMPU (Piedra, Papel, Tijera)
		para 1 jugador y la computadora, (usar condición anidada)

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

	if(opcionJugador == opcionComputadora){
		printf("Empate!!!");
	}else{
		if(opcionJugador == PIEDRA){
			if(opcionComputadora == PAPEL){
				printf("Gana jugador 2");
			}else{
				printf("Gana jugador 1");
			}
		}else{
			if (opcionJugador == PAPEL){
				if(opcionComputadora == TIJERA){
					printf("Gana jugador 2");
				}else{
					printf("Gana jugador 1");
				}
			}else{
				if(opcionComputadora == PIEDRA){
					printf("Gana jugador 2");
				}else{
					printf("Gana jugador 1");
				}
			}
		}
	}


	printf("\n");
	system("read -p ''");

	return 0;
}