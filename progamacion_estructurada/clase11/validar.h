#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INT 10

typedef struct _fecha{
  int d;//dia
  int m;//mes
  int a;//anio -> years
}TSfecha;

int leerEnteroPositivo(){
    
    int controlador = 1;
    int centinela = 1;
    int i = 0;
    char c;
    char numeroEnCadena[MAX_INT];
        
    while(controlador){
        c = getch();
            
        if(c >= '0'){
            if(c <= '9'){
                putchar(c);
                numeroEnCadena[i++] = c;   
            }
        }else{   
            if(c == '\r'){
                putchar('\n');
                numeroEnCadena[i] = '\0';
                controlador = 0;
            }
        }
            
        if(i > MAX_INT){
            putchar('\n');
            puts("Warning: too long int");
            controlador = 0;
        }
            
    }//endwhile
    
    return atoi(numeroEnCadena);
}

int leerEntero(){
    
    int controlador = 1;
    int centinela = 1;
    int i = 0;
    char c;
    char numeroEnCadena[MAX_INT];
    
    while(controlador){
        c = getch();
            
        if(c >= '0'){
            if(c <= '9'){
                putchar(c);
                numeroEnCadena[i++] = c;   
            }
        }else{ 
            if(c == '-'){
                if(!i){
                    putchar(c);
                    numeroEnCadena[i++] = c;
                }
            }else{  
                if(c == '\r'){
                    putchar('\n');
                        numeroEnCadena[i] = '\0';           
                        controlador = 0;
                }
            }
        }
            
        if(i > MAX_INT){
            putchar('\n');
            puts("Warning: too long int");
            controlador = 0;
        }
            
    }//end while
    return atoi(numeroEnCadena);
}
/*
  0 solo minusculas
  1 solo mayusculas
  2 ambos
*/
void validar(char cadena[], int n, int m){

	int i = 0;
	int j = 0;
	int band = 1;
	int espacio = 0;
	char c;
  
	while(band){
		c = getch();

		if(c != '\r'){
			if(j < n){
				
        if(m == 0){
    			if(c >= 'a'){
					  if(c <= 'z'){
						  putchar(c);
						  cadena[j++] = c;
						  espacio = 1;
					  }
				  }
           
          if(c == (char) 164){
					  putchar(c);
					  cadena[j++] = c;
					  espacio = 1;
				  }
        }else{
                
          if(m == 1){
				    if(c >= 'A'){
					    if(c <= 'Z'){
						    putchar(c);
						    cadena[j++] = c;
						    espacio = 1;
					    }
				    }
          
             if (c == (char) 165){	
					    putchar(c);
					    cadena[j++] = c;
					    espacio = 1;
				    }                      
          }else{
                
            if(m == 2){
    			    if(c >= 'a'){
					      if(c <= 'z'){
						      putchar(c);
						      cadena[j++] = c;
						      espacio = 1;
					      }
				      }
				    
				      if(c >= 'A'){
					      if(c <= 'Z'){
							    putchar(c);
						      cadena[j++] = c;
						      espacio = 1;
					      }
              }
          
              if(c == (char) 164){
					      putchar(c);
					      cadena[j++] = c;
					      espacio = 1;
				      }          
            
              if (c == (char) 165){	
					      putchar(c);
					      cadena[j++] = c;
					      espacio = 1;
				      }                     
            }
          }
        }
                
				if(c == ' '){
					if(espacio){
						putchar(c);
						cadena[j++] = ' ';
						espacio = 0;
					}
				}

			}else{
				putchar('\n');
				band = 0;
			}
		}else{
      if(j > 1){
      	putchar('\n');
        band = 0; 
      }
		}
	}

	cadena[j] = '\0';
}

int validarNumeroISR(char msg[], int positivo){
    
	int bandera = 1; 
	int num;
	char c;
    
	 if(positivo){
       
		while(bandera){

			system("cls");
			puts(msg);
			num = leerEnteroPositivo();
      
			printf("Es correcto %d (y/n) ",num);
			c = getch();

  		if(c == 'y'){
				putchar(c);
				bandera = 0;
			}else{
				if(c == 'n'){
					putchar(c);
				}
			}
   }
		
	}else{
    
		while(bandera){

			system("cls");
			puts(msg);
			num = leerEntero();
      
			printf("Es correcto %d (y/n) ", num);
			c = getch();

      if(c == 'y'){
				putchar(c);
				bandera = 0;
			}else{
				if(c == 'n'){
					putchar(c);
				}
		  }
    }
	}
	
	return num;
}

