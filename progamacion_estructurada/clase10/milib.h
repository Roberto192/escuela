#include <stdio.h>
#include <string.h>
#include "validar.h"
#include "rosaak.h"

#define TRUE 1
#define FALSE 0

#define MAX_NOMBRE 60
#define MAX_APELLIDO 50

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

int menu(){
  
  system("cls");
  
  char men[7][20] = {
    "AGREGAR",
    "AGREGAR MANUAL",
    "ELIMINAR REGISTRO",
    "BUSCAR",
    "ORDENAR",
    "IMPRIMIR",
    "SALIR"
  };
  
  int i;
  
  printf("Menu\n");
  
  for(i = 0; i <= 6; i++){
    printf("%d.- %s\n",i+1,men[i]);
  }
  
  return leerEntero();  
}

int agregarAleatorio(Talumno alumnos[], int tm, int r1, int r2){
  Tnombre nombresM[15] = {"MARIA DE LA LUZ", "GUADALUPE", "VALENTINA", "ASUCENA", "VALERIA", "DE LA TRINIDAD", "JUANA", "VALENTINA", "SOPHIA", "MIA", "MAYDA", "LILIANA", "MONSERRAT", "SUSANA", "MARIA"};
  Tnombre nombresH[15] = {"XHON XINA", "ROBERTO", "SHELONG MUSK", "JOSE", "VICTOR", "HUGO", "JESUS", "HAZAEL", "AZAEL", "TERIYAKI", "JUAN", "ADOLFO", "MARADONA", "PITER", "ARIEL"};
  Tapellido apellidos[15] = {"LOPEZ", "KIM", "RAMIREZ", "TARANTINO", "BANDA", "GUERRERO", "FREEMAN", "FREEFAYER", "POTTER", "HERNANDEZ", "BORJA", "KHALIFA", "ARIAS", "DELGADO", "RODRIGUEZ"};
  
  int i;
  
  if(r2 > tm){
    return -1;
  }

  for(i = r1; i < r2; i++){
    alumnos[i].sexo = rand() % 2 + 1;
    if(alumnos[i].sexo == 1){
      strcpy(alumnos[i].nombre, nombresH[rand() % 15]);
    }else{
      strcpy(alumnos[i].nombre, nombresM[rand() % 15]);
    }
    
    strcpy(alumnos[i].apellido_p, apellidos[rand() % 15]);
    strcpy(alumnos[i].apellido_m, apellidos[rand() % 15]);
    alumnos[i].edad = (rand() % 20) + 18;
    alumnos[i].matricula =  (1000000 * (rand() % 3) + 1) + (100000 * (rand() % 10)) + (10000 * (rand() % 10)) + (1000 * (rand() % 10)) + (100 * (rand() % 10)) + (10 * (rand() % 10)) + (rand() % 10);
    alumnos[i].estado = TRUE;
    
  }
  
  return 0;  
}

void imprimirReg(Talumno alumno){
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

int insertarDatos(Talumno alumnos[], int tam){
  int i;
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

  i = validarNumeroICR((char *) "Ingresa la posicion (1 - 500): ",(char *) "Error valor fuero del los limites", 1, 1, 500);
  alumnos[i - 1] = alumno;
  
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