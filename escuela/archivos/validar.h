#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INT 10

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

void validar(char cadena[], int n, int m){

	int i = 0;
	int j = 0;
	int band = 1;
	int espacio = 0;
	char c;

	for(i = 0; band; i++){
		c = getch();

		if(c != '\r'){
			if(i < n){
				if(c == (char) 164){
					putchar(c);
					cadena[j++] = c + 1;
					espacio = 1;
				}

				if (c == (char) 165){	
					putchar(c);
					cadena[j++] = c + 1;
					espacio = 1;
				}

           if(m == 1){
    				if(c >= 'a'){
					   if(c <= 'z'){
						  putchar(c);
						  cadena[j++] = c + 1;
						  espacio = 1;
					   }
				    }
                }
                
           if(m == 0){
				    if(c >= 'A'){
					   if(c <= 'Z'){
						  putchar(c);
						  cadena[j++] = c + 1;
						  espacio = 1;
					   }
				    }                        
          }
                
           if(m == 2){
    				if(c >= 'a'){
					   if(c <= 'z'){
						  putchar(c);
						  cadena[j++] = c + 1;
						  espacio = 1;
					   }
				    }
				    
				    if(c >= 'A'){
						   if(c <= 'Z'){
							  putchar(c);
							  cadena[j++] = c + 1;
							  espacio = 1;
						   }
					  }                        
       	   }
                
				if(c == ' '){
					if(espacio){
						putchar(c);
						cadena[j++] = ' ' + 1;
						espacio = 0;
					}
				}

			}else{
				putchar('\n');
				band = 0;
			}
		}else{
			putchar('\n');
			band = 0;
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
    
    puts(msg);
    
    if(positivo){
        while(1){
            num = leerEnteroPositivo();
        
            if(num >= r1 && num <= r2){
                return num;
            }else{
                puts(msgError);
            }
        }
    }else{
        while(1){
            
            num = leerEntero();
        
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
}