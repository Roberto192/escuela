#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifdef __unix__
	#define CLEAR system("clear");
#endif

#ifdef __WIN32
	#define CLEAR system("cls");
#endif
#define MAX 10
#define convertIC(x) #x

void menu();
void fibonnaciWhile();
void fibonnaciDoWhile();
void fibonnaciFor();
void factorialWhile();
void factorialDoWhile();
void factorialFor();
void cantidadDigitos();
void cicloFor();
void cicloWhile();
void cicloDoWhile();

int main(int argc, char const *argv[])
{

	char opcion[10];
	int bandera = 1;
	int si = 1;
	int op;

	while(bandera){

		do
		{
			printf("1._ Programa con ciclo while\n");
			printf("2._ Programa con ciclo Do while\n");
			printf("3._ Progama con ciclo for\n");
			printf("4._ Salir\n");

			fgets(opcion, 10, stdin);

			if(strcmp(opcion, "\n") != 0){
				si = 0;
			}
			op = atoi(opcion);
			if(!op){
				si = 1;
			}
			CLEAR;
		} while (si);

		if(op == 1){
			cicloWhile();
		}else{
			if(op == 2){
				cicloDoWhile();
			}else{
				if (op == 3){
					cicloFor();
				}else{
					if(op == 4){
						bandera = 0;
					}
				}
			}
		}


	}

	puts("Saliendo...");

	return 0;


}

void cicloWhile(){

	char opcion[MAX];
	int op;

	while(opcion[0] != 27){
		menu();
		printf("->");
		scanf(" %[^\n]",opcion);
		CLEAR;

		op = atoi(opcion);
		if( op == 1){
			fibonnaciWhile();
		}else{
			if ( op == 2){
				factorialWhile();
			}else{
				if( op == 3){
					cantidadDigitos();
				}else{
					if(opcion[0] != 27){
						printf("Ingrese un valor correcto: %s\n",opcion);
					}
				}
			}
		}
	}

}

void cicloDoWhile(){

	char opcion = ' ';

	do{
		menu();
		printf("->");
		scanf(" %c",&opcion);
		CLEAR;

		if( (opcion - 48) == 1){
			fibonnaciDoWhile();
		}else{
			if ( (opcion - 48 ) == 2){
				factorialDoWhile();
			}else{
				if( (opcion - 48) == 3){
					cantidadDigitos();
				}else{
					if(opcion != 27){
						printf("Ingrese un valor correcto: %c\n",opcion);
					}
				}
			}
		}
	}while(opcion != 27);

}

void cicloFor(){

	char opcion = ' ';

	for(;opcion != 27;){
		menu();
		printf("->");
		scanf(" %c",&opcion);
		CLEAR;

		if( (opcion - 48) == 1){
			fibonnaciFor();
		}else{
			if ( (opcion - 48 ) == 2){
				factorialFor();
			}else{
				if( (opcion - 48) == 3){
					cantidadDigitos();
				}else{
					if(opcion != 27){
						printf("Ingrese un valor correcto: %c\n",opcion);
					}
				}
			}
		}
	}

}

void menu(){

	puts("MEUWU");
	puts("[1] Fibonacci");
	puts("[2] Factorial");
	puts("[3] Cantidad de digitos");
	puts("[x] ESC + Enter para salir");

}

void fibonnaciFor(){

	char veces[MAX];

	unsigned long anterior = 0;
	unsigned long actual = 1;
	unsigned long suma = 0;
	int i;
	int n;

	printf("Ingrese la cantidad de veces a repetir\n");
	printf("->");
	scanf(" %[^\n]",veces);
	n = atoi(veces);

	for(i = 0; i < n; i++){
		printf("%lu\n",anterior);
		suma = anterior + actual;
		anterior = actual;
		actual = suma;
	}
	puts("");
}

void fibonnaciWhile(){

	char veces[MAX];

	unsigned long anterior = 0;
	unsigned long actual = 1;
	unsigned long suma = 0;
	int i;
	int n;

	printf("Ingrese la cantidad de veces a repetir\n");
	printf("->");
	scanf(" %[^\n]",veces);
	n = atoi(veces);

	i = 0;
	while(i++ < n){
		printf("%lu\n",anterior);
		suma = anterior + actual;
		anterior = actual;
		actual = suma;
	}
	puts("");
}


void fibonnaciDoWhile(){

	char veces[MAX];

	unsigned long anterior = 0;
	unsigned long actual = 1;
	unsigned long suma = 0;
	int i;
	int n;

	printf("Ingrese la cantidad de veces a repetir\n");
	printf("->");
	scanf(" %[^\n]",veces);
	n = atoi(veces);

	i = 0;
	do{
		printf("%lu\n",anterior);
		suma = anterior + actual;
		anterior = actual;
		actual = suma;
	}while(++i < n);

	puts("");
}


void factorialFor(){

	char cadenaDeNumero[MAX];
	int numeroFactorial = 0;
	unsigned long totalFactorial = 1;
	int i;

	printf("Ingrese el numero del factorial\n");
	printf("->");

	scanf(" %[^\n]",cadenaDeNumero);

	numeroFactorial = atoi(cadenaDeNumero);

	if(numeroFactorial > 0){
		for (i = numeroFactorial; i > 1; i--){
			totalFactorial *= (unsigned long) i;
		}

		printf("Factorial de %d! = %lu",numeroFactorial, totalFactorial);
	}else{
		if(!numeroFactorial){
			printf("Factorial de 0! = 1");
		}else{
			printf("Ingrese un valor mayor a 0");
		}
	}
	puts("");
}

void factorialWhile(){

	char cadenaDeNumero[MAX];
	int numeroFactorial = 0;
	unsigned long totalFactorial = 1;
	int i;

	printf("Ingrese el numero del factorial\n");
	printf("->");

	scanf(" %[^\n]",cadenaDeNumero);

	numeroFactorial = atoi(cadenaDeNumero);

	if(numeroFactorial > 0){
		i = numeroFactorial;
		while(i > 1){
			totalFactorial *= (unsigned long) i--;
		}
		printf("Factorial de %d! = %lu",numeroFactorial, totalFactorial);
	}else{
		if(!numeroFactorial){
			printf("Factorial de 0! = 1");
		}else{
			printf("Ingrese un valor mayor a 0");
		}
	}
	puts("");
}


void factorialDoWhile(){

	char cadenaDeNumero[MAX];
	int numeroFactorial = 0;
	unsigned long totalFactorial = 1;
	int i;

	printf("Ingrese el numero del factorial\n");
	printf("->");

	scanf(" %[^\n]",cadenaDeNumero);

	numeroFactorial = atoi(cadenaDeNumero);

	if(numeroFactorial > 0){
		i = numeroFactorial;
		do{
			totalFactorial *= (unsigned long) i--;
		}while(i != 0);
		printf("Factorial de %d! = %lu",numeroFactorial, totalFactorial);
	}else{
		if(!numeroFactorial){
			printf("Factorial de 0! = 1");
		}else{
			printf("Ingrese un valor mayor a 0");
		}
	}
	puts("");
}

void cantidadDigitos(){

	char cadenaDeNumero[MAX];
	int numero = 0;
	int size = 0;

	printf("Ingrese un numero diferente a 0\n");
	printf("->");
	scanf(" %[^\n]",cadenaDeNumero);

	numero = atoi(cadenaDeNumero);

	if (!numero){
		printf("Ingrese un numero valido");
	}else{
		size = snprintf(NULL, 0, "%d", numero);
		printf("El numero %d consta de %d digitos",numero,size);
	}
	puts("");
}