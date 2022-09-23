#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

void menu();
void fibonnaci();
void factorial();
void cantidadDigitos();

int main(int argc, char const *argv[])
{

	factorial();

	return 0;


}

void menu(){

	puts("\t\t    MEUWU");
	puts("\t\t    [1] Fibonacci");
	puts("\t\t    [2] Factorial");
	puts("\t\t    [3] Cantidad de digitos");

}

void fibonnaci(){

	int anterior = 0;
	int actual = 1;
	int suma = 0;
	int i;
	
	for(i = 0; i < 15; i++){
		printf("%d ",anterior);
		suma = anterior + actual;
		anterior = actual;
		actual = suma;
	}
}

void factorial(){

	char numeroChar;

	printf("Ingrese el numero del factorial");
	gets(numeroChar);

}