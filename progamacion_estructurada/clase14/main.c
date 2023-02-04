#include "milib.h"
#include "rosaak.h"
#include "validar.h"

#define MAX_ALUMNOS 3500

void generarArchivoIndex(Tindex [], int tam, logico bin);

int main(){
  Tindex index[MAX_ALUMNOS], paquetado[MAX_ALUMNOS];
  int n;
  int opcion = TRUE;
  int grado = DESORDENADO;
  
  n = cargarDatos(index, MAX_ALUMNOS, "registros.dat");
  
  while(opcion){
    opcion = menu();
    
    switch(opcion){
      case 1:
        submenu(index, MAX_ALUMNOS, &n, opcion, NULL);
        break;
        case 2:
        busqueda(index, &n, grado, BORRAR);
        system("pause");
        break;
      case 3:
        busqueda(index, &n, grado, BUSCAR);
        system("pause");
        break;
      case 4:
        ordenar(index, n - 1, &grado);
        break;
      case 5:
        submenu(index, MAX_ALUMNOS, &n, opcion, &grado);
        break;
      case 6:
        generarArchivoIndex(index, n, FALSE);
        break;
      case 7:
        cargarDatos(paquetado, MAX_ALUMNOS, "registros.dat");
        generarArchivoIndex(paquetado, n, TRUE);
        system("pause");
        break;
    }
  }
}

void generarArchivoIndex(Tindex index[], int tam, logico bin){
  FILE *archivo;
  Talumno alumnos[MAX_ALUMNOS];
  
  archivo = fopen("registros.dat","rb");
  
  if(archivo){
    fread(alumnos, sizeof(Talumno), tam, archivo);
    generarArchivo(alumnos, tam, bin);
  }
}