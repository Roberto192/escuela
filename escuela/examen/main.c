#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX 20

typedef struct _tranking{
  char nombre[NAME_MAX];
  float puntajePrevio;
  float puntosObtenidos;
}Tranking;

void pause();

char *capturaPais(char cadena[], int n);

int menu();
void insertarRanking(Tranking rankings[], int tam, int n);
int buscarPais(Tranking rankings[], int tam, char pais[]);
void ordenarRanking(Tranking rankings[], int tam);
int capturarPuntaje(Tranking rankings[], int tam);
void listarXpuntaje(Tranking rankings[], int tam);
int cargarDatos(Tranking rankings[], int tam, char nameFile[]);
void guardarDatos(Tranking rankings[], int tam, char nameFile[]);

int main(int argc, char *argv[]){
  #define N 100
  Tranking ranking[N];
  int n = 0;
  int opcion;
  int fileName = 0;
  
  if(argc >= 3){
    fileName = 1;
    n = cargarDatos(ranking, atoi(argv[2]), argv[1]);
  }else{
    if(argc == 2){
      fileName = 1;
      n = cargarDatos(ranking, 0, argv[1]);
    }else{
      fileName = 0;
      n = cargarDatos(ranking, 0, "datos.dat");
    }
  }
  
  while((opcion = menu())){
    if(opcion == 1){
      insertarRanking(ranking, N, n);
      n = n <= N ? n+1 : N-1;
    }else{
      if(opcion == 2){
        capturarPuntaje(ranking, n);
      }else{
        if(opcion == 3){
         listarXpuntaje(ranking, n);
        }
      }
    }
    pause();
  }

  if(n != 0){
    if(fileName){
      guardarDatos(ranking, n, argv[fileName]);
    }else{
      guardarDatos(ranking, n, "datos.dat");
    }
  }
  
  return 0;
}

void pause(){
  puts("presiona enter para continuar...");
  fflush(stdin);
  getchar();
  fflush(stdin);
}

char *capturaPais(char cadena[], int n){
  int i = 0;
  char c;
  
  puts("Ingrese el nombre del pais");
  fflush(stdin);
  while((c = getc(stdin)) != '\n'){
    cadena[i++] = c;
  }
  fflush(stdin);
  cadena[i] = '\0';
  
  return cadena;
}

float validarPuntaje(char mensaje[]){
  int i = 0;
  float puntaje;
  char numero[20], c;
  
  puts(mensaje);
  fflush(stdin);
  while((c = getc(stdin)) != '\n'){
    
    if(c >= '0' && c <= '9')
      numero[i++] = c;
    if(c == '-' || c == '.')
      numero[i++] = c;
    
    if(i >= 20)
      break;
  }
  
  puntaje = atof(numero);
  
  return puntaje;
}

int menu(){
  char opcion[2];
  system("cls");
  puts("1.- Insertar pais");
  puts("2.- Capturar nuevo puntaje");
  puts("3.- Listar");
  puts("0. Guardar y Salir");
  fflush(stdin);
  fgets(opcion, 2, stdin);
  fflush(stdin);
  
  return opcion[0] != '\n' ? atoi(opcion) : -1 ;
}

void insertarRanking(Tranking ranking[], int tam, int n){
  char nombre[NAME_MAX];
  if(n > tam){
    return;
  }
  
  capturaPais(nombre, NAME_MAX);
  memcpy(ranking[n].nombre, nombre, NAME_MAX);
  ranking[n].puntajePrevio = 0;
  ranking[n].puntosObtenidos = 0;
  printf("Guardado %s\n",ranking[n].nombre);
}

int buscarPais(Tranking ranking[], int tam, char pais[]){
  int i;
  
  if(tam == 0)
    return -1;
  
  for(i = 0; i < tam; i++){
    if(strcmp(ranking[i].nombre, pais) == 0){
      return i;
    }
  }
  
  return -1;
}

void ordenarRanking(Tranking rankings[], int tam){
  
  Tranking aux;
  int i, j;
  
  for(i = 0; i < tam; i++){
    for(j = 0; j < tam-1; j++){
      if(rankings[j].puntajePrevio + rankings[j].puntosObtenidos < rankings[j+1].puntajePrevio + rankings[j+1].puntosObtenidos){
        aux = rankings[j];
        rankings[j] = rankings[j+1];
        rankings[j+1] = aux;
      }
    }
  }
  
}

int capturarPuntaje(Tranking rankings[], int tam){
  
  char nombre[NAME_MAX];
  int i;
  
  if(tam == 0){
    printf("Capture un pais primero\n");
    return -1;
  }else{
    capturaPais(nombre, NAME_MAX);
    i = buscarPais(rankings, tam, nombre);
    if(i != -1){
      if(rankings[i].puntajePrevio == 0){
        rankings[i].puntajePrevio = validarPuntaje("Ingrese puntaje previo");
      }else{
        rankings[i].puntajePrevio += rankings[i].puntosObtenidos;
      }
      rankings[i].puntosObtenidos = validarPuntaje("Ingrese los puntos obtenidos");
      printf("%.2f %.2f\n",rankings[i].puntajePrevio, rankings[i].puntosObtenidos);
      ordenarRanking(rankings, tam);
    }else{
      printf("El pais %s no existe\n",nombre);
    }
  }
  return 0;
}

void listarXpuntaje(Tranking rankings[], int tam){
  int i;
  
  if(tam != 0)
    printf("%-4s %-20s %-15s %-15s %-5c %s\n", "Rk", "Team", "Total points", "Preview points",241, "Position");
  for(i = 0; i < tam; i++){
    printf("%-4d %-20s %12.2f %17.2f %5.2f %5s\n",i + 1, rankings[i].nombre, rankings[i].puntajePrevio + rankings[i].puntosObtenidos, rankings[i].puntajePrevio, rankings[i].puntosObtenidos, (rankings[i].puntosObtenidos > 0)? "+" : "-");
  }
}

int cargarDatos(Tranking rankings[], int tam, char fileName[]){
  FILE *arch;
  int i = 0;
  
  arch = fopen(fileName, "rb");
  if(!arch){
    printf("El archivo %s no se encontro\n",fileName);
    pause();
    return 0;
  }
  
  while(fread(&rankings[i], sizeof(Tranking), 1, arch)){
    i++;
    if(tam != 0)
      if(i > tam)
        break;
  }
  
  return i;
}

void guardarDatos(Tranking rankings[], int tam, char fileName[]){
  FILE *arch;
  
  arch = fopen(fileName, "wb");
  
  if(!arch){
    puts("No se pudo guardar los registros...");
    arch = fopen("backup.bckp", "wb");
    fwrite(rankings, sizeof(Tranking), tam, arch);
    fclose(arch);
  }else{
    fwrite(rankings, sizeof(Tranking), tam, arch);
    
    fclose(arch);
  }
}