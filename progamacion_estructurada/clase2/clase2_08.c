//                                          clase2_07
//                      programa que calcule las horas dormido en to'a mi vida       
//                  Nombre: Roberto Isaac Arias Guerrero Matricula: 1292118
//                                      Fecha: 19/08/2022

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    
    int unsigned edad, dias; 
    int horas;
    int horasDormidas;

    printf("Ingresa tu edad: ");
    scanf("%u",&edad);

    dias = edad * 365;
    horas = dias * 24;
    horasDormidas = horas / 3;

    printf("Durante %u a%cos haz dormido %u horas\n",edad, 164, horasDormidas);

    printf("%i",u'ñ');

    system("pause>>null");

    return 0;
}