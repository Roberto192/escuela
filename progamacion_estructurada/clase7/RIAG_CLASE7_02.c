#include "rosaak.h"

#define MAX 100

void validar(char *cadena, int n){

	int i = 0;
	int j = 0;
	int band = 1;
	int espacio = 1;
	char aux[MAX];

	fflush(stdin);
	fgets(cadena, n, stdin);

	while(cadena[0] == ' ')
		quitarEspaciosExtras(cadena);

	for(i = 0; band; i++){
		if(cadena[i] != '\0'){
			if(i < n){
				if(cadena[i] >= 'a'){
					if(cadena[i] <= 'z'){
						aux[j++] = cadena[i];
						espacio = 1;
					}
				}

				if(cadena[i] >= 'A'){
					if(cadena[i] <= 'Z'){
						aux[j++] = cadena[i];
						espacio = 1;
					}
				}

				if(cadena[i] == ' '){
					if(espacio){
						aux[j++] = ' ';
						espacio = 0;
					}
				}

			}else{
				band = 0;
			}
		}else{
			band = 0;
		}
	}

	aux[j] = '\0';
	strcpy(cadena, aux);

}

int main(int argc, char const *argv[])
{
	char miCadena[] = "hola mundo";
	char miOtraCadena[MAX];
	int i;
	char c;

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
	JMPL;

	for (i = 0; i < 10; i++){
		c = getc(stdin);
		printf("%c",c - 32);
	}

	return 0;
}