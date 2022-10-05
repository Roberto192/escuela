#include "cadenas.h"

int main(int argc, char const *argv[])
{
	
	int i;
	cadenas *miCadena = NULL;
	char buff;

	int bandera = 1;

	while(bandera){
		buff = leerCaracter(1);

		if(buff == JUMPLINE_CHAR){
			bandera = 0;
		}else{
			if(buff != BACKSPACE_CHAR){
				agregarCadena(&miCadena, buff);
			}
		}
	}

	JUMPLINE;

	printf("Longitud de la cadena -> %d\n",obtenerLongitud(miCadena));
	printf("Contenido de la cadena -> %s\n",obtenerCadena(miCadena));

	return 0;
}