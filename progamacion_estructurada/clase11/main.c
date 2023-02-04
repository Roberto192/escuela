#include <stddef.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "milib.h"
#include "CURPC.h"
#include "validar.h"

#define MAX_ALUMNOS 2000

#define ORDENADO 1
#define DESORDENADO 2
#define SEMIDESORDENADO 3

typedef struct _TSDDN{
  TSfecha fecha;
  int lugarDeNacimiento;
}TSDDN;//Tipo de datos de nacimiento

typedef struct _TalumnoDDC{
  char curp[MAX_CURP];
  Talumno alumno;
  TSDDN datosDeNacimiento;
  
}TalumnoDDC;

void agregarDDN(TalumnoDDC *);
void imprimirDatosCompletos(TalumnoDDC [], int , int, int);
void agregarAlumnosAleatorio(TalumnoDDC [], int, int, int);
void ordenarBurbuja(TalumnoDDC [], int, int);
int busquedaBinariaRecursiva(TalumnoDDC [], long, char [] , int , int, int );
void busqueda(TalumnoDDC [], int , int );
int qckSort(TalumnoDDC [], int , int , int );
void ordenarQuickSort(TalumnoDDC [], int, int );
void ordenar(TalumnoDDC [], int, int, int *);
void agregar(TalumnoDDC [], int, int *, int *);

int main(){

  TalumnoDDC alumnos[MAX_ALUMNOS];
  int centinela = 1;
  int n = 0;
  int pos;
  int ordenadoPorMatricula = FALSE, ordenadoPorCURP = FALSE;
  int grado = DESORDENADO;
  long matricula;
  srand(time(NULL));
  
  //agregarAlumnosAleatorio(alumnos, MAX_ALUMNOS, 0, 100);
  
  while(centinela){
    centinela = menu();
    
    switch(centinela){
      case 1: 
        agregar(alumnos, MAX_ALUMNOS, &n, &grado);
        system("pause");
        break;
      case 2: 
        busqueda(alumnos, n, FALSE);
        system("pause");
      break;
      case 3: 
        busqueda(alumnos, n, TRUE);
        system("pause");
        break;
      case 4:
        if(ordenadoPorCURP){
          grado = SEMIDESORDENADO;
          ordenadoPorCURP = FALSE;
        }
        ordenar(alumnos, n, 1, &grado);
        ordenadoPorMatricula = TRUE;
        system("pause");
        break;
      case 5:
        if(ordenadoPorMatricula){
          grado = SEMIDESORDENADO;
          ordenadoPorMatricula = FALSE;
        }
        ordenar(alumnos, n, 0, &grado);
        ordenadoPorCURP = TRUE;
        system("pause");
        break;
      case 6: 
        imprimirDatosCompletos(alumnos, MAX_ALUMNOS, 0, n);
        system("pause");        
        break;
      case 7: centinela = 0; break;
    }
    
  }
  
  //imprimirDatosCompletos(alumnos, MAX_ALUMNOS, 0, 100);
  
  return 0;
}

void agregarDDN(TalumnoDDC *alumno){
  TSfecha fecha;
  
  if(alumno->alumno.estado == TRUE){
    fecha.a = 2022 - alumno->alumno.edad;
    fecha.m = 12;
    fecha.d = 31;
    alumno->datosDeNacimiento.fecha = obtenerFechaAleatoria(fecha);
    alumno->datosDeNacimiento.lugarDeNacimiento = (rand() % 33) + 1;
  }
  
}

