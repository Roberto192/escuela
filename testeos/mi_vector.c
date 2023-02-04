#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 100

typedef struct _tdatos{
  int indice;
  int valor;
  char nombreDato[MAX];
  int cantidad;
}Tdatos;

void mostrarDatos(Tdatos *dato);
void* regresaCualquierMierda(void *mierda, int tam, int pos);

int main(){
  
  Tdatos datos[MAX];
  char buff1[MAX];
  char buff2[MAX];
  
  srand(time(NULL));
  
  for(int i = 0; i < MAX; i++){
    datos[i].indice = i;
    datos[i].valor = (rand() % 100);
    datos[i].cantidad = (rand() % 50);
    _itoa_s(i + 1, buff1, MAX, 10);
    strcpy_s(buff2, MAX, "Prueba \0");
    strcat_s(buff2, MAX, buff1);
    strcpy_s(datos[i].nombreDato, MAX, buff2);
    mostrarDatos(regresaCualquierMierda(datos, sizeof(Tdatos), i));
  }
  
  char *c = regresaCualquierMierda(buff2, 1, 2);
  printf("\n -> %c\n", *c);
}

void mostrarDatos(Tdatos *dato){
  printf("->Indice %d\n", dato->indice);
  printf("Nombre datos -> : %s\n", dato->nombreDato);
  printf("Valor producto -> : %d\n", dato->valor);
  printf("Cantidad Datos -> : %d\n", dato->cantidad);
  printf("->Fin\n");
}

void* regresaCualquierMierda(void *mierda, int tam, int pos){
  char *dato = (char *) mierda;
  int i;
  
  for(i = 0; i < pos * tam; i++){
    dato++;
  }
  
  return dato;
}