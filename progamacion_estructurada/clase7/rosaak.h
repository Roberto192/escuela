#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define JMPL putc(10, stdout)

int longitud(char *);
void quitarCaracteres(char *, int);
void imprimirCadena(char *);
char *voltearCadena(char *);
void imprimirCadenaHorizontal(char *);
void recortarPorDerechaCadena(char *);
void recortarPorIzquierdaCadena(char *);
void quitarUnCaracter(char *, char);
void vocales(char *, int);
void mayusculas(char *);
void minusculas(char *);
void quitarEspaciosExtras(char *);
void Capitalizar(char *);
char *quitarEspacios(char *);
int abc(char *);

int longitudMax(char *cadena){
	int i;
	for (i = 0; cadena[i] != '\0' ; i++);
	return i;
}

int longitud(char *cadena){
	int i;
	for(i = 0; cadena[i] != '\0'; i++);
	return i - 1;
}

void quitarCaracteres(char *cadena, int x){
	int i;
	char *aux = (char *) malloc(longitud(cadena));
	char *mem = &(*aux);

	for (i = 0; cadena[i] != '\0'; i++){
		if(cadena[i] != x){
			*(aux++) = cadena[i];
		}
	}

	*aux = '\0';
	aux = mem;
	strcpy(cadena, aux);

	free(aux);
}

void imprimirCadena(char *cadena){
	int i = 31;
	while(*cadena != '\0'){
		putc(*(cadena++), stdout);
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
		(++i > 37)? i = 31 : i;
		putc(*(cadena++), stdout);
		JMPL;
	}
}

void recortarPorDerechaCadena(char *cadena){
	int lon = longitud(cadena);
	char *aux = (char *) malloc(lon);
	strcpy(aux, cadena);

	while(lon != -1){
		imprimirCadena(aux);
		JMPL;
		aux[lon--] = '\0';
	}

	free(aux);

}

void quitarUnCaracter(char *cadena, char caracter){
	int i;
	int lon = longitud(cadena);
	if(lon != 0){
		char *aux = (char *) malloc(lon);
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
		JMPL;
		quitarUnCaracter(aux, cadena[i]);
	}
	free(aux);
}

void vocales(char *cadena, int si){
	int i;
	int j = 30;
	if(si){
		for (i = 0; cadena[i] != '\0'; i++){
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
		}
	}else{
		for (i = 0; cadena[i] != '\0'; i++){
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
		}
	}

	JMPL;
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

void minusculas(char *cadena){
	int i;
	for (i = 0; i < longitud(cadena) + 1; ++i){
		if(cadena[i] >= 'A'){
			if(cadena[i] <= 'Z'){
				cadena[i] += 32;
			}
		}
	}
}

void quitarEspaciosExtras(char *cadena){
	int i;
	int lon;

	lon = longitud(cadena);
	
	if(cadena[lon] == '\n'){
		if(cadena[lon - 1] == ' '){
			cadena[lon] = '\0';
			cadena[lon - 1] = '\n';
		}
	}

	if(cadena[lon] == ' '){
		cadena[lon] = '\0';
	}

	if(cadena[0] == ' '){
		for(i = 0; i < lon; i++){
			cadena[i] = cadena[i + 1];
		}
		cadena[lon] = '\0';
	}

}

void Capitalizar(char *cadena){
	int i;
	int lon = longitud(cadena);
	int centinela = 1;
	quitarEspaciosExtras(cadena);
	
	for (i = 0; i < lon; i++){
		if(centinela){
			if(cadena[i] >= 'a'){
				if(cadena[i] <= 'z'){
					cadena[i] -= 32;
					centinela = 0;
				}
			}
		}

		if(cadena[i] == ' '){
			centinela = 1;
		}
	}

}

char *quitarEspacios(char *cadena){
	char *miCadena = (char *) malloc(longitudMax(cadena));
	strcpy(miCadena, cadena);
	quitarCaracteres(miCadena, ' ');
	return miCadena;
}