void imprimirDatosCompletos(TalumnoDDC alumnos[], int tam, int r1, int r2){
  
  char fecha[MAX_DATE];
  int i = r1;
  char estadosDe2Caracteres[33][3] = {
    "AS",
    "BC",
    "BS",
    "CC",
    "CL",
    "CM",
    "CS",
    "CH",
    "DF",
    "DG",
    "GT",
    "GR",
    "HG",
    "JC",
    "MC",
    "MN",
    "MS",
    "NT",
    "NL",
    "OC",
    "PL",
    "QT",
    "QR",
    "SP",
    "SL",
    "SR",
    "TC",
    "TS",
    "TL",
    "VZ",
    "YN",
    "ZS",
    "NE"
  };  
  if(r2 <= tam){
    printf("No\tMatricula\tNombre\t\t\t\tEstado\tCURP\n");
    while(i < r2){
      if(alumnos[i].alumno.estado == TRUE){
        printf("[%04d] | %010lu | %20s %20s %20s | %2s | %19s\n", i, alumnos[i].alumno.matricula, alumnos[i].alumno.nombre, alumnos[i].alumno.apellido_p, alumnos[i].alumno.apellido_m, estadosDe2Caracteres[alumnos[i].datosDeNacimiento.lugarDeNacimiento - 1], alumnos[i].curp);
        i++;
      }
      if(i % 40 == 0){
        system("pause");
        system("cls");
        printf("No\tMatricula\tNombre\tEstado\n");
      }
    }
  }
}

void agregarAlumnosAleatorio(TalumnoDDC alumnos[], int tam, int r1, int r2){
  int i;
  char anio[5];
  char mes[3];
  char dia[3];
  
  char sexo[3] = "HM";
  
  char estadosDe2Caracteres[33][3] = {
    "AS",
    "BC",
    "BS",
    "CC",
    "CL",
    "CM",
    "CS",
    "CH",
    "DF",
    "DG",
    "GT",
    "GR",
    "HG",
    "JC",
    "MC",
    "MN",
    "MS",
    "NT",
    "NL",
    "OC",
    "PL",
    "QT",
    "QR",
    "SP",
    "SL",
    "SR",
    "TC",
    "TS",
    "TL",
    "VZ",
    "YN",
    "ZS",
    "NE"
  };
  
  if(r2 <= tam){
    for(i = r1; i < r2; i++){
      agregarAleatorio(&alumnos[i].alumno);
      agregarDDN(&alumnos[i]);
      
      obtenerAnio(anio, 5, alumnos[i].datosDeNacimiento.fecha);
      obtenerMes(mes, 3, alumnos[i].datosDeNacimiento.fecha);
      obtenerDia(dia, 3, alumnos[i].datosDeNacimiento.fecha);
      
      crearCurp(alumnos[i].curp, alumnos[i].alumno.nombre, alumnos[i].alumno.apellido_p, alumnos[i].alumno.apellido_m, anio, mes, dia, estadosDe2Caracteres[alumnos[i].datosDeNacimiento.lugarDeNacimiento - 1], sexo[alumnos[i].alumno.sexo - 1]);
    }    
  }
}

void ordenarBurbuja(TalumnoDDC alumnos[], int tam, int t){
  int i, j;
  TalumnoDDC alumno;
    
  if(t == 1){
    for(i = 0; i < tam; i++){
      for(j = 0; j < tam - 1; j++){
        if(alumnos[j].alumno.matricula > alumnos[j + 1].alumno.matricula){
          alumno = alumnos[j];
          alumnos[j] = alumnos[j + 1];
          alumnos[j + 1] = alumno;
        }
      }
    }
  }else{
    
    for(i = 0; i < tam; i++){
      for(j = 0; j < tam - 1; j++){
        if(strcoll(alumnos[j].curp, alumnos[j + 1].curp) > 0){
          alumno = alumnos[j];
          alumnos[j] = alumnos[j + 1];
          alumnos[j + 1] = alumno;
        }
      }
    }
      
  }   
}

