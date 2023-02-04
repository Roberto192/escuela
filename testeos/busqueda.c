#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int busquedaBinaria(int arreglo[], int l, int r, int numeroBuscado);
int comp(const void *n1, const void *n2);
int compM(const void *n1, const void *n2);

typedef struct _tindex{
  int index;
  long matricula;
}Tindex;

int main(){
  int unArreglo[100];
  Tindex unIndexArreglo[100];
  int i, j, k, aux;
  j = 0;
  k = 1;
  srand(time(NULL));
  
  for(i = 0; i < 100; i++){
    unIndexArreglo[i].matricula = rand()% (1000 - i);
    unIndexArreglo[i].index = i;
  }
  for(i = 0; i < 100; i++)
    printf("%d -> %lu\n", i, unIndexArreglo[i].matricula);
  
  printf("\n\n\nOrdenado\n\n\n"); 
  qsort(unArreglo, 100, sizeof(struct _tindex), compM);

  for(i = 0; i < 100; i++)
    printf("%d -> %lu\n", unIndexArreglo[i].index, unIndexArreglo[i].matricula);
  
  
  //printf("%d\n",busquedaBinaria(unArreglo, 0, 100, aux));
  
  return 0;
}

int busquedaBinaria(int arreglo[], int l, int r, int numeroBuscado){

  int mid;
  if(r >= l){
    mid = l + (r - l) / 2;
    if(arreglo[mid] == numeroBuscado){
      return mid;
    }
    
    if(arreglo[mid] > numeroBuscado){
      return busquedaBinaria(arreglo, l, mid - 1, numeroBuscado);
    }
    
    return busquedaBinaria(arreglo, mid + 1, r, numeroBuscado);
  }
  
  return -1;
}

int comp(const void *n1, const void *n2){
  int *nl, *nr;
  
  nl = (int *) n1;
  nr = (int *) n2;
  
  return (*nl - *nr);
}

int compM(const void *n1, const void *n2){
  Tindex *i1, *i2;
  long m1, m2;
  
  i1 = (Tindex *) n1;
  i2 = (Tindex *) n2;
  
  m1 = i1->matricula;
  m2 = i2->matricula;
  
  return (m1 - m2);
}