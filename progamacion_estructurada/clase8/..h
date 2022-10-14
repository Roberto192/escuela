
/*
    --------->     Libreria     <----------
    (Funciones de validar cadenas, cadenas)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
					cadena[j++] = c;
					espacio = 1;
				}

				if (c == (char) 165){	
					putchar(c);
					cadena[j++] = c;
					espacio = 1;
				}

                if(m == 1){
    				if(c >= 'a'){
					   if(c <= 'z'){
						  putchar(c);
						  cadena[j++] = c;
						  espacio = 1;
					   }
				    }
                }
                
                if(m == 0){
				    if(c >= 'A'){
					   if(c <= 'Z'){
						  putchar(c);
						  cadena[j++] = c;
						  espacio = 1;
					   }
				    }                        
                }
                
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
                }
                
				if(c == ' '){
					if(espacio){
						putchar(c);
						cadena[j++] = ' ';
						espacio = 0;
					}
				}

			}else{
				band = 0;
			}
		}else{
			band = 0;
		}
	}

	cadena[j] = '\0';
}

void imprimirArreglo(int miArreglo[], int n){
    int i;
    
    for(i = 0; i < n; i++){
        printf("%i [%d]\n",i,miArreglo[i]);
    }
}

void llaa(int miArreglo[], int n, int r1, int r2){//Llenar Arreglo Aleatorio
    int i;
    
    for(i = 0; i < n; i++){
        miArreglo[i] = (rand() % (r2 - r1)) + r1;
    }
    
}