int validarNumeroICR(char msg[], char msgError[], int positivo, int r1, int r2){
    int num;
    
    if(positivo){
        while(1){
            puts(msg);
            num = leerEnteroPositivo();
        
            system("cls");
            if(num >= r1 && num <= r2){
                return num;
            }else{
                puts(msgError);
            }
        }
    }else{
        while(1){
            puts(msg);
            num = leerEntero();
        
            system("cls");
            if(num >= r1 && num <= r2){
                return num;
            }else{
                puts(msgError);
            }
        }
    }
}

void validarTexto(char msg[], char variable[], int n, int t){
	int controlador = 1;
	char c;
	
	while(controlador){
		system("cls");
		puts(msg);
		validar(variable, n, t);
		printf("Es correcto %s (y/n)",variable);
		
		c = getch();
		
		if(c == 'y'){
			putchar(c);
			controlador = 0;
		}else{
			if(c == 'n'){
				putchar(c);
			}
		}
	}
  
  system("cls");
}

char validarUnCaracter(char valido){
  char c;
  while(1){
    c = getch();
    if(c == valido){
      putchar(c);
      return c;
    }
  }
}

char validarDosCaracteres(char v1, char v2){
  char c;
  int controlador = 1;
  
  while(controlador){
    c = getch();
    if(c == v1){
      controlador = 0;
    }else{
      if(c == v2){
        controlador = 0;
      }
    }
  }
  putchar(c);
  return c;
}

//Rango A es la representacion de la fecha minima y Rango B es la maxima
TSfecha validarFecha(TSfecha rangoA, TSfecha rangoB){
  char msg[] = "Ingresa el dia de nacimiento: ";
  char msgErro[] = "Ingresa un dia correcto: ";
  TSfecha fecha;
  int controlador = 1;
  int diaMaximo;
  int valido = 0;
  
  while(controlador){
    fecha.a = validarNumeroICR((char *) "Ingresa tu anio de nacimiento: ",(char *) "Ingresa un fecha valida", 1, rangoA.a, rangoB.a); 
    fecha.m = validarNumeroICR((char *) "Ingresa el mes de nacimiento: ",(char *) "Ingresa un mes valido", 1, 1, 12);
    
    if(fecha.m == 12){
      diaMaximo = 31;
    }else{
      if(fecha.m == 10){
        diaMaximo = 31;
      }else{
        if(fecha.m >= 7){
          diaMaximo = 31;
        }else{
          if(fecha.m % 2 != 0){
            diaMaximo = 31;
          }else{
            if(fecha.m == 2){
              if(fecha.a % 4 == 0){
                diaMaximo = 29;
              }else{
                diaMaximo = 28;
              }
            }else{
              diaMaximo = 30;
            }
          }
        }
      }
    }
    
    fecha.d = validarNumeroICR((char *) "Ingresa el dia de nacimiento: ",(char *) "Ingrese un dia valido", 1, 1, diaMaximo);
    
    if(fecha.m >= rangoA.m){
      if(fecha.d >= rangoA.d){
        if(fecha.a != rangoB.a){
          valido = 1;
        }else{
          if(fecha.m != rangoB.m){
            valido = 1;
          }else{
            if(fecha.d <= rangoB.d){
              valido = 1;
            }
          }
        }
      }
    }
    
    if(valido){
      controlador = 0;
    }else{
      printf("Ingrese una fecha entre %04d/%02d/%02d y %04d/%02d/%02d\n",rangoA.a, rangoA.m, rangoA.d, rangoB.a, rangoB.m, rangoB.d);
    }
    
  }//while  
  
  return fecha;
}

char* obtenerFecha(char fechaCadena[], int t,TSfecha fecha){
  
  snprintf(fechaCadena, t, "%04d/%02d/%02d",fecha.a, fecha.m, fecha.d);
  
  return fechaCadena;
}