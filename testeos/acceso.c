#include <stdio.h>

int main(){
  int mem = 0;
  int ubicacion = 248;
  mem [(int *) ubicacion] = 65;
  char x = mem[(int *) ubicacion];
  printf("%d",x);
  return 0;
}