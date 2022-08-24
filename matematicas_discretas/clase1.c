#include <stdio.h>
#include <stdlib.h>

/*
int main(){

    int calificacion;

    printf("Ingrese la calificacion\n");
    scanf("%i",&calificacion);

    if (calificacion > 100 || calificacion < 0) {
        printf("Calificacion fuera de rango\n");

        system("pause>>null");
        return 0;
    }

    if (calificacion >= 90 && calificacion <= 100) {
        printf("Su calificacion es excelente: %i\n",calificacion);
    }else if (calificacion >= 80 && calificacion <= 89) {
        printf("Su calificacion es buena: %i\n",calificacion);
    }else if (calificacion >= 70 && calificacion <= 79) {
        printf("Su calificacion es regular: %i\n",calificacion);
    }else if (calificacion >= 60 && calificacion <= 69) {
        printf("Su calificacion es baja: %i\n",calificacion);
    }else if (calificacion >= 0 && calificacion <= 59) {
        printf("Su calificacion es reprobatorio: %i\n",calificacion);
    }

    system("pause>>null");

    return 0;
}
*/


int main(){

    float montoMensual = 1200, montoInscripcion = 300;
    int esAlumno;

    printf("Es alumno de la universidad de la UABC\nDigite 1 para si\nDigite 2 para no\n");
    scanf("%i",&esAlumno);

    if(esAlumno == 1){
        montoInscripcion *= 0.30f;
        montoMensual *= 0.30f;
    }
    
    printf("El monto de la incripcion es: %.2f \n",montoInscripcion);
    printf("El monto de la mensualidad es: %.2f \n",montoMensual);

    system("pause>>null");

    return 0;
}