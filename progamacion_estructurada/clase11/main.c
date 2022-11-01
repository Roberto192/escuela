#include <stdio.h>
#include <stdlib.h>
#include "validar.h"
#include "rosaak.h"
#include "CURPC.h"

int main(){
  
  TSfecha fechaDeNacimiento;
  TSfecha fechaMin = {1, 1, 1940};
  TSfecha fechaMax = {1, 12, 2022};
  char fecha[11];
  
  fechaDeNacimiento = validarFecha(fechaMin, fechaMax);
  obtenerFecha(fecha ,11  , fechaDeNacimiento);
  
  puts(fecha);

  return 0;
}