//			RIAG_clase3_11.c
/*			
			11.- Algoritmo que sirva para desplegar el Total de una llamada telefónica donde se pide

			como datos de entrada los ​ minutos​ y el ​ tipo de llamada​ , se cobra de la siguiente manera:

			1.- Llamada Loca​ l $3.00 sin límite de tiempo

			2.-​ ​ Llamada Nacional​ $7.00 por los 3 primeros minutos y $2.00 minuto adicional

			3.-​ ​ Llamada Internacional​ $9.00 por los 2 primeros minutos y $4.00 minuto

			adicional

			Desplegar, ​ Subtotal​ ,​ Iva​ (16%) y ​ Tota​l.
*/
//			Nombre: Robero=to Isaac Arias Guerrero Matricula: 1292118
//			Fecha: 2022-08-26

#include <stdio.h>
#include <stdlib.h>

#define IVA 0.16

int main(int argc, char const *argv[])
{

	//Datos a pedir

	int minutosLlamados, tipoDeLlamada;

	//Datos a calcular

	float subtotal, total, iva;
	int minutosLlamadosAdicionales;

	printf("Calcula el precio de una llamada\n");
	printf("Ingrese los minutos en llamada: ");
	scanf(" %i",&minutosLlamados);
	printf("Ingrese el tipo de llamada: (1 = Local, 2 = Nacional, 3 = Internacional)\n");
	scanf(" %i",&tipoDeLlamada);

	if(tipoDeLlamada == 1){
		subtotal = minutosLlamados * 3;
	}else{
		if(tipoDeLlamada == 2){
			if(minutosLlamados > 3){
				minutosLlamadosAdicionales = minutosLlamados - 3;
				subtotal = (3 * 7) + (minutosLlamadosAdicionales * 2); 
			}else{
				subtotal = minutosLlamados * 7;
			}
		}else if(tipoDeLlamada == 3){
			if(minutosLlamados > 2){
				minutosLlamadosAdicionales = minutosLlamados - 2;
				subtotal = (2 * 9) + (minutosLlamadosAdicionales * 4); 
			}else{
				subtotal = minutosLlamados * 7;
			}
		}
	}

	iva = subtotal * IVA;

	total = subtotal + iva;

	printf("Minutos Hablados: %i\nSubtotal: %.2f\nIVA (0.16): %.2f\nTotal: %.2f\n",minutosLlamados,subtotal,iva,total);

	return 0;
}