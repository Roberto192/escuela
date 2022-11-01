#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "validar.h"
#include "ventanas.h"

#define FILE_NAME_DAT "datos.DAT"
#define FILE_NAME_TXT "datos.TXT"
#define MAX_DATOS 100
#define MAX_NOMBRE 50

void menu(char *[], int);
void crearArchivo(char [], char []);
void escribirDatos(int, char []);
int listarDatos(char [], char []);
int insertarRegistro(char [], int, int, int);
void copiarArchivos(char [], char []);
void listar(char [], char []);
void borrar();
void modificarRegistro();

typedef struct _tsdatos{
  int ndc;//Numero de cuenta
  char nombre[MAX_NOMBRE];
  int saldo;
}tsdatos;

int main(){
  
  char *_menu[] = {
    "Crear archivo DAT",//acceso directo
    "Crear archivo TXT",//acesso con formato
    "Insertar Registro",
    "Borrar Registro",
    "Modificar Registro",
    "Listar datos DAT",
    "Listar datos TXT",
    "Salir..."
  };
  
  int centinela = 1;
  int opcion;
  int no;
  int saldo;
  char nombre[MAX_NOMBRE];
  
  srand(time(NULL));
  
  while(centinela){
    ponerMenuEnXY(_menu, 2, 8);
    ponerCuadradoEnXY(2, 2, 50, 20, 3);
    opcion = leerEnteroPositivo();
    
    switch(opcion){
      case 1:
        crearArchivo(FILE_NAME_DAT, "wb");
        escribirDatos(MAX_DATOS, "rb+");
        printf("Archivo creado!!!\n");
        break;
      case 2:
        crearArchivo(FILE_NAME_TXT, "w");
        copiarArchivos(FILE_NAME_DAT, FILE_NAME_TXT);
        break;
      case 3:
        no = rand() % 100 + 1;
        validarTexto("Ingrese el nombre: ", nombre, MAX_NOMBRE, 2);
        saldo = validarNumeroISR("Ingrese el saldo: ", 0);
        opcion = validarNumeroICR("Ingrese la posicion a agregar (1-100)", "Ingrese una posicion correcta!!!", 1, 1, 100);
        insertarRegistro(nombre, no, saldo, opcion - 1);
        break;
      case 4:
        borrar();
      break;
      case 5:
        modificarRegistro();
      break;
      case 6:
        listarDatos(FILE_NAME_DAT, "rb");
      break;
      case 7:
        listar(FILE_NAME_TXT, "r");
      break;
      case 8:
        centinela = 0;
      break;
    }
    system("pause");
  }
  
  system("cls");
  return 0;
}

void menu(char *text[], int n){
    int i;
    system("cls");
    for(i = 0; i < n; i++)
        puts(text[i]);
}

void crearArchivo(char fileName[], char t[]){
  FILE *datos;
  
  fopen_s(&datos, fileName, t);
  
  if(datos == NULL){
    printf("Error no se pudo crear el archivo %s", fileName);
  }
  
  fclose(datos);
  
}

void escribirDatos(int cantidad, char t[]){
  
  FILE *archivo;
  tsdatos datos = {0, "", 0};
  int i;
  
  fopen_s(&archivo, FILE_NAME_DAT, t);
  
  if(archivo != NULL){
    for(i = 0; i < cantidad; i++){
      fwrite(&datos, sizeof(struct _tsdatos), 1, archivo);
    }
    if(ferror(archivo)){
      printf("Error\n");
    }
    
  }else{
    printf("Error al abrir el archivo: %s\n",FILE_NAME_DAT);
  }
  fclose(archivo);
  
}

int listarDatos(char nombreDelArchivo[], char t[]){
  
  int i;
  
  FILE *archivo;
  tsdatos dato;
  
  system("cls");
  if(fopen_s(&archivo, nombreDelArchivo, t)){
    printf("No se pudo encontrar el archivo %s\n", nombreDelArchivo);
    return -1;
  }
  
  printf("#  | No. | %50s | Saldo\n","Nombre");
  for(i = 0; !feof(archivo); i++){
    fread(&dato, sizeof(struct _tsdatos), 1, archivo);
    if(i < MAX_DATOS) 
      printf("%3d| %3d | %50s | %d\n", i+1 ,dato.ndc, dato.nombre, dato.saldo);
  }
  
  fclose(archivo);
  return i;
}

