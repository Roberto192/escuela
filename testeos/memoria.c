#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	/*
	int arreglo[10] = {1,2,3,4,5,6,7,8,9,10};

	for(int i = 0; i < (int) sizeof(arreglo)/sizeof(int); i++){
		printf("%i\n",*arreglo);
		(*arreglo)++;
	}

	for(int i = 0; i < (int) sizeof(arreglo)/sizeof(int); i++){
		printf("%p\n",&arreglo[i]);
	}*/
	
	char *miCadena = malloc(5);
	char *c;
	
	miCadena = "Hola\0";
	printf("%s\n",miCadena);
	printf("%p\n",&(*miCadena));
	printf("%p\n",&miCadena);
	printf("%p\n",&(miCadena));
	
	scanf("%p",&c);
	printf("%s\n",c);
	printf("%c",*(c++));
	printf("%c",*(c++));
	printf("%c",*(c++));
	printf("%c",*(c++));
	
	return 0;
}