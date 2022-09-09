//                                          clase2_07
//                      programa que calcule el teorema de pitagoras       
//                  Nombre: Roberto Isaac Arias Guerrero Matricula: 1292118
//                                      Fecha: 19/08/2022

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	unsigned a, b, hipotenusa;

	printf("Ingrese el primer cateto: ");
	scanf("%u",&a);
	printf("Ingrese el segundo cateto: ");
	scanf("%u",&b);

	hipotenusa = a + b;

	printf("%u^2 = %u^2 + %u^2\n",hipotenusa,a,b);

	system("pause>>null");

	return 0;
}