#include <stdio.h>
#include <stdlib.h>

typedef struct Tnodo Tnodo;
typedef struct Tarista Tarista;
typedef Tnodo *NODO;
typedef Tarista *ARISTA;

typedef struct Tnodo{
  int valor;
  NODO sig;
  ARISTA adyacente;
}TNODO;

typedef struct Tarista{
  ARISTA sig;
  NODO des;
}TARISTA;

NODO newN(int valor);
ARISTA newA(NODO des);
void insertarN(NODO *nodo, int valor);
void insertarA(ARISTA *nodo, NODO des);
void insertarNA(NODO *nodo, NODO des, int valor);

void freeUA(NODO *nodo, int valor, int des);
void freeA(ARISTA *arista);
void freeN(NODO *nodo, NODO *ant, int valor);
//void freeR(NODO *nodo, int valor);

void printNodo(NODO nodo);
void printArista(ARISTA arista);
void printGrafo(NODO nodo);
NODO buscarN(NODO *nodo, int n);

int main(){
  NODO nodoPrincipal;
  nodoPrincipal = NULL;
  char opcion;
  char valor;
  char varol[10];
  
  while(opcion != '0'){
    system("pause");
    system("cls");
    puts("1.- inserte vertice");
    puts("2.- inserte arista");
    puts("3.- eliminar vertice");
    puts("4.- imprimir grafo");
    puts("Press 0 to exit");
    opcion = getc(stdin);
    fflush(stdin);
    switch(opcion){
      case '1':
        puts("Ingresa el valor:");
        insertarN(&nodoPrincipal, atoi(gets(varol)));
        fflush(stdin);
      break;
      case '2':
        puts("A que vertice lo deseas insertar?");
        valor = atoi(gets(varol));
        fflush(stdin);
        puts("Que quieres guardar?");
        insertarNA(&nodoPrincipal, buscarN(&nodoPrincipal, atoi(gets(varol))), valor);
        fflush(stdin);
      break;
      case '3':
        puts("Que vertice deseas borrar?");
        freeN(&nodoPrincipal, &nodoPrincipal, atoi(gets(varol)));
        fflush(stdin);
      break;
      case '4':
        printGrafo(nodoPrincipal);
      break;
    }
  }

}

NODO newN(int valor){
  NODO nodo = (NODO) malloc(sizeof(TNODO));
  if(!nodo)
    return NULL;
  
  nodo->valor = valor;
  nodo->sig = NULL;
  nodo->adyacente = NULL;
  
  return nodo;
}

ARISTA newA(NODO des){
  ARISTA arista = (ARISTA) malloc(sizeof(TARISTA));
  
  if(!arista)
    return NULL;
  
  arista->sig = NULL;
  arista->des = des;
  
  return arista;
}

void insertarN(NODO *nodo, int valor){
  if(*nodo == NULL){
    *nodo = newN(valor);
  }else{
    if((*nodo)->valor == valor){
      printf("El valor %d ya existe\n",valor);
      return;
    }
    
    insertarN(&(*nodo)->sig, valor);
  }
}

void insertarA(ARISTA *arista, NODO des){
  if(*arista == NULL){
    *arista = newA(des);
  }else{
    insertarA(&(*arista)->sig, des);
  }
}

void insertarNA(NODO *nodo, NODO des, int valor){
  if(*nodo != NULL){
    if((*nodo)->valor == valor){
      insertarA(&(*nodo)->adyacente, des);
    }else{
      insertarNA(&(*nodo)->sig, des, valor);
    }
  }
}

void freeUA(NODO *nodo,  int valor, int des){
  ARISTA aux = NULL;
  ARISTA ant = (*nodo)->adyacente;
  if(*nodo != NULL){
    if((*nodo)->valor == valor){
      while(ant != NULL){
        if((ant)->des->valor != valor)
          insertarA(&aux, buscarN(nodo, (ant)->des->valor));
        ant = ant->sig;
      }
      
      (*nodo)->adyacente = aux;
    }else{
      freeUA(&(*nodo)->sig, valor, des);
    }
  }
}

void freeA(ARISTA *arista){
  if(*arista == NULL){
    free(*arista);
  }else{
    freeA(&(*arista)->sig);
    free(*arista);
    *arista = NULL;
  }
}

void freeN(NODO *nodo, NODO *ant, int valor){
  NODO aux;
  if(*nodo != NULL){
    if((*nodo)->valor == valor){
      if(*nodo == *ant){
        aux = (*nodo)->sig;
        freeA(&(*nodo)->adyacente);
        free(*nodo);
        *nodo = aux;
      }else{
        aux = (*nodo)->sig;
        freeA(&(*nodo)->adyacente);
        free(*nodo);
        (*ant)->sig = aux;
      }
    }else{
      //freeUA(nodo, &(*nodo)->adyacente, &(*nodo)->adyacente, (*nodo)->valor, valor);
      freeN(&(*nodo)->sig, &(*nodo), valor);
    }
  }
}

void printNodo(NODO nodo){
  NODO aux;
  
  aux = nodo;
  
  while(aux != NULL){
    printf("%d\n",aux->valor);
    aux = aux->sig;
  }
}

void printArista(ARISTA arista){
  ARISTA aux;
  
  aux = arista;
  
  while(aux != NULL){
    if(aux->des != NULL){
      if(aux->des->valor > 0 && aux->des->valor < 1000)
        printf("|%4d",aux->des->valor);
      else
        printf("|NULL");
    }else{
      printf("|NULL");
    }
    
    aux = aux->sig;
  }
  
  puts("|");
}

void printGrafo(NODO nodo){
  while(nodo != NULL){
    printf("-> %-5d",nodo->valor);
    printArista(nodo->adyacente);
    nodo = nodo->sig;
  }
}

NODO buscarN(NODO *nodo, int v){
  if(*nodo == NULL){
    return NULL;
  }else{
    if((*nodo)->valor == v){
      return *nodo;
    }else{
      return buscarN(&(*nodo)->sig, v);
    }
  }
}