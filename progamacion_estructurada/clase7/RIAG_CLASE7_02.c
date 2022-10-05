#include "rosaak.h"

int main(int argc, char const *argv[])
{
	char miCadena[] = "hola mundo";
	int i;

	printf("MAYUSCULAS:\n");
	mayusculas(miCadena);
	imprimirCadena(miCadena);
	stdlin;
	stdlin;
	printf("minuscula:\n");
	minusculas(miCadena);
	imprimirCadena(miCadena);
	stdlin;
	stdlin;
	printf("Capitalizacion:\n");
	Capitalizar(miCadena);
	imprimirCadena(miCadena);
	stdlin;
	stdlin;
	printf("longitud de %s -> %d",miCadena,longitud(miCadena) + 1);
	stdlin;
	stdlin;
	printf("Reversa:\n");
	imprimirCadena(voltearCadena(miCadena));
	stdlin;
	stdlin;
	printf("Sin espacios:\n");
	imprimirCadena(quitarEspacios(miCadena));
	stdlin;

	return 0;
}