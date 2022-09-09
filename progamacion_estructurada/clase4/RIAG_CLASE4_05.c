//		RIAG_CLASE4_05
/*
	5.- Programa en C que sirva para desplegar el Total de una llamada telefónica donde se pide como datos de entrada los minutos y el tipo de llamada, se cobra de la siguiente manera:


	MENÚ

	1.- Llamada Local $3.00 sin límite de tiempo

	2.- Llamada Nacional $7.00 por los 3 primeros minutos y $2.00 minuto adicional

	3.- Llamada Internacional $9.00 por los 2 primeros minutos y $4.00 minuto adicional

	Desplegar, Subtotal,Iva (16%) y Total.
*/
//		Nombre: Roberto Isaac Arias Guerrero Matricula: 1292118
//		2022/09/07
#include <stdio.h>
#include <stdlib.h>

#define LOCAL 1
#define LOCALPRECIO 3.00
#define NACIONAL 2
#define NACIONALPRECIO1 7.00
#define NACIONALPRECIO2 2.00
#define INTERNACIONAL 3
#define INTERNACIONALPRECIO1 9.00
#define INTERNACIONALPRECIO2 4.00
#define IVA 16/100

int main(int argc, char const *argv[])
{
	
	//Datos a pedir
	int opcion, tiempo;
	//Datos a procesar
	float subtotal, impuesto, total;

	printf("\t---------- [ MENUwU ] ---------\n\n");
	printf("\t-------------------------------\n");
	printf("\t| 1.- Llamada Local   \t\t|\n");
	printf("\t| 2.- Llamada Nacional\t\t|\n");
	printf("\t| 3.- Llamada Internacional\t|\n");
	printf("\t-------------------------------\n");
	printf(":->");
	scanf(" %i",&opcion);
	printf("Tiempo hablado\n");
	printf(":->");
	scanf(" %i",&tiempo);

	if(LOCAL == opcion){
		subtotal = LOCALPRECIO * tiempo;
		impuesto = subtotal * IVA;
	}else{
		if(NACIONAL == opcion){
			if(3 > tiempo){
				subtotal = NACIONALPRECIO1 * 3;
				impuesto = subtotal * IVA;
				subtotal += NACIONALPRECIO2 * (tiempo - 3);
				impuesto += subtotal * IVA;
			}else{	
				subtotal = NACIONALPRECIO1 * tiempo;
				impuesto = subtotal * IVA;
			}
		}else{			
			if(INTERNACIONAL == opcion){
				if(2 > tiempo){
					subtotal = INTERNACIONALPRECIO1 * 2;
					impuesto = subtotal * IVA;
					subtotal += INTERNACIONALPRECIO2 * (tiempo - 2);
					impuesto += subtotal * IVA;
				}else{	
					subtotal = INTERNACIONALPRECIO1 * tiempo;
					impuesto = subtotal * IVA;
				}	
			}
		}

	}

	total = subtotal + impuesto;

	//Desplegar, Subtotal,Iva (16%) y Total.
	printf("Subtotal:\t %5.2f%c",subtotal,10);
	printf("Iva:\t\t %5.2f%c",impuesto,10);
	printf("Total:\t\t %5.2f%c",total,10);

	//system("pause");//para sistema operativo windows
	system("read -p 'presione cualquier tecla para salir...'");//para sistema operativo linux


	return 0;
}