// Clase 12
// Manejo de archivos
// Nombre: Roberto Isaac Arias Guerrero    Matricula: 1292118
// Fecha: 06/11/2022

#include <stdio.h>
#include <string.h>
#include "milib.h"
#include "rosaak.h"
#include "validar.h"

#define MAX 1500
#define EXT ".txt"

#define ORDENADO 1
#define SEMIORDENADO 2
#define DESORDENADO 3

int cargarArchivo();
int agregarAleatorioDesde(Talumno [], int, int, int);
void imprimirTabla(Talumno [], int);
int generarArchivo(Talumno [], int, int, char [], int);
void ordenarBurbuja(Talumno alumnos[], int tam);
int busquedaBinariaRecursiva(Talumno alumnos[], long matricula, int izquierda, int derecha);
int busquedaSecuencial(Talumno alumnos[], unsigned long matricula, int x, int y);
void busqueda(Talumno alumnos[], int n, int grado);
int qckSort(Talumno alumnos[], int izq, int der);
void ordenarQuickSort(Talumno alumnos[], int n);
void ordenar(Talumno alumnos[], int tam, int *grado);

int main(){
  Talumno alumnos[MAX];
  int opcion = 1;
  int grado = DESORDENADO;
  logico archivoCargado = FALSE;
  int posIndex = 0;
  int Errors;
  
  while(opcion){
    opcion = menu();
    
    switch(opcion){
      case 1: 
        if(!archivoCargado){
          posIndex = generarArchivo(alumnos, 0, 0, "r", 0) - 1;
          archivoCargado = TRUE;
        }
        system("pause");
        break;
      case 2:
        
        if(posIndex < MAX){
          posIndex += 10;
          if(grado == ORDENADO){
            grado = SEMIORDENADO;
          }
          Errors = agregarAleatorioDesde(alumnos, posIndex - 10, posIndex, MAX);
          printf("Se agregado 10 alumnos nuevos... %d\n",posIndex);
        }else{
          posIndex = MAX;
        }
        
        system("pause");
        break;
      case 3: 
        busqueda(alumnos, posIndex, grado);
        system("pause");
        break;
      case 4: 
        ordenar(alumnos, posIndex, &grado);
        system("pause");
        break;
      case 5: 
        imprimirTabla(alumnos, posIndex);
        system("pause");
        break;
      case 6: 
        generarArchivo(alumnos, posIndex, 1, "w", 0);
        break;
      case 0:
        generarArchivo(alumnos, posIndex, 1, "w", 1);
        printf("Seguro que quieres salir (0:SI / 1:no)\n");
        opcion = leerEnteroPositivo();
        break;
    }
  }
  
  return 0;
}

/*
Alumnos -> indica el arreglo de tipo alumnos
i -> indica desde donde se insertaran los datos
f -> indica el final del arreglo
tam -> indica la cantidad max del arreglo i < f && f <= tam
*/
int agregarAleatorioDesde(Talumno alumnos[], int i, int f, int tam){
  if(i < 0){
    return 0;
  }
  
  if(f < 0){
    return -5;
  }
  
  if(tam < 0){
    return -6;
  }
  
  if(alumnos == NULL){
    return 0;
  }
  
  if(i > f){
    return -1;
  }
  
  if(i > tam){
    return -3;
  }
  
  if(f >= tam){
    return -2;
  }
  
  if(i == f){
    return f;
  }
  
  for(;i < f;i++){
    agregarAleatorio(&alumnos[i]);
  }
  
  return f;
}

void imprimirTabla(Talumno alumnos[], int tam){
  int i;
  
  if(tam <= 0){
    printf("Registros vacios\n");
  }else{
    for(i = 0; i < tam; i++){
      if(alumnos[i].estado == TRUE){
        printf("%04d %010lu %20s %20s %20s %d\n", i, alumnos[i].matricula, alumnos[i].nombre, alumnos[i].apellido_p, alumnos[i].apellido_m, alumnos[i].sexo);
      }
    }
  }
}

