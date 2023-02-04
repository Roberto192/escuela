
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