//               RIAG_CLASE08_01
/*
    Crear propia libreria
    (Funciones de validar cadenas, cadenas)
*/
//		Nombre: Roberto Isaac Arias Guerrero Matricula: 1292118
//		Fecha: 2022-08-26

#include "..h"

#define MAX 10

int main(){
    
    srand(time(NULL));
    
    int palabras[MAX];
    
    llaa(palabras, MAX, 'a', 'z');
    imprimirArreglo(palabras, MAX);
    
    return 0;
}