int generarArchivo(Talumno alumnos[], int n, int tipo, char modo[], int m){
  FILE *archivo;
  char nombreArchivo[40];
  char sexo[15];
  int i = 0 , j;
  int salir = 1;
  if(m){
    strcpy(nombreArchivo, "AutoGuardado.txt");
  }else{
    
    validarTexto("Ingrese el nombre del archivo: ", nombreArchivo, 40, 2);
    strcat(nombreArchivo, ".txt");
  
  }
  
  archivo = fopen(nombreArchivo, modo);
  
  if(archivo != NULL){
  
    while(salir){
      
      if(tipo){
        if(alumnos[i].sexo == 2){
          strcpy(sexo, "MUJER");
        }else{
          strcpy(sexo, "HOMBRE");
        }
        if(alumnos[i].estado == TRUE){
          fprintf(archivo, "%04d %010lu %20s %20s %20s %3d %s\n", i, alumnos[i].matricula, alumnos[i].nombre, alumnos[i].apellido_p, alumnos[i].apellido_m, alumnos[i].edad, sexo);
        }
        i++;
        
        if(i > n){
          salir = 0;
        }

      }else{
        fscanf(archivo, "%d %lu %s %s %s %d %s",&j,&alumnos[i].matricula, alumnos[i].nombre, alumnos[i].apellido_p, alumnos[i].apellido_m,&alumnos[i].edad, sexo);
        if(strcmp(sexo, "MUJER") == 0){
          alumnos[i].sexo = 2;
        }else{
          alumnos[i].sexo = 1;
        }
        
        alumnos[i].estado = (alumnos[i].matricula != 0);
        
        if(getc(archivo) == EOF){
          salir = 0;
        }
        
        i++;
        
      }
      
    }
  
  }else{
    if(tipo){
      puts("No se pudo crear el archivo");
    }else{
      puts("No se encontro el archivo");
    }
  }
  
  fclose(archivo);
  
  return i;
}

void ordenarBurbuja(Talumno alumnos[], int tam){
  int i, j;
  Talumno alumno;

  for(i = 0; i < tam; i++){
    for(j = 0; j < tam - 1; j++){
      if(alumnos[j].matricula > alumnos[j + 1].matricula){
        alumno = alumnos[j];
        alumnos[j] = alumnos[j + 1];
        alumnos[j + 1] = alumno;
      }
    }
  }
}

int busquedaBinariaRecursiva(Talumno alumnos[], long matricula, int izquierda, int derecha){

  int indiceDeLaMitad;

    
      if (izquierda > derecha) return -1;

      indiceDeLaMitad = (izquierda + derecha) / 2;

      long valorQueEstaEnElMedio = alumnos[indiceDeLaMitad].matricula;
      if (matricula == valorQueEstaEnElMedio){
          return indiceDeLaMitad;
      }

      if (matricula < valorQueEstaEnElMedio){
          derecha = indiceDeLaMitad - 1;
      }else{
          izquierda = indiceDeLaMitad + 1;
      }
      return busquedaBinariaRecursiva(alumnos, matricula, izquierda, derecha);
   
}

int busquedaSecuencial(Talumno alumnos[], unsigned long matricula, int x, int y){
  int i;
  
  for(i = x; i < y; i++){
    if(alumnos[i].matricula == matricula){
      return i;
    }
  }
  
  return -1;
}

void busqueda(Talumno alumnos[], int n, int grado){
  long matricula;
  int pos;
  
    matricula = validarNumeroLCR("Ingrese la matricula a buscar: ", "Ingrese una matricula correcta", 1, 9999, 9999999);
    if(grado == ORDENADO || grado == SEMIORDENADO){
      pos = busquedaBinariaRecursiva(alumnos, matricula, 0, n);
    }else{
      pos = busquedaSecuencial(alumnos, matricula, 0, n);
    }
    if(pos != -1){
      imprimirReg(alumnos[pos]);
    }else{
      printf("No existe\n");
    }
  printf("\n");
}

int qckSort(Talumno alumnos[], int izq, int der){
  if(izq >= der){
    return 0;
  }

  Talumno pivote = alumnos[izq], temp;
  int i = izq+1;
  int d = der;
  
  while(i <= d){
    while(alumnos[i].matricula < pivote.matricula){
      i++;
    }

    while(alumnos[d].matricula > pivote.matricula){
      d--;
    }

    if(i < d){
      temp = alumnos[d];

      alumnos[d] = alumnos[i];
      alumnos[i] = temp;
      i++;
      d--;
    }
  }

  if(d>izq){
    temp = alumnos[izq];
    alumnos[izq] = alumnos[d];
    alumnos[d] = temp;
  }

  qckSort(alumnos, izq, d-1);
  qckSort(alumnos, d+1,der);
  
  return 1;
}

void ordenarQuickSort(Talumno alumnos[], int n){
    qckSort(alumnos, 0, n-1);
}

void ordenar(Talumno alumnos[], int tam, int *grado){
  if(tam != 0){
    if(*grado == DESORDENADO){
      ordenarQuickSort(alumnos, tam);
      printf("Se ordeno con Quick sort\n");
    }else{
      if(*grado == SEMIORDENADO){
        ordenarBurbuja(alumnos, tam);
        printf("Se ordeno con Bubble sort\n");
      }
    }

    *grado = ORDENADO;
  }
}