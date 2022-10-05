#include "rosaak.h"

int main(int argc, char const *argv[])
{
	char miCadena[] = "hola mundo";
	int i;

	printf("MAYUSCULAS:\n");
	mayusculas(miCadena);
	imprimirCadena(miCadena);
	JMPL;
	JMPL;
	printf("minuscula:\n");
	minusculas(miCadena);
	imprimirCadena(miCadena);
	JMPL;
	JMPL;
	printf("Capitalizacion:\n");
	Capitalizar(miCadena);
	imprimirCadena(miCadena);
	JMPL;
	JMPL;
	printf("longitud de %s -> %d",miCadena,longitud(miCadena) + 1);
	JMPL;
	JMPL;
	printf("Reversa:\n");
	imprimirCadena(voltearCadena(miCadena));
	JMPL;
	JMPL;
	printf("Sin espacios:\n");
	imprimirCadena(quitarEspacios(miCadena));
	JMPL;

	return 0;
}