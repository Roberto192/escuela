#include <stdio.h>
#include <stdlib.h>
#include "validar.h"

#define FILE_NAME "datos.data"
#define MAX_NAME 50

#define PAUSE system("pause >> nul")

void menu(char *[], int);
void crear();
void verCuentasEnZero();
void verCuentasConSaldo();
void verCuentasConDeuda();
void verCuentas();

int main(){
    
    char *_menu[] = {"MENU",
                    "[1] Crear cliente",
                    "[2] Ver cuantas en cero",
                    "[3] Ver cuantas con saldo",
                    "[4] Ver cuentas con deuda",
                    "[5] Ver todas las cuentas",
                    "[6] Salir"};
    int controlador = 1;
    int op;
    
    while(controlador){
        menu(_menu, 7);
        op = validarNumeroICR("Ingrese un numero: ", "Ingrese un numero valido", 1, 1, 6);
        switch(op){
            case 1:
                crear();
                PAUSE;
            break;
            case 2:
                verCuentasEnZero();
                PAUSE;
            break;
            case 3:
                verCuentasConSaldo();
                PAUSE;
            break;
            case 4:
                verCuentasConDeuda();
                PAUSE;
            break;
            case 5:
                verCuentas();
                PAUSE;
            break;
            case 6:
                controlador = 0;
            break;
        }
    }

  return 0;
}

void menu(char *text[], int n){
    int i;
    system("cls");
    for(i = 0; i < n; i++)
        puts(text[i]);
}

void crear(){
    FILE *datos;
    
    char nombre[MAX_NAME];
    int id;
    int saldo;
    
    datos = fopen(FILE_NAME, "a");
    
    id = validarNumeroISR("Ingrese un id del usuario", 1);
    validarTexto( "Ingrese el nombre: ", nombre, MAX_NAME,2);
    saldo = validarNumeroISR("Ingrese el saldo de la cuenta: ", 0);
    
    fprintf(datos, "%d/%s/%d\n",id, nombre, saldo);
    
    fclose(datos);
}

void verCuentasEnZero(){
    FILE *datos;
    
    int controlador = 0;
    int i = 0;
    char nombre[MAX_NAME + 1];
    char c;
    char id[10];
    char saldo[10];
    
    datos = fopen(FILE_NAME, "a+");
    if(datos != NULL){
        while(c != EOF){
            c = fgetc(datos);
            if(c == '/' || c == '\n'){
                 controlador++;
                 i = 0;
            }else{
            
                if(controlador > 2){
                    controlador = i = 0;
                    if(atoi(saldo) == 0){
                        printf("ID: %4s Nombre: %-30s Saldo: %s\n",id,nombre,saldo);
                    }
                    
                }
            
                if(controlador == 0){
                    id[i++] = c;
                    id[i] = '\0';
                }else{
                    if(controlador == 1){
                        nombre[i++] = c - 1;
                        nombre[i] = '\0';
                    }else{
                        saldo[i++] = c;
                        saldo[i] = '\0';
                    }
                }
            }
        }
    }else{
        printf("No se pudo abrir\n");
    } 
        
    fclose(datos);
}

void verCuentasConDeuda(){
    FILE *datos;
    
    int controlador = 0;
    int i = 0;
    char nombre[MAX_NAME + 1];
    char c;
    char id[10];
    char saldo[10];
    
    datos = fopen(FILE_NAME, "a+");
    if(datos != NULL){
        while(c != EOF){
            c = fgetc(datos);
            if(c == '/' || c == '\n'){
                 controlador++;
                 i = 0;
            }else{
            
                if(controlador > 2){
                    controlador = i = 0;
                    if(atoi(saldo) < 0){
                        printf("ID: %4s Nombre: %-30s Saldo: %s\n",id,nombre,saldo);
                    }
                    
                }
            
                if(controlador == 0){
                    id[i++] = c;
                    id[i] = '\0';
                }else{
                    if(controlador == 1){
                        nombre[i++] = c - 1;
                        nombre[i] = '\0';
                    }else{
                        saldo[i++] = c;
                        saldo[i] = '\0';
                    }
                }
            }
        }
    }else{
        printf("No se pudo abrir\n");
    } 
        
    fclose(datos);
}

void verCuentasConSaldo(){
    FILE *datos;
    
    int controlador = 0;
    int i = 0;
    char nombre[MAX_NAME + 1];
    char c;
    char id[10];
    char saldo[10];
    
    datos = fopen(FILE_NAME, "a+");
    if(datos != NULL){
        while(c != EOF){
            c = fgetc(datos);
            if(c == '/' || c == '\n'){
                 controlador++;
                 i = 0;
            }else{
            
                if(controlador > 2){
                    controlador = i = 0;
                    if(atoi(saldo) > 0){
                        printf("ID: %4s Nombre: %-30s Saldo: %s\n",id,nombre,saldo);
                    }
                    
                }
            
                if(controlador == 0){
                    id[i++] = c;
                    id[i] = '\0';
                }else{
                    if(controlador == 1){
                        nombre[i++] = c - 1;
                        nombre[i] = '\0';
                    }else{
                        saldo[i++] = c;
                        saldo[i] = '\0';
                    }
                }
            }
        }
    }else{
        printf("No se pudo abrir\n");
    } 
        
    fclose(datos);
}

void verCuentas(){
    FILE *datos;
    
    int controlador = 0;
    int i = 0;
    char nombre[MAX_NAME + 1];
    char c;
    char id[10];
    char saldo[10];
    
    datos = fopen(FILE_NAME, "a+");
    if(datos != NULL){
        while(c != EOF){
            c = fgetc(datos);
            if(c == '/' || c == '\n'){
                 controlador++;
                 i = 0;
            }else{
            
                if(controlador > 2){
                    controlador = i = 0;
                    printf("ID: %4s Nombre: %-30s Saldo: %s\n",id,nombre,saldo);
                }
            
                if(controlador == 0){
                    id[i++] = c;
                    id[i] = '\0';
                }else{
                    if(controlador == 1){
                        nombre[i++] = c - 1;
                        nombre[i] = '\0';
                    }else{
                        saldo[i++] = c;
                        saldo[i] = '\0';
                    }
                }
            }
        }
    }else{
        printf("No se pudo abrir\n");
    } 
        
    fclose(datos);
}