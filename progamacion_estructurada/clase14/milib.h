#pragma once
#include <stdio.h>
#include <string.h>
#include "validar.h"
#include "rosaak.h"

#define TRUE 1
#define FALSE 0
#define ORDENADO 1
#define SEMIORDENADO 2
#define DESORDENADO 3

#define MAX_NOMBRE 40
#define MAX_APELLIDO 30

#define BUSCAR 1
#define BORRAR 2

typedef int logico;
typedef char Tnombre[MAX_NOMBRE];
typedef char Tapellido[MAX_APELLIDO];

typedef struct _talumno{
  long matricula;
  Tnombre nombre;
  Tapellido apellido_p;
  Tapellido apellido_m;
  int edad;
  int sexo;
  logico estado;
}Talumno;


typedef struct _tindex{
  long matricula;
  int index;
}Tindex;

int cargarDatos(Tindex index[], int max, char nombreArchivo[]){
  FILE *archivo;
  Talumno *alumnos;
  int i, j;
  
  archivo = fopen(nombreArchivo, "rb");
  if(archivo){
    alumnos = (Talumno *) malloc(sizeof(Talumno) * max);
    if(alumnos){
      for(i = j = 0; !feof(archivo);i++){
        
        fseek(archivo, sizeof(Talumno) * i, SEEK_SET);
        fread(&alumnos[i], sizeof(Talumno), 1, archivo);
        
        if(alumnos[i].estado){
          index[j].matricula = alumnos[i].matricula;
          index[j].index = i;
          j++;
        }
      }
    }
    
    fclose(archivo);
  }
  
  return j;
}

int menu(){
  
  system("cls");
  
  char men[7][30] = {
    "Agregar",
    "Eliminar registro",
    "Buscar",
    "Ordenar",
    "Mostrar",
    "Generar Archivo Texto",
    "Empaquetar"
  };
  
  int i;
  
  printf("Menu\n");
  
  for(i = 0; i < 7; i++){
    printf("%d.- %s\n",i+1,men[i]);
  }
  
  printf("0.- Salir\n");
  
  return leerEntero();  
}

void agregarAleatorio(Talumno *alumno){
  Tnombre nombresM[15] = {"LUZ", "GUADALUPE", "VALENTINA", "ASUCENA", "VALERIA", "TRINIDAD", "JUANA", "VALENTINA", "SOPHIA", "MIA", "MAYDA", "LILIANA", "MONSERRAT", "SUSANA", "MARIA"};
  Tnombre nombresH[15] = {"XINA", "ROBERTO", "MUSK", "JOSE", "VICTOR", "HUGO", "JESUS", "HAZAEL", "AZAEL", "TERIYAKI", "JUAN", "ADOLFO", "MARADONA", "PITER", "ARIEL"};
  Tapellido apellidos[15] = {"LOPEZ", "KIM", "RAMIREZ", "TARANTINO", "BANDA", "GUERRERO", "FREEMAN", "FREEFAYER", "POTTER", "HERNANDEZ", "BORJA", "KHALIFA", "ARIAS", "DELGADO", "RODRIGUEZ"};

    alumno->sexo = rand() % 2 + 1;
    if(alumno->sexo == 1){
      strcpy(alumno->nombre, nombresH[rand() % 15]);
    }else{
      strcpy(alumno->nombre, nombresM[rand() % 15]);
    }
    
    strcpy(alumno->apellido_p, apellidos[rand() % 15]);
    strcpy(alumno->apellido_m, apellidos[rand() % 15]);
    alumno->edad = (rand() % 20) + 18;
    alumno->matricula =  (1000000 * (rand() % 3) + 1) + (100000 * (rand() % 10)) + (10000 * (rand() % 10)) + (1000 * (rand() % 10)) + (100 * (rand() % 10)) + (10 * (rand() % 10)) + (rand() % 10);
    alumno->estado = TRUE;  
}

void agregarAletorios(Talumno alumnos[], int tam){
  int i;
  
  for(i = 0; i < tam; i++)
    agregarAleatorio(&alumnos[i]);
}

void imprimirReg(Talumno alumno){
 
  if(alumno.estado == TRUE){
    printf("\n-----------------------------------------------------\n");
    printf("Matricula: %lu\n", alumno.matricula);
    printf("Nombre completo: %s %s %s\n", alumno.nombre, alumno.apellido_p, alumno.apellido_m);
    if(alumno.sexo == 1){
      printf("Sexo: Hombre\n");
    }else{
      printf("Sexo: Mujer\n");
    }
    printf("Edad: %d\n", alumno.edad);
  }
}

void imprimirDatos(Talumno alumnos[], int tam, int ini, int fin){
  int i;
  
  system("cls");
  
  if(i >= 0){
    for(i = ini; i < fin; i++){
      if(alumnos[i].estado == TRUE){
        printf("\n\nRegistro: %d",i);
        imprimirReg(alumnos[i]);
      }
    }
  }
}

