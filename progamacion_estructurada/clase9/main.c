#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "CURPC.h"
#include "validar.h"
#include "rosaak.h"

#define MAX_CURP 19
#define MAX_NAME 60
#define MAX_LAST_NAME 40
#define MAX_FULL_NAME MAX_NAME + (2 * MAX_LAST_NAME)
#define TAMPRE 20

int validarMesSF(int, char *, char *);
void imprimirMenu(char *[], int , int);
void crearCurp(char [], char [], char [], char [], char [], char [], char [], char [], char);
void convertirNumeroA_Cadena(char [] , int, int);
int esVocal(char );
int cuantosHayDe(char [], int, char);
void existe(char [], int, char [], int);
int obtPosCar(char [], int, char);
int siExisteEliminala(char [], int, char [], int);

int main(){
  char msgDiaNacimiento[] = "Ingresa el dia de nacimiento: ";
  char msgDiaNacimientoError[] = "Ingrese un dia correcto: ";
  char mesCadena[12][10] = {
    "ENERO",
    "FEBRERO",
    "MARZO",
    "ABRIL",
    "MAYO",
    "JUNIO",
    "JULIO",
    "AGOSTO",
    "SEPTIEMBRE",
    "OCTUBRE",
    "NOVIEMBRE",
    "DICIEMBRE"
  };
  
  char mesCadenaNumerico[12][3] = {
    "01",
    "02",
    "03",
    "04",
    "05",
    "06",
    "07",
    "08",
    "09",
    "10",
    "11",
    "12"
  };
  
  char diaCadenaNumero[31][3] = {
    "01",
    "02",
    "03",
    "04",
    "05",
    "06",
    "07",
    "08",
    "09",
    "10",
    "11",
    "12",
    "13",
    "14",
    "15",
    "16",
    "17",
    "18",
    "19",
    "20",
    "21",
    "22",
    "23",
    "24",
    "25",
    "26",
    "27",
    "28",
    "29",
    "30",
    "31"
  };
  
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
  
  char estadosNombreCompleto[33][40] = {
        "AGUASCALIENTES     ",    
        "BAJA CALIFORNIA    ",    
        "BAJA CALIFORNIA SUR",    
        "CAMPECHE           ",    
        "COAHUILA           ",    
        "COLIMA             ",    
        "CHIAPAS            ",    
        "CHIHUAHUA          ",    
        "DISTRITO FEDERAL   ",    
        "DURANGO            ",    
        "GUANAJUATO         ",    
        "GUERRERO           ",    
        "HIDALGO            ",    
        "JALISCO            ",    
        "MEXICO             ",    
        "MICHOACAN          ",    
        "MORELOS            ",    
        "NAYARIT            ",    
        "NUEVO LEON         ",    
        "OAXACA             ",    
        "PUEBLA             ",    
        "QUERETARO          ",    
        "QUINTANA ROO       ",    
        "SAN LUIS POTOSI    ",    
        "SINALOA            ",    
        "SONORA             ",    
        "TABASCO            ",    
        "TAMAULIPAS         ",    
        "TLAXCALA           ",    
        "VERACRUZ           ",    
        "YUCATAN            ",    
        "ZACATECAS          ",
        "NACIDO EN EL EXTRANJERO"    
      };
  
  char nombreCompleto[MAX_FULL_NAME];
  char nombre_s[MAX_NAME];
  char apellido_p[MAX_LAST_NAME];
  char apellido_m[MAX_LAST_NAME];
  char CURP[MAX_CURP] = "xxxx000000xxxxxxx0\0";
  char sexo;
  int anyo;
  char anyoC[5];
  int mes;
  int dia;
  int i;
  int estado;
  int centinela = 1;
  int controlador = 1;
  int si = 1;;

  srand(time(NULL));
      
  //pedir nombre completowhile(controlador){
  while(si){
    nombreCompleto[0] = '\0';
    validarTexto("Ingresa tu nombre/s: ", nombre_s, MAX_NAME, 2);
    mayusculas(nombre_s);
    validarTexto("Ingresa el apellido paterno: ", apellido_p, MAX_LAST_NAME, 2);
    mayusculas(apellido_p);
    validarTexto("Ingresa el apellido materno: ", apellido_m, MAX_LAST_NAME, 2);
    mayusculas(apellido_m);
    
    strcat(nombreCompleto, apellido_p);
    strcat(nombreCompleto, " ");
    strcat(nombreCompleto, apellido_m);
    strcat(nombreCompleto, " ");
    strcat(nombreCompleto, nombre_s);
      
    anyo = validarNumeroICR("Ingresa el año de nacimiento", "Ingrese un año mayor a 1900 o menor al actual", 1, 1900, 2022);
    for(i = 0; i < 12; i++){
      printf("%d.- %s\n",i + 1,mesCadena[i]);
    }
    mes = validarNumeroICR("Ingresa el mes de nacimiento (1-12): ", "Ingrese un mes correcto entre 1-12", 1, 1, 12);  

    if(anyo % 4 == 0){
      if(mes == 2){
         dia = validarNumeroICR(msgDiaNacimiento, msgDiaNacimientoError, 1, 1, 29);
      }  else{
          dia = validarMesSF(mes, msgDiaNacimiento, msgDiaNacimientoError);
      }  
    }  else{
      if(mes == 2){
          dia = validarNumeroICR("Ingresa el dia de nacimiento: ", "Ingresa un dia correcto", 1, 1, 28);
      }else{
        dia = validarMesSF(mes, msgDiaNacimiento, msgDiaNacimientoError);
      }
    }
  
    //fin de lectura de fecha de nacimiento
    
    //inicio de pedir el estado de nacimiento
    for(i = 0; i < 33; i++){
        printf("%d.- %s\n",i + 1, estadosNombreCompleto[i]);
    }
    estado = validarNumeroICR("Ingresa el estado de nacimiento: ", "Ingrese un estado correcto", 1, 1, 33);
    //Fin de estado de nacimiento
    //Pedir sexo
  
    printf("Ingresa el sexo\n");
    printf("M - MUJER\n");
    printf("H - HOMBRE\n");
    sexo = validarDosCaracteres('M', 'H');
    system("cls");
    //Fin de sexo  
    //Inicio crear CURP
    convertirNumeroA_Cadena(anyoC, anyo, 5);
    crearCurp(CURP, nombre_s, apellido_p, apellido_m, anyoC, mesCadenaNumerico[mes - 1], diaCadenaNumero[dia - 1], estadosDe2Caracteres[estado - 1], sexo);
    //Fin CURP
  
    printf("Nombre completo: %s\n", nombreCompleto);
    printf("Nombre: %s\n", nombre_s);
    printf("Apellido Paterno: %s\n", apellido_p);
    printf("Apellido Materno: %s\n", apellido_m);
    printf("Fecha de nacimiento: %d/%s/%s \n", anyo, mesCadenaNumerico[mes - 1], diaCadenaNumero[dia - 1]);
    printf("Estado de nacimiento: %s, %s",estadosDe2Caracteres[estado - 1], estadosNombreCompleto[estado - 1]);
    printf("Sexo: %c\n", sexo);
    printf("CURP: %s\n", CURP);
    
    printf("Desea sacar otro curp: (y/n)\n");
    if(validarDosCaracteres('y','n') == 'n'){
      si = 0;
    }
  }
  return 0;
}

int validarMesSF(int mes, char msg[], char msgError[]){
  int dia;
  
  if(mes == 12){
    dia = validarNumeroICR(msg, msgError, 1, 1, 31);
  }else{
    if(mes == 11){
      dia = validarNumeroICR(msg, msgError, 1, 1, 30);
    }else{
      if(mes == 10){
        dia = validarNumeroICR(msg, msgError, 1, 1, 31);
      }else{
        if(mes == 9){
          dia = validarNumeroICR(msg, msgError, 1, 1, 30);
        }else{
          if(mes == 8){
            dia = validarNumeroICR(msg, msgError, 1, 1, 31);
          }else{
            
            if(mes % 2 != 0){
              dia = validarNumeroICR(msg, msgError, 1, 1, 31);
            }else{
              dia = validarNumeroICR(msg, msgError, 1, 1, 30);
            }
          }
        }
      }
    }
  }
  
  return dia;
}

void imprimirMenu(char *msg[], int tam, int enumerado){
  int i;
  
  for(i = 0; i < tam; i++){
    if(enumerado){
      printf("%d.- %s\n",i+1,msg[i]);
    }else{
      puts(msg[i]);
    }
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