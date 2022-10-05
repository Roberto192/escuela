#include "rosaak.h"

int main(int argc, char const *argv[])
{
	char miCadena[] = "hola mundo";
	int i;

	printf("MAYUSCULAS:\n");
	mayusculas(miCadena);
	imprimirCadena(miCadena);
	stdlin;
	printf("minuscula:\n");
	minusculas(miCadena);
	imprimirCadena(miCadena);
	stdlin;
	printf("Capitalizacion:\n");
	Capitalizar(miCadena);
	imprimirCadena(miCadena);
	stdlin;
	printf("longitud de %s -> %d",miCadena,longitud(miCadena) + 1);
	stdlin;
	printf("Reversa:\n");
	imprimirCadena(voltearCadena(miCadena));
	stdlin;
	printf("Sin espacios:\n");
	imprimirCadena(quitarEspacios(miCadena));
	stdlin;
	printf(ge)

	return 0;
}