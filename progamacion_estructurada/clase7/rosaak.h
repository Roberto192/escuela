#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define stdlin putc(10, stdout)

int longitud(char *);
void quitarCaracter(char *, int);
void imprimirCadena(char *);
char *voltearCadena(char *);
void imprimirCadenaHorizontal(char *);
void recortarPorDerechaCadena(char *);
void recortarPorIzquierdaCadena(char *);
void quitarUnCaracter(char *, char);
void vocales(char *, int);
void mayusculas(char *);


int longitud(char *cadena){
	int i;
	for(i = 0; cadena[i] != '\0'; i++);
	return i - 1;
}

void quitarCaracter(char *cadena, int x){
	int i;
	char *aux = malloc(longitud(cadena));
	char *mem = &(*aux);

	for (i = 0; cadena[i] != '\0'; i++){
		if(cadena[i] != x){
			*(aux++) = cadena[i];
		}
	}

	aux = mem;
	strcpy(cadena, aux);

	free(aux);
}

void imprimirCadena(char *cadena){
	int i = 31;
	while(*cadena != '\0'){
		printf("\33[%dm",(++i > 36)? i = 31 : i);
		putc(*(cadena++), stdout);
		printf("\33[0m");
	}
}

char *voltearCadena(char *cadena){
	int i;
	int lon = longitud(cadena);
	char *aux =(char *) malloc(lon + 1);

	for (i = lon; i >= 0; i--){
		aux[lon - i] = cadena[i];
	}

	aux[lon + 1] = '\0';

	return aux;
}

void imprimirCadenaHorizontal(char *cadena){
	int i = 31;
	while(*cadena != '\0'){
		printf("\33[%dm",(++i > 37)? i = 31 : i);
		putc(*(cadena++), stdout);
		stdlin;
		printf("\33[0m");
	}
}

void recortarPorDerechaCadena(char *cadena){
	int lon = longitud(cadena);
	char *aux = (char *) malloc(lon);
	strcpy(aux, cadena);

	while(lon != -1){
		imprimirCadena(aux);
		stdlin;
		aux[lon--] = '\0';
	}

	free(aux);

}

void quitarUnCaracter(char *cadena, char caracter){
	int i;
	int lon = longitud(cadena);
	if(lon != 0){
		char *aux = malloc(lon);
		char *mem = &(*aux);
		int bandera = 0;
	
		for (i = 0; i < lon + 1; i++){
			if(cadena[i] == caracter){
				if(bandera == 0){
					bandera = 1;
				}else{
					*(aux++) = cadena[i];
				}
			}else{
				*(aux++) = cadena[i];
			}
		}

		*aux = '\0';
		aux = mem;
	
		strcpy(cadena, aux);
		free(aux);
	}


}

void recortarPorIzquierdaCadena(char *cadena){
	int i;
	int lon = longitud(cadena);	
	char *aux = (char *) malloc(lon);
	strcpy(aux, cadena);
	/*printf("%p\n",aux);
	printf("%p\n",cadena);*/
	for (i = 0; i < lon + 1; i++){
		imprimirCadena(aux);
		stdlin;
		quitarUnCaracter(aux, cadena[i]);
	}
	free(aux);
}

void vocales(char *cadena, int si){
	int i;
	int j = 30;
	if(si){
		for (i = 0; cadena[i] != '\0'; i++){
			printf("\33[%dm",(++j > 37)? j = 31 : j);
			if(cadena[i] == 'A'){
				putc(cadena[i], stdout);
			}else{
				if(cadena[i] == 'a'){
					putc(cadena[i], stdout);
				}else{
					if(cadena[i] == 'E'){
						putc(cadena[i], stdout);
					}else{
						if(cadena[i] == 'e'){
							putc(cadena[i], stdout);
						}else{
							if(cadena[i] == 'I'){
								putc(cadena[i], stdout);
							}else{
								if(cadena[i] == 'i'){
									putc(cadena[i], stdout);
								}else{
									if(cadena[i] == 'O'){
										putc(cadena[i], stdout);
									}else{
										if(cadena[i] == 'o'){
											putc(cadena[i], stdout);
										}else{
											if(cadena[i] == 'U'){
												putc(cadena[i], stdout);
											}else{
												if(cadena[i] == 'u'){
													
													putc(cadena[i], stdout);
													
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			printf("\33[0m");
		}
	}else{
		for (i = 0; cadena[i] != '\0'; i++){
			printf("\33[%dm",(++j > 37)? j = 31 : j);
			if(cadena[i] != 'A'){
				if(cadena[i] != 'a'){
					if(cadena[i] != 'I'){
						if(cadena[i] != 'i'){
							if(cadena[i] != 'E'){
								if(cadena[i] != 'e'){
									if(cadena[i] != 'O'){
										if(cadena[i] != 'o'){
											if(cadena[i] != 'U'){
												if(cadena[i] != 'u'){
													putc(cadena[i], stdout);
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			printf("\33[0m");
		}
	}

	stdlin;
}

void mayusculas(char *cadena){
	int i;
	for (i = 0; i < longitud(cadena) + 1; ++i){
		if(cadena[i] >= 'a'){
			if(cadena[i] <= 'z'){
				cadena[i] -= 32;
			}
		}
	}
}