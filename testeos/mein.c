#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
  
  char *cadena, *a;
  cadena = a = (char *) malloc(4);
  
  strcpy_s(cadena, 5, "Hola");
  
  printf("%s\n", cadena);
  
  for(int i = -1000; i < 1000; i++){
    *(cadena + i) = '\0';
    putchar(*(cadena + i));
    printf("-> %p\n", cadena + i);
    a = cadena - 100;
    a++;
  }
  
  printf("%s",a-4);
  
  return 0;
}