int busquedaBinariaRecursiva(TalumnoDDC alumnos[], long matricula, char curp[], int izquierda, int derecha, int i){
    
  int indiceDeLaMitad;
  
    if(i == 1){
      if (izquierda > derecha) return -1;
 
      indiceDeLaMitad = (izquierda + derecha) / 2;
 
      long valorQueEstaEnElMedio = alumnos[indiceDeLaMitad].alumno.matricula;
      if (matricula == valorQueEstaEnElMedio){
          return indiceDeLaMitad;
      }
      
      if (matricula < valorQueEstaEnElMedio){
          derecha = indiceDeLaMitad - 1;
      }else{
          izquierda = indiceDeLaMitad + 1;
      }
      return busquedaBinariaRecursiva(alumnos, matricula, NULL, izquierda, derecha, i);
    }else{
      if (izquierda > derecha) return -1;
 
      indiceDeLaMitad = (izquierda + derecha) / 2;
      char valorQueEstaEnElMedio[MAX_CURP]; 
    
      strcpy(valorQueEstaEnElMedio, alumnos[indiceDeLaMitad].curp);
      if (strcmp(valorQueEstaEnElMedio, curp)){
          return indiceDeLaMitad;
      }
      
      if (strcoll(curp, valorQueEstaEnElMedio) < 0){
          derecha = indiceDeLaMitad - 1;
      }else{
          izquierda = indiceDeLaMitad + 1;
      }
      return busquedaBinariaRecursiva(alumnos, matricula, curp, izquierda, derecha, i);
    }
}

void busqueda(TalumnoDDC alumnos[], int n, int ordenadoMatricula){
  long matricula;
  int pos;
  char CURP[MAX_CURP];
  
  if(ordenadoMatricula){
    matricula = validarNumeroLCR("Ingrese la matricula a buscar: ", "Ingrese una matricula correcta", 1, 9999, 9999999);
    pos = busquedaBinariaRecursiva(alumnos, matricula, NULL, 0, n, 1);
    if(pos != -1){
      imprimirReg(alumnos[pos].alumno);
      printf("CURP: %s",alumnos[pos].curp);
    }else{
      printf("No existe\n");
    }
  }else{
    fflush(stdin);
    scanf("%s",CURP);
    pos = busquedaBinariaRecursiva(alumnos, 0, CURP, 0, n, 1);
    if(pos != -1){
      
      imprimirReg(alumnos[pos].alumno);
      printf("CURP: %s",alumnos[pos].curp);
    }else{
      printf("No exite\n");
    }
  }
  printf("\n");
}

int qckSort(TalumnoDDC alumnos[], int tipo, int izq, int der){
  if(izq >= der){
    return 0;
  }
  
  TalumnoDDC pivote = alumnos[izq], temp;  
  int i = izq+1;
  int d = der;
  
  if(tipo){
    while(i <= d){
      while(alumnos[i].alumno.matricula < pivote.alumno.matricula){
        i++;
      }
      
      while(alumnos[d].alumno.matricula > pivote.alumno.matricula){
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
  }else{
    
    while(i <= d){
      while(strcoll(alumnos[i].curp, pivote.curp) < 0){
        i++;
      }
      
      while(strcoll(alumnos[d].curp,pivote.curp) > 0){
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
  }
  
  if(d>izq){
    temp = alumnos[izq];
    alumnos[izq] = alumnos[d];
    alumnos[d] = temp;
  }
  
  qckSort(alumnos, tipo, izq, d-1);
  qckSort(alumnos, tipo, d+1,der);

}

void ordenarQuickSort(TalumnoDDC alumnos[], int n, int tipo){
  if(tipo){
    qckSort(alumnos, tipo, 0, n-1);
  }else{
    qckSort(alumnos, 0, 0, n-1);
  }
}

void ordenar(TalumnoDDC alumnos[], int tam, int tipo, int *grado){
  if(tam != 0){
    if(*grado == DESORDENADO){
      ordenarQuickSort(alumnos, tam, tipo);
      printf("Se ordeno con Quick sort\n");
    }else{
      if(*grado == SEMIDESORDENADO){
        ordenarBurbuja(alumnos, tam, tipo);
        printf("Se ordeno con Bubble sort\n");
      }
    }
    
    *grado = ORDENADO;
  }
}

void agregar(TalumnoDDC alumnos[], int tamMAX, int *n, int *grado){
  agregarAlumnosAleatorio(alumnos, tamMAX, *n, *n+100);        
  if(*n < MAX_ALUMNOS){
    *n += 100;
    if(*grado == ORDENADO){
      *grado = SEMIDESORDENADO;
    }else{
      *grado = DESORDENADO;
    }
  }else{
    printf("Se a llenado la maxima cantidad de alumnos\n");
    *n = MAX_ALUMNOS;
  }
}