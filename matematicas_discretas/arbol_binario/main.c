#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arbol_binario.h"
#include "ventanas.h"

#define GREEN FOREGROUND_GREEN
#define RED FOREGROUND_RED
#define BLUE FOREGROUND_BLUE
#define WHITE GREEN | BLUE | RED

nodoptr crearNodo(int);
void agregarDato(nodoptr *, int);
void imprimirArbol(nodoptr *, int, int, int);
int niveles(nodoptr *, int);
void imprimirArbolGraficamente(nodoptr *, int, int, int, DWORD);

int main(){
  nodoptr arbol = NULL;
  int salir = 0;
  int numero;
  
  srand(time(NULL));
  system("cls");
  while(salir < 10){
    numero = (rand() % 26) + 'a';
    agregarDato(&arbol, numero);
    salir++;
  }
  
  imprimirArbolGraficamente(&arbol, niveles(&arbol, 0) + 1, 40, 0, FOREGROUND_INTENSITY);
  
  iraXY(0, 20);
  ponerColor(WHITE);
  free(arbol);
}

nodoptr crearNodo(int dato){
  nodoptr nuevoNodo = (nodoptr) malloc(sizeof(nodo));
  
  if(nuevoNodo != NULL){
    nuevoNodo->dato = dato;
    nuevoNodo->der = nuevoNodo->izq = NULL;
  }  
  
  return nuevoNodo;
}

void agregarDato(nodoptr *nodo, int dato){
  if(*nodo == NULL){
    *nodo = crearNodo(dato);
  }else{
    if((*nodo)->dato < dato){
      agregarDato(&(*nodo)->der, dato);
    }else{
      agregarDato(&(*nodo)->izq, dato);
    }
  }
}

void imprimirArbol(nodoptr *nodo, int nivel, int lado, int x){
  
  if(lado == 0){
    printf("Raiz");
  }else if(lado < 0){
    printf("Izq");
  }else{
    printf("Der");
  }
  
  if(*nodo == NULL){
    printf(":%d->%d %c\n",nivel, x, '0'); 
  }else{
    printf(":%d->%d %c\n",nivel, x, (*nodo)->dato);
    imprimirArbol(&(*nodo)->izq, nivel + 1, -1, x-4);
    imprimirArbol(&(*nodo)->der, nivel + 1, 1, x+4);
  }
  Sleep(200);
}

int niveles(nodoptr *nodo, int n){
  int auxi, auxd;
  
  if(*nodo != NULL){
    auxi = niveles(&(*nodo)->izq, n+1);
    auxd = niveles(&(*nodo)->der, n+1);
    
    if(auxi > n){
      n = auxi;
    }
    
    if(auxd > n){
      n = auxd;
    }
  }
  
  return n;
}

void imprimirArbolGraficamente(nodoptr *nodo, int nivel, int x, int y, DWORD color){
  int n;
  iraXY(x,y);
  
  ponerColor(color);
  n = rand() % 6 + 1;
  
  if(n == 1){
    color |= GREEN;
  }else{
    if(n == 2){
      color |= RED;
    }else{
      if(n == 3){
        color |= BLUE;
      }else{
        if(n == 4){
          color = RED;
        }else{
          if(n == 5){
            color = GREEN;
          }else{
            color = BLUE;
          }
        }
      }
    }
  }
  
  if(*nodo != NULL){
    putchar((*nodo)->dato);
    imprimirArbolGraficamente(&(*nodo)->izq, nivel - 1, x - nivel, y + 1, color);
    imprimirArbolGraficamente(&(*nodo)->der, nivel - 1, x + nivel, y + 1, color);
  }else{
    putchar('0');
  }
}