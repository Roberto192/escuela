#include "rosaak.h"

#define MAX_CURP 19
#define MAX_NAME 60
#define MAX_LAST_NAME 40
#define MAX_FULL_NAME MAX_NAME + (2 * MAX_LAST_NAME)
#define TAMPRE 20


void cambiarpalabra(char cadena[]){
  
     char palabraProhibida[81][5] = {"BACA",
                                  "BAKA",
                                  "BUEI",
                                  "BUEY",
                                  "CACA",
                                  "CACO",
                                  "CAGA",
                                  "CAGO",
                                  "CAKA",
                                  "CAKO",
                                  "COGE",
                                  "COGI",
                                  "COJA",
                                  "COJE",
                                  "COJI",                              
                                  "COJO",
                                  "COLA",
                                  "CULO",
                                  "FALO",
                                  "FETO",
                                  "GETA",
                                  "GUEI",
                                  "GUEY",
                                  "JETA",
                                  "JOTO",
                                  "KACA",
                                  "KACO",
                                  "KAGA",
                                  "KAGO",
                                  "KAKA",
                                  "KAKO",
                                  "KOGE",
                                  "KOGI",   
                                  "KOJA",
                                  "KOJE",
                                  "KOJI",
                                  "KOJO",
                                  "KOLA",
                                  "KULO",
                                  "LILO",
                                  "LOCA",
                                  "LOCO",
                                  "LOKA",
                                  "LOKO",
                                  "MAME",
                                  "MAMO",
                                  "MEAR",
                                  "MEAS",
                                  "MEON",
                                  "MIAR",
                                  "MION",
                                  "MOCO",
                                  "MOKO",
                                  "MULA",
                                  "MULO",
                                  "NACA",
                                  "NACO",
                                  "PEDA",
                                  "PEDO",
                                  "PENE",
                                  "PIPI",
                                  "PITO",
                                  "POPO",
                                  "PUTA",
                                  "PUTO",
                                  "QULO",
                                  "RATA",
                                  "ROBA",
                                  "ROBE",
                                  "ROBO",
                                  "RUIN",
                                  "SENO",
                                  "TETA",
                                  "VACA",
                                  "VAGA",
                                  "VAGO",
                                  "VAKA",
                                  "VUEI",
                                  "VUEY",
                                  "WUEI",
                                  "WUEY"};
     
     int i;
     int j;
     int k = 0;
     
     for(i = 0; i < 82; i++){
          k = 0;
          for(j = 0; j < 5; j++){
               if(cadena[j] == palabraProhibida[i][j]){
                    k++;
               }
          }
          
          if(k == 4){
               cadena[1] = 'X';
          }
     }
     
}

void convertirNumeroA_Cadena(char destino[], int numero, int cant){
  int ceros[6] = {
    1,10,100,1000,10000,100000
  };
  
  int i;
  int tamDin = cant - 2;
  int res = ceros[tamDin];//cant -> 4
  int quitar;
  
  
  //1998
  for(i = 0; i < cant - 1; i++){
    quitar = numero / res;
    numero -= quitar * res;
    destino[i] = quitar + '0';
    res = ceros[--tamDin];//cant -> 3
  }
  
  destino[i] = '\0';
  //resultado -> "1998"
}

int esVocal(char c){
  if(c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U'){
    return 1;
  }else{
    return 0;
  }
}

int cuantosHayDe(char cadena[], int n, char c){
  int hay = 0;
  int i;
  
  for(i = 0; i < n; i++){
    if(cadena[i] == c){
      hay++;
    }
  }
  
  return hay;
}

void existe(char cadena[], int n, char palabra[], int m){
  int i;
  int j = 0;
  
  for(i = 0; i <= m; i++){
    if(cadena[i] == palabra[i]){
      printf("%c -> %c\n",cadena[i], palabra[i]);
      j++;
    }
  }
  
  if(j == m - 1){
    printf("Si entro\n");
    for(i = m + 1, j = 0; i <= n; i++){
      cadena[j++] = cadena[i];
    }
    
    cadena[j] = '\0';
  }else{
    printf("No entro %s\n",palabra);
  }
}

int obtPosCar(char cadena[], int tam, char c){
  int i;
  
  for(i = 0; i < tam; i++){
    if(cadena[i] == c){
      return i;
    }
  }
  
  return -1;
}

int siExisteEliminala(char cadena[], int n, char datoAEliminar[],int m){
  int i;
  int j = 0;
  //de rosa
  for(i = 0; i < n; i++){
    if(cadena[i] == datoAEliminar[i]){
      j++;
    }
  }
  
  if(m == j){
    printf("%s %sYa valio\n",cadena, datoAEliminar);
    for(j = n + 1, i = 0; j < longitud(cadena)+1; j++, i++){
      cadena[i] = cadena[j];
    }
    cadena[i] = '\0';
    return 1;
  }else{
    return 0;
    printf("No es: %d %d  %s\n", j, m,datoAEliminar);
  }
}