int insertarDatos(Talumno *alumnos){
  Tnombre nombre;
  Tapellido apellido_p, apellido_m;
  Talumno alumno;

  alumno.matricula = validarNumeroLCR((char *) "Ingrese el numero de matricula: ",(char *) "Ingrese un numero de matricula valido", 1, 1000000, 3999999);
  alumno.edad = validarNumeroICR((char *) "Ingresa tu edad: ",(char *) "Ingresa una edad valida", 1, 17, 99);
  validarTexto((char *) "Ingrese el nombre: ", nombre, MAX_NOMBRE, 2);
  validarTexto((char *) "Ingresa el apellido paterno: ", apellido_p, MAX_APELLIDO, 2);
  validarTexto((char *) "Ingrese el apellido materno: ", apellido_m, MAX_APELLIDO, 2);
  alumno.sexo = validarNumeroICR((char *) "1.-HOMBRE\n2.-MUJER\n",(char *) "Ingrese un valor correcto de 1 o 2", 1, 1, 2);
  alumno.estado = TRUE;
  mayusculas(nombre);
  mayusculas(apellido_p);
  mayusculas(apellido_m);
  quitarEspaciosExtras(nombre);
  quitarEspaciosExtras(apellido_p);
  quitarEspaciosExtras(apellido_m);
  
  strcpy(alumno.nombre, nombre);
  strcpy(alumno.apellido_p, apellido_p);
  strcpy(alumno.apellido_m, apellido_m);

  *alumnos = alumno;
  
  return 0;
}

void buboReg(Talumno alumnos[], int tam, long matricula, logico borrar){
  int i;
  
  for(i = 0; i < tam; i++){
    if(alumnos[i].matricula == matricula){
      if(alumnos[i].estado == TRUE){
        imprimirReg(alumnos[i]);
        if(borrar == TRUE){
          if(validarNumeroICR((char *) "1.-Si\n2.-No\nDesea borrar este registro para SIEMPRE!!!",(char *) "Error ingrese un valor correcto", 1, 1, 2) == 1){
            printf("Alumno con matricula %lu a sido borrado\n", alumnos[i].matricula);
            alumnos[i].estado = FALSE;
          }
        }
      }
    }
  }
}

