//                                          clase2_02
//                      programa que calcule el volumen de un cilindro       
//                  Nombre: Roberto Isaac Arias Guerrero Matricula: 1292118
//                                      Fecha: 19/08/2022

#include <stdio.h>
#include <stdlib.h>

#define PI 3.141516

int main(int argc, char const *argv[])
{
    
    unsigned altura, radio;
    float volumen;

    printf("Ingrese la altura del cilindro: ");
    scanf("%u",&altura);
    printf("Ingrese el radio del cilindro: ");
    scanf("%u",&radio);

    volumen = (float) PI*(radio * radio)*altura;

    printf("Volumen del cilindro es: %.4f * %u^2 * %u = %.2f u^3\n\n", PI,radio,altura,volumen);

    system("pause>>null");

    return 0;
}