void crearCurp(char CURP[], char nombre_s[], char apellido_p[], char apellido_m[], char anyo[], char mes[], char dia[], char estado[], char sexo){
  
  char nombreProb[7][10] = {"MARIA", "MA.", "MA", "JOSE", "J.", "J"};
  char preposiciones[TAMPRE][5] = {"DA", "DAS", "DE", "DEL", "DER", "DI", "DIE", "DD", "EL", "LA", "LOS", "LAS", "LE", "LES", "MAC", "MC", "VAN", "VON", "Y"};
  
  char vocalesApp[MAX_LAST_NAME];
  char consonantesApp[MAX_LAST_NAME];
  char consonantesApm[MAX_LAST_NAME];
  char consonantesN[MAX_LAST_NAME];
  char apellido_buff[MAX_LAST_NAME];
  char apellido_buffm[MAX_LAST_NAME];
  char nombre_buff[MAX_NAME];
  int cuantosEsp;
  int posEsp;
  int i;
  int j;
  int controlador = 0;
  
  strcpy(apellido_buff, apellido_p);
  strcpy(apellido_buffm, apellido_m);
  strcpy(nombre_buff, nombre_s);
  
  cuantosEsp = cuantosHayDe(apellido_buff, longitud(apellido_buff), ' ');
  if(cuantosEsp > 0){
    for(i = cuantosEsp;i != 0; i--){
      posEsp = obtPosCar(apellido_buff, longitud(apellido_buff), ' ');
      if(posEsp != -1){
        for(j = 0; j < TAMPRE; j++){
          controlador = siExisteEliminala(apellido_buff, posEsp, preposiciones[j], longitud(preposiciones[j])+ 1);
          if(controlador){
            j = TAMPRE;
          }
        }
      }
    }
  }
  
  cuantosEsp = cuantosHayDe(apellido_buffm, longitud(apellido_buffm), ' ');
  if(cuantosEsp > 0){
    for(i = cuantosEsp;i != 0; i--){
      posEsp = obtPosCar(apellido_buffm, longitud(apellido_buffm), ' ');
      if(posEsp != -1){
        for(j = 0; j < TAMPRE; j++){
          controlador = siExisteEliminala(apellido_buffm, posEsp, preposiciones[j], longitud(preposiciones[j])+ 1);
          if(controlador){
            j = TAMPRE;
          }
        }
      }
    }
  }
  
  cuantosEsp = cuantosHayDe(nombre_buff, longitud(nombre_buff), ' ');
  if(cuantosEsp > 0){
    for(i = cuantosEsp;i != 0; i--){
      posEsp = obtPosCar(nombre_buff, longitud(nombre_buff), ' ');
      if(posEsp != -1){
        for(j = 0; j < TAMPRE - 1; j++){
          controlador = siExisteEliminala(nombre_buff, posEsp, preposiciones[j], longitud(preposiciones[j])+ 1);
          if(controlador){
            j = TAMPRE;
          }
        }
      }
    }
  }
  
  cuantosEsp = cuantosHayDe(nombre_buff, longitud(nombre_buff), ' ');
  if(cuantosEsp > 0){
    for(i = cuantosEsp;i != 0; i--){
      posEsp = obtPosCar(nombre_buff, longitud(nombre_buff), ' ');
      if(posEsp != -1){
        for(j = 0; j < 6; j++){
          controlador = siExisteEliminala(nombre_buff, posEsp, nombreProb[j], longitud(nombreProb[j])+ 1);
          if(controlador){
            j = TAMPRE;
          }
        }
      }
    }
  }
  
  printf("-> %s\n",apellido_buff);
  
  strcpy(vocalesApp, apellido_buff);
  strcpy(consonantesApp, apellido_buff);
  strcpy(consonantesApm, apellido_buffm);
  strcpy(consonantesN, nombre_buff);
  
  printf("Analizando datos...\n");
  printf("Nombre -> %s\n", nombre_buff);
  printf("Apellido Paterno -> %s\n",apellido_buff);
  printf("Apellido materno -> %s\n",apellido_buffm);
  printf("Fecha de nacimiento -> %s/%s/%s\n",anyo, mes, dia);
  printf("Estado -> %s\n",estado);
  printf("Sexo -> %c\n",sexo);
  
  vocales(vocalesApp,1);  
  vocales(consonantesApp, 0);
  vocales(consonantesApm, 0);
  vocales(consonantesN, 0);
  
  CURP[0] = apellido_buff[0];
  CURP[1] = vocalesApp[0];
  CURP[2] = apellido_buffm[0];
  CURP[3] = nombre_buff[0];
  CURP[4] = anyo[2];
  CURP[5] = anyo[3];
  CURP[6] = mes[0];
  CURP[7] = mes[1];
  CURP[8] = dia[0];
  CURP[9] = dia[1];
  CURP[10] = sexo;
  CURP[11] = estado[0];
  CURP[12] = estado[1];
  CURP[13] = consonantesApp[1];
  CURP[14] = consonantesApm[1];
  CURP[15] = consonantesN[1];
  CURP[16] = (char) rand() % (int) 27 + (int) 'A';
  CURP[17] = (char) rand() % 10 + '0';
  
  if(esVocal(CURP[0])){
    CURP[1] = vocalesApp[1];
    CURP[13] = consonantesApp[0];
  }else{
    if(CURP[0] == -61){
      CURP[0] = 'X';
      CURP[13] = consonantesApp[2];
    }
  }
  
  
  if(CURP[13] == -61 || CURP[13] == (char) 165){
    CURP[13] = 'X';
  }else{
    if(CURP[13] == '\0'){
      CURP[13] = 'X';
    }
  }
  
  if(CURP[14] == '\0'){
    CURP[14] = 'X';
  }
  
  if(CURP[2] == '\0'){
    CURP[2]  = CURP[14] = 'X';
  }
  
  if(esVocal(nombre_buff[0])){
    CURP[15] = consonantesN[0];
  }
  
  cambiarpalabra(CURP);  
}