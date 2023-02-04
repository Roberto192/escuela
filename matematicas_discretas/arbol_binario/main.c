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
void imprimirArbol(nodoptr *, int, int, int, int);
int niveles(nodoptr *, int);
void imprimirArbolGraficamente(nodoptr *, int, int, int, DWORD);
nodoptr obtenerUltimoDato(nodoptr *);
void eliminar(nodoptr *, int);
int buscar(nodoptr *, int, int);
int menu();


int main(){
  nodoptr arbol = NULL;
  nodoptr aux;
  int salir = 1;
  int numero;
  
  srand(time(NULL));
  system("cls");
  
  while(salir){
    ponerColor(WHITE);
    salir = menu();
    fflush(stdin);
    
    switch(salir){
      case 1:
        puts("Ingrese el valor:");
        scanf("%d",&numero);
        agregarDato(&arbol, numero);
        break;
      case 2:
        system("cls");
        imprimirArbolGraficamente(&arbol, niveles(&arbol, 0), 50,0 ,RED);
        getchar();
        break;
      case 3: 
        puts("Ingrese el numero a eliminar:");
        scanf("%d",&numero);
        eliminar(&arbol, numero);
        system("pause");
        break;
      case 4:
        puts("Ingrese el valor a buscar:");
        scanf("%d",&numero);
        buscar(&arbol, numero, 0);
        system("pause");
        break;
      case 5: 
        imprimirArbol(&arbol, 0, 0, 0, 0);
        system("pause");
        break;
      case 6: 
        imprimirArbol(&arbol, 0, 0, 0, 1);
        system("pause");
        break;
      case 7: 
        imprimirArbol(&arbol, 0, 0, 0, 2);
        system("pause");
        break;
      case 8: 
        aux = arbol;
        free(aux);
        arbol = NULL;
        puts("Arbol borrado");
        system("pause");
        break;
      case 9: 
        salir = 0;
        break;
    }
  }
  
  system("pause");
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
    if((*nodo)->dato != dato){
      if((*nodo)->dato < dato){
        agregarDato(&(*nodo)->der, dato);
      }else{
        agregarDato(&(*nodo)->izq, dato);
      }
    }
  }
}

void imprimirArbol(nodoptr *nodo, int nivel, int lado, int x, int o){
    
  if(*nodo != NULL){
    if(o == 0){
      if(lado == 0){
        ponerColor(RED);
      }else if(lado == 1){
        ponerColor(GREEN);
      }else{
        ponerColor(BLUE);
      }

      printf("|%05d|", (*nodo)->dato);
      imprimirArbol(&(*nodo)->izq, nivel + 1, -1, x-4, o);
      imprimirArbol(&(*nodo)->der, nivel + 1, 1, x+4, o);
    }else{
      if(o == 1){
        imprimirArbol(&(*nodo)->izq, nivel + 1, -1, x-4, o);
        if(lado == 0){
          ponerColor(RED);
        }else if(lado == 1){
          ponerColor(GREEN);
        }else{
          ponerColor(BLUE);
        }
        printf("|%05d|",(*nodo)->dato);
        imprimirArbol(&(*nodo)->der, nivel + 1, 1, x+4, o);
      }else{
        imprimirArbol(&(*nodo)->izq, nivel + 1, -1, x-4, o);
        imprimirArbol(&(*nodo)->der, nivel + 1, 1, x+4, o);
        if(lado == 0){
          ponerColor(RED);
        }else if(lado == 1){
          ponerColor(GREEN);
        }else{
          ponerColor(BLUE);
        }

        printf("|%05d|",(*nodo)->dato);
      }
    }
  }
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
    
  char numero[10];
  int n;   
  ponerColor(color);
  if(*nodo != NULL){
  
    iraXY(x, y);
    printf("%d",(*nodo)->dato);
    n = snprintf(numero, 10, "%d",(*nodo)->dato);
    imprimirArbolGraficamente(&(*nodo)->izq, nivel - 1, x - n - nivel, y + 1, RED | GREEN);
    imprimirArbolGraficamente(&(*nodo)->der, nivel - 1, x + n + nivel, y + 1, GREEN);    
    
  }else{
    iraXY(x,y);
    putchar('x');
  }
}

int tieneDosHijos(nodoptr arbol){
  return (arbol->der != NULL && arbol->izq != NULL);
}

int noTieneHijos(nodoptr arbol){
  return (arbol->izq == NULL && arbol->der == NULL);
}

int tieneUnHijo(nodoptr arbol){
  if(arbol->izq != NULL)
    return -1;
  
  if(arbol->der != NULL)
    return 1;
  
  return 0;
}

nodoptr obtenerUltimoDato(nodoptr *arbol){
  nodoptr aux1, aux2, aux;
  if(*arbol != NULL){
    aux1 = obtenerUltimoDato(&(*arbol)->der);
    aux2 = obtenerUltimoDato(&(*arbol)->izq);
    
    if(aux1 == NULL && aux2 == NULL){
      aux = *arbol;
      *arbol = NULL;
      return aux;
    }else{
      if(aux1 == NULL && aux2 != NULL){
        return aux2;
      }else{
        return aux1;
      }
    }
  }
  
  return NULL;
}

void eliminar(nodoptr *arbol, int dato){
  int aux;
  nodoptr nodoAux;
  
  if(*arbol != NULL){
    if((*arbol)->dato == dato){
      if(tieneDosHijos(*arbol)){
        nodoAux = obtenerUltimoDato(&(*arbol)->izq);
        nodoAux->der = (*arbol)->der;
        nodoAux->izq = (*arbol)->izq;
        free(*arbol);
        *arbol = nodoAux;
        puts("Nodo eliminado");
      }else{
        aux = tieneUnHijo(*arbol);
        if(aux == 1){
          nodoAux = (*arbol)->der;
          free(*arbol);
          *arbol = nodoAux;
          puts("Nodo eliminado");
        }else{
          if(aux == -1){
            nodoAux = (*arbol)->izq;
            free(*arbol);
            *arbol = nodoAux;
            puts("Nodo eliminado");
          }else{
            free(*arbol);
            *arbol = NULL;
            puts("Nodo eliminado");
          }
        }
      }
    }else{
      if((*arbol)->dato > dato){
        eliminar(&(*arbol)->izq, dato);
      }else{
        eliminar(&(*arbol)->der, dato);
      }
    }  
  }
}

int buscar(nodoptr *arbol, int dato, int nivel){
  int datoEnArbol;
  int res;
  
  if(*arbol == NULL){
    return 0;
  }else{
    datoEnArbol = (*arbol)->dato;
    if(datoEnArbol == dato){
      printf("Encontrado en %d -> %d\n", nivel,datoEnArbol);
      return 1;
    }else{
      if(datoEnArbol > dato){
        res = buscar(&(*arbol)->izq, dato, nivel+1);
      }else{
        res = buscar(&(*arbol)->der, dato, nivel+1);
      }
    }
  }
  
  return res;
}

int menu(){
  system("cls");
  puts("1.- Insertar nuevo nodo");
  puts("2.- Mostrar arbol completo");
  puts("3.- Borrar un nodo");
  puts("4.- Buscar elemento del arbol");
  puts("5.- Recorrer PreOrden");
  puts("6.- Recorrer InOrden");
  puts("7.- Recorrer PosOrden");
  puts("8.- Eliminar todo el arbol");
  puts("9.- Salir");
  
  return getchar() - '0';
}