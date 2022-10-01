#include "rosaak.h"

int main(int argc, char const *argv[]){

	char texto[] = "ENSENADA";
	char *textoVolteado = voltearCadena(texto);

	puts("Primera Salida");
	imprimirCadena(texto);
	stdlin;
	puts("Segunda Salida");
	imprimirCadena(textoVolteado);
	stdlin;
	puts("Tercera Salida");
	imprimirCadenaHorizontal(texto);
	stdlin;
	puts("Cuarta Salida");
	imprimirCadenaHorizontal(textoVolteado);
	stdlin;
	puts("Quinta Salida");
	recortarPorDerechaCadena(texto);
	stdlin;
	puts("Sexta Salida");
	recortarPorDerechaCadena(textoVolteado);
	stdlin;
	puts("Septima Salida");
	recortarPorIzquierdaCadena(texto);
	stdlin;
	puts("Octava Salida");
	recortarPorIzquierdaCadena(textoVolteado);
	puts("Novena salida");
	vocales(texto, 0);
	puts("Decima salida");
	vocales(texto, 1);

	free(textoVolteado);

	return 0;
}
