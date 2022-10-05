#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "cadenas.h"

int main(int argc, char const *argv[])
{
	
	int i;
	cadenas *miCadena = NULL;
	char buff;
	int bandera = 1;

	while(bandera){
		buff = leerCaracter(1);

		if(buff == '\n'){
			bandera = 0;
		}else{
			if(buff != 127){
				agregarCadena(&miCadena, buff);
			}
		}
	}

	putchar(10);

	printf("Longitud de la cadena -> %d\n",obtenerLongitud(miCadena));
	printf("Contenido de la cadena -> %s\n",obtenerCadena(miCadena));

	return 0;
}