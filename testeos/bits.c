#include <limits.h>
#include <stdio.h>

typedef struct tvalor{
  char v;
}Tvalor;

void showBites(void *valor){
  
  Tvalor *v = valor;
  char j = v->v;
  int i;
  
  for(i = sizeof(char) * 8 - 1; i >= 0; i--)
    printf("%d",(int)(j >> i) & 1);
  
  printf("\n");
}

int main(){
  char f = ~'f';
  char e = ~'e';
  char o = ~'o';
  
  showBites(&f);
  showBites(&e);
  showBites(&o);
  
  char a = (~f & ~e & ~o);
  showBites(&a);
  
  printf("%d", a);
  
}