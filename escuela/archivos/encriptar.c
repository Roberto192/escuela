#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "datos.data"
#define DUCKY 30
#define MAX 10000

int main(){
  
  FILE *datos;
  char texto[MAX];
  char c;
  int i = 0;
  int max;
  
  datos = fopen(FILE_NAME, "r");
  
  while((c = fgetc(datos)) != EOF){
    texto[i++] = c + DUCKY;
    texto[i] = '\0';
  }
  
  printf("%s",texto);
  
  fclose(datos);
  
  datos = fopen(FILE_NAME, "w");
  
  fprintf(datos, "%s",texto);
  
  fclose(datos);
  
  return 0;
}