int insertarRegistro(char nombre[], int no, int saldo, int pos){
  
  tsdatos dato;
  FILE *archivo;
  int salida = 1;
  int i;
  
  if(fopen_s(&archivo, FILE_NAME_DAT, "rb+")){
    printf("No se pudo encontrar el archivo: %s\n",FILE_NAME_DAT);
    salida = -1;
  }else{
    dato.ndc = no;
    strcpy(dato.nombre, nombre);
    dato.saldo = saldo;
    
    if(fseek(archivo, sizeof(struct _tsdatos) * pos, SEEK_SET) == 0){  
      fwrite(&dato, sizeof(struct _tsdatos), 1, archivo);
      salida = 0;
    }else{
      printf("Algo surgio mal...\n");
    }
  }
  
  if(ferror(archivo)){
    printf("No se pudo agregar el usuario\n");
    salida = -3;
  }else{
    printf("Usuario agregado correctamente\n");
  }

  
  fclose(archivo);
  return salida;
}

void copiarArchivos(char nombreOriginal[], char nombreDestino[]){
  FILE *original, *destino;
  tsdatos dato;
  int ndc = 0;
  int contador = 0;

  fopen_s(&original, nombreOriginal, "rb");
  fopen_s(&destino, nombreDestino, "r+");
  
  if(original == NULL || destino == NULL){
    printf("No se encontro el archivo:\n%s\n%s",nombreOriginal, nombreDestino);
  }else{
    fprintf(destino, "%3s | %-50s | %s\n","No.","Nombre de la cuenta","Saldo");
    do{
      fread(&dato, sizeof(struct _tsdatos), 1, original);
      if(ferror(original)){
        fprintf(destino, "Error!!!");
      }else{
          if(dato.ndc != ndc){
            if(dato.ndc != 0){
              fprintf(destino, "%3d | %50s | %d\n", dato.ndc, dato.nombre, dato.saldo);
              ndc = dato.ndc;
              contador++;
            }
          }
      }
    }while(!feof(original));
    
    printf("Se guardo un total de %d\n",contador);
  }
  
  fclose(original);
  fclose(destino);
  
}

void listar(char nombre[], char tipo[]){
  FILE *archivo;
  
  fopen_s(&archivo, nombre, tipo);
  
  if(archivo == NULL){
    printf("Error no se encontro: %s",nombre);
  }else{
    do{
      putchar(fgetc(archivo));
    }while(!feof(archivo));
  }
  
  fclose(archivo);
}

void borrar(){
  
  FILE *archivo;
  tsdatos dato;
  int ndc;
  int i = 0;
  int j = 0;
  
  fopen_s(&archivo, FILE_NAME_DAT, "rb+");
  
  if(archivo == NULL){
    printf("Primero cree el archivo DAT\n");
  }else{
    
    ndc = validarNumeroICR("Ingrese el no. de cuenta: ", "Ingrese un numero de cuenta valido!!!", 1, 1, 100);
    
    while(!feof(archivo)){
      fread(&dato, sizeof(struct _tsdatos), 1, archivo);
      if(dato.ndc == ndc){
        j = i;
      }
      i++;
    }
    
    if(j == 0){
      printf("No se encontro el usuario\n");
    }else{
      dato.saldo = 0;
      dato.saldo = 0;
      memset(dato.nombre, '\0', MAX_NOMBRE);
      rewind(archivo);
      fseek(archivo, sizeof(struct _tsdatos) * j, SEEK_CUR);
      fwrite(&dato, sizeof(struct _tsdatos), 1, archivo);
    }
  }
  
  
  fclose(archivo);
}

void modificarRegistro(){
  
  FILE *archivo;
  tsdatos dato, aux;
  int ndc;
  int i = 0;
  int j = 0;
  
  fopen_s(&archivo, FILE_NAME_DAT, "rb+");
  
  if(archivo == NULL){
    printf("Primero cree el archivo DAT\n");
  }else{
    
    ndc = validarNumeroICR("Ingrese el no. de cuenta: ", "Ingrese un numero de cuenta valido!!!", 1, 1, 100);
    
    while(!feof(archivo)){
      fread(&dato, sizeof(struct _tsdatos), 1, archivo);
      if(dato.ndc == ndc){
        j = i;
        aux = dato;
      }
      i++;
    }
    
    if(j == 0){
      printf("No se encontro el usuario\n");
    }else{
      aux.saldo = validarNumeroISR("Ingresa el nuevo saldo: ", 0);
      rewind(archivo);
      fseek(archivo, sizeof(struct _tsdatos) * j, SEEK_CUR);
      fwrite(&aux, sizeof(struct _tsdatos), 1, archivo);
    }
  }
  
  fclose(archivo);
}