#include "milib.h"
#include "validar.h"
#include "rosaak.h"
#include <stdio.h>

#define MAX 3500

void agregarA(Talumno alumnos[], int tam, int i, int j);
void eliminar(Talumno alumnos[], int tam, int grado);
void cargarArchivo(Talumno alumnos[], int *n, int *grado, logico binario);

int main(){
  
  int opcion = 1;
  Talumno alumnos[MAX] = {0};
  int n = 0;
  int grado = DESORDENADO;
  logico cargado = FALSE;
  
  while((opcion = menu())){
    printf("%d\n",n);
    switch(opcion){
      case 1:
        agregarA(alumnos, MAX, n,  n + 300);
        if(n<=MAX){
          n += 300;
          if(grado == ORDENADO){
            grado = SEMIORDENADO;
          }else{
            grado = DESORDENADO;
          }
        }
        break;
      case 2:
        insertarDatos(alumnos, n);
        n++;
        if(grado == ORDENADO){
          grado = SEMIORDENADO;
        }
        break;
      case 3:
        if(validarNumeroICR("Seguro que quieres eliminar un alumno? (1:SI/ 0:NO)", "Ingrese un valor correcto", 1, 0, 1))
          eliminar(alumnos, n, grado);
        break;
      case 4:
        busqueda(alumnos, n, DESORDENADO);
        break;
      case 5:
        
        if(cargado){
          if(grado != ORDENADO){
            ordenarBurbuja(alumnos, n);
            grado = ORDENADO;
            puts("Se ordenaron los datos");
          }
        }
        ordenar(alumnos, n, &grado);
        
        break;
      case 6:
        imprimirTabla(alumnos, n);
        break;
      case 7:
        generarArchivo(alumnos, n, FALSE);
        break;
      case 8:
        cargarArchivo(NULL, NULL, NULL, FALSE);
        break;
      case 9:
        generarArchivo(alumnos, n, TRUE);
        break;
      case 10:
        cargarArchivo(alumnos, &n, &grado, TRUE);
        cargado = TRUE;
        break;
    }
    
    system("pause");
  }
  
  return 0;
}

void agregarA(Talumno alumnos[], int tam, int i, int j){
  if(j <= tam){
    if(j > i){
      if(i >= 0){
         for(;i < j; i++)
          agregarAleatorio(&alumnos[i]); 
      }
    }
  }
}

void eliminar(Talumno alumnos[], int tam, int grado){
  long matricula;
  
  imprimirTabla(alumnos, tam);
  system("pause");

  if(grado == ORDENADO){
    matricula = validarNumeroLCR("Ingrese el numero de matricula que desea eliminar: ", "Ingrese un numero de matricula valido", 1, alumnos[0].matricula, alumnos[tam-1].matricula);
    alumnos[busquedaBinariaRecursiva(alumnos, matricula, 0, tam)].estado = FALSE;
  }else{
    matricula = validarNumeroLCR("Ingrese el numero de matricula que desea eliminar: ", "Ingrese un numero de matricula valido", 1, 11111, 9999999);
    alumnos[busquedaSecuencial(alumnos, matricula, 0, tam)].estado = FALSE;
  }
  
  printf("Alumno eliminado satisfactoriamente\n");
}

void cargarArchivo(Talumno alumnos[], int *n, int *grado, logico binario){
  FILE *archivo;
  Tnombre nombre;
  
  validarTexto("Ingrese el nombre del archivo a cargar: ", nombre, MAX_NOMBRE, 2);
  
  if(binario){
    strcat(nombre, ".dat");
    archivo = fopen(nombre, "rb");
    
    if(archivo == NULL){
      fprintf(stderr, "Error al abrir el archivo, no existe o alguna aplicacion esta usando el archivo\n");
    }else{
      *n = (int) fread(alumnos, sizeof(struct _talumno), MAX, archivo);
      *grado = ORDENADO;
    }
  }else{
    strcat(nombre, ".txt");
    archivo = fopen(nombre, "r");
    
    if(archivo == NULL){
      fprintf(stderr, "Error al abrir el archivo, no existe o alguna aplicacion esta usando el archivo\n");
    }else{
      while(!feof(archivo))
        putchar(getc(archivo));
    }
    
  }
  
  fclose(archivo);
}