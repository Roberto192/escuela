// RIAG_CLASE10
// ESTRUCTURAS
// NOMBRE: ROBERTO ISAAC ARIAS GUERRERO MATRICULA: 1292118
// FECHA: 19/10/2022

#include <stdio.h>
#include <stdlib.h>
#include "milib.h"

void valerror(int , char [], char []);

int main(){
  
  Talumno alumnos[500];
  Tnombre nombre;
  Tapellido apellido_buff;
  
  logico ordenado = FALSE;
  int op = 0;
  int error;
  
  while(op != 7){
    op = menu();
  
    switch(op){
      case 1:
        error = agregarAleatorio(alumnos, 500, 0, 10);
        valerror(error, "Rango es mayor al arreglo", "Usuarios agregados correctamente");
      break;
      case 2:
        ordenado = FALSE;
        error = insertarDatos(alumnos, 500);
        valerror(error, "No se a podido crear el usuario", "Usuario agregado satisfactoriamente");
      break;
      case 3:
        buboReg(alumnos, 500, validarNumeroLCR("Ingrese el numero de la matricula a borrar: ", "Ingrese una matricula correcta", 1, 1000000, 3999999), TRUE);
        ordenado = FALSE;
      break;
      case 4:
        buboReg(alumnos, 500, validarNumeroLCR("Ingrese el numero de la matricula a buscar: ", "Ingrese una matricula correcta", 1, 1000000, 3999999), FALSE);
      break;
      case 5:
        if(!ordenado){
          ordenarReg(alumnos, 500);
          imprimirDatos(alumnos, 500, 0 , 500);
          ordenado = TRUE;
        }else{
          printf("Ya esta ordenado\n");
        }
      break;
      case 6:
        imprimirDatos(alumnos, 500, 0, 500);
      break;
      case 7:
        printf("Saliendo...\n");
      break;
      default:
        printf("Ingrese un valor correcto\n");
    }
    
    system("pause");
  }
}

void valerror(int error, char msgError[], char msgBueno[]){
  if(error == 0){
    puts(msgBueno);
  }else{
    if(error == -1){
      printf("Error:\n%s", msgError);
    }
  }
}