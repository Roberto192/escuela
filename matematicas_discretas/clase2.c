#include <stdio.h>
#include <stdlib.h>
#include "condicionales.h"
#include "ventanas.h"

int main(int argc, char const *argv[])
{
	
	int datos[4][2] = { {TRUE, TRUE},
						  {TRUE, FALSE},
						  {FALSE, TRUE},
						  {FALSE, FALSE} };

	int datosusuario[8][2];
	int len;
	int variable;	  

	char operador;

	printf("Ingrese la cantidad de datos\n");
	scanf(" %i",&len);

	printf("Ingrese los datos de p y q (0/FALSE) (1/TRUE)\n");
	ponerCaracterEnXY(4, 4, 'p');
	ponerCaracterEnXY(8, 4, 'q');
	for (int i = 0; i < len; i++)
	{
		iraXY(4,i + 5);
		scanf("%i",&datosusuario[i][0]);
		iraXY(8,i + 5);
		scanf("%i",&datosusuario[i][1]);
		printf("\n");
	}


	printf("Ingrese el operador\n");
	scanf(" %c",&operador);
	switch(operador){
		case '!':
			printf("Ingrese la variable (p/0) (q/1) \n");
			scanf(" %i",&variable);

			iraXY(20, 4);
			printf("Negacion:\n");
			for (int i = 0; i < len; ++i)
			{
				iraXY(20,i + 5);
				printf("%i",negacionU(datosusuario[i][variable]));
			}
		break;
		case '&':
			iraXY(20, 4);
			printf("and:\n");

			for (int i = 0; i < len; ++i)
			{
				iraXY(20,i + 5);
				printf("%i",conjuncion(datosusuario[i][1], datosusuario[i][0]));
			}	
		break;
		case '|':
			iraXY(20, 4);
			printf("or: \n");

			for (int i = 0; i < len; i++)
			{
				iraXY(20,i + 5);	
				printf("%i",disyuncion(datosusuario[i][0], datosusuario[i][1]));
			}	
		break;
		case '>':
			
			iraXY(20, 4);
			printf("condicional p -> q: \n");

			for (int i = 0; i < len; i++)
			{
				iraXY(20,i + 5);	
				printf("%i",condicional(datosusuario[i][0], datosusuario[i][1]));
			}	
		break;
		case '<':
			
			iraXY(20, 4);
			printf("condicional q -> p: \n");

			for (int i = 0; i < len; i++)
			{
				iraXY(20,i + 5);	
				printf("%i",condicional(datosusuario[i][1], datosusuario[i][0]));
			}	
		break;
		case '-':
			
			iraXY(20, 4);
			printf("bicondicional: \n");

			for (int i = 0; i < len; i++)
			{
				iraXY(20,i + 5);	
				printf("%i",bicondicional(datosusuario[i][0], datosusuario[i][1]));
			}	
		break;
	}

	PAUSE;

	return 0;
}