void ordenarReg(Talumno alumnos[], int tam){
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

int generarArchivo(Talumno alumnos[], int tam, logico binario){
  
  FILE *archivo;
  char nombre[30];
  int i;
  
  if(binario){
    system("erase temp.bak");
    system("copy registros.dat temp.bak");
    archivo = fopen(nombre, "wb");
    if(archivo == NULL)
      return -1;
    
    fwrite(alumnos, sizeof(struct _talumno), tam, archivo);
    if(ferror(archivo)){
      fclose(archivo);
      return -2;
    }
  }else{
    validarTexto((char *)"Ingrese el nombre del archivo a guardar: ", nombre, 30, 2);
    strcat(nombre, ".txt");
    archivo  = fopen(nombre, "w");
    fprintf(archivo, "MATRICULA | ESTATUS | NOMBRE/S | APELLIDO PATERNO | APELLIDO MATERNO | EDAD | SEXO\n");
    for(i = 0; i < tam; i++){
      fprintf(archivo, "%010lu | %1d %-10s %-10s %-10s %03d %-10s\n",alumnos[i].matricula, alumnos[i].estado, alumnos[i].nombre, alumnos[i].apellido_p, alumnos[i].apellido_m, alumnos[i].edad, (alumnos[i].sexo == 1)? "HOMBRE" : "MUJER" );
    }
  }
  
  fclose(archivo);
  return 0;
}

void ordenarBurbuja(Tindex alumnos[], int tam){
  int i, j;
  Tindex alumno;

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

int busquedaBinariaRecursiva(Tindex alumnos[], long matricula, int izquierda, int derecha){

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

int busquedaSecuencial(Tindex alumnos[], unsigned long matricula, int x, int y){
  int i;
  
  for(i = x; i < y; i++){
    if(alumnos[i].matricula == matricula){
      return i;
    }
  }
  
  return -1;
}

Talumno leerDatoArchivo(int pos){
  FILE *archivo;
  archivo = fopen("registros.dat", "rb");
  Talumno alumno;
  
  if(archivo){
    rewind(archivo);
    fseek(archivo, sizeof(Talumno) * pos, SEEK_SET);
    fread(&alumno, sizeof(Talumno), 1, archivo);
    
    fclose(archivo);
    return alumno;
  }
  
  return alumno;
}

void borrarRegistro(int pos){
  FILE *archivo;
  Talumno alumno;
  
  archivo = fopen("registros.dat", "rb+");
  
  if(archivo){
    rewind(archivo);
    fseek(archivo, sizeof(Talumno) * pos, SEEK_SET);
    fread(&alumno, sizeof(Talumno), 1, archivo);
    
    alumno.estado = FALSE;
    printf("Se borro %s\n",alumno.nombre);
    rewind(archivo);
    fseek(archivo, sizeof(Talumno) * pos, SEEK_SET);
    fwrite(&alumno, sizeof(Talumno), 1, archivo);
    fclose(archivo);
  }
}

void busqueda(Tindex alumnos[], int *n, int grado, int modo){
  Talumno alumno;
  long matricula;
  int pos;
  
    matricula = validarNumeroLCR("Ingrese la matricula a buscar: ", "Ingrese una matricula correcta", 1, 9999, 9999999);
    if(grado == ORDENADO || grado == SEMIORDENADO){
      pos = busquedaBinariaRecursiva(alumnos, matricula, 0, *n);
    }else{
      pos = busquedaSecuencial(alumnos, matricula, 0, *n);
    }
    if(pos != -1){
        alumno = leerDatoArchivo(alumnos[pos].index);
        
        if(alumno.estado){
          imprimirReg(alumno);
          if(modo == BORRAR){
            if(validarNumeroICR("Desea borrar el registro\n1.- Si\n2.- No\n", "Ingrese un valor correcto", 1, 1, 2) == 1){
              borrarRegistro(alumnos[pos].index);
            }
          }
        }else{
          printf("No existe\n");
        }
    //imprimirReg(alumnos[pos].index);
    }else{
      printf("No existe\n");
    }
  printf("\n");
}

int qckSort(Tindex alumnos[], int izq, int der){
  if(izq >= der){
    return 0;
  }

  Tindex pivote = alumnos[izq], temp;
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

void ordenarQuickSort(Tindex alumnos[], int n){
    qckSort(alumnos, 0, n-1);
}

void ordenar(Tindex alumnos[], int tam, int *grado){
  if(tam != 0){
    if(*grado == DESORDENADO){
      puts("DESORDENADO");
      printf("%d",tam);
      ordenarQuickSort(alumnos, tam - 1);
      printf("Se ordeno con Quick sort\n");
    }else{
      if(*grado == SEMIORDENADO){
        puts("SEMIORDENADO");
        ordenarBurbuja(alumnos, tam);
        printf("Se ordeno con Bubble sort\n");
      }
    }

    *grado = ORDENADO;
  }
}

void cargarArchivo(Talumno alumnos[], int max, char nombreArchivo[]){
  FILE *archivo;
  
  archivo = fopen(nombreArchivo, "rb");
  
  if(!archivo){
    printf("El archivo %s no existe\n", nombreArchivo);
  }else{
    fread(alumnos, sizeof(Talumno), max, archivo);
    fclose(archivo);
  }
}

void guardaAlumno(Talumno *alumno){
  FILE *archivo;
  
  archivo = fopen("registros.dat", "r+b");
  
  if(archivo){
    fseek(archivo, 0, SEEK_END);
    fwrite(alumno, sizeof(Talumno), 1, archivo);
    if(ferror(archivo)){
      printf("Ocurrio un error\n");
    }else{
      printf("Se agrego correctamente el alumno: %s\n",alumno->nombre);
    }
    fclose(archivo);
  }
}

void leerArchivo(int pos){
  FILE *archivo;
  Talumno alumno;
  
  archivo = fopen("registros.dat", "rb");
  
  if(archivo){
    rewind(archivo);
    fseek(archivo, sizeof(Talumno) * pos, SEEK_SET);
    fread(&alumno, sizeof(Talumno), 1, archivo);
    
    printf("%010lu | %-10s %-10s %-10s | %03d | %-10s |\n",alumno.matricula, alumno.nombre, alumno.apellido_p, alumno.apellido_m, alumno.edad, (alumno.sexo == 1)? "HOMBRE" : "MUJER" );
    fclose(archivo);
  }
}

void submenu(Tindex index[], int max, int *n, int opcion, int *grado){
  system("cls");
  Talumno alumno;
  if(opcion == 1){
    printf("1.- Automatico\n");
    printf("2.- Manual\n");
       
    if(validarNumeroICR(NULL,(char *) "Ingrese una opcion correcta", 1, 1, 2) == 1){
      agregarAleatorio(&alumno);
    }else{
      insertarDatos(&alumno);
    }
    
    guardaAlumno(&alumno);
    if(*n <= max){
      index[*n + 1].matricula = alumno.matricula;
      index[*n + 1].index = (*n) + 1;
      *n += 1;
    }
  }else{
    if(opcion == 5){
      printf("1.- Ordenado\n");
      printf("2.- Archivo normal\n");
      
      if(validarNumeroICR(NULL, (char *)"Ingrese una opcion correcta", 1, 1, 2) == 1){
        ordenar(index, *n, grado);
        for(int i = 0; i < *n; i++){
          leerArchivo(index[i].index);
        }
      }else{
        for(int i = 0; i < *n; i++){
          leerArchivo(index[i].index);
        }
      }
    }
  }
  
  system("pause");
}
