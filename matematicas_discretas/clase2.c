#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int negacion(int v1, int v2){
	if (v1 == TRUE && v2 == TRUE){
		return FALSE;
	}

	if (v1 == FALSE && v2 == TRUE){
		return FALSE;
	}

	return TRUE;
}

int conjuncion(int v1, int v2){
	if(v1 == TRUE && v2 == TRUE){
		return TRUE;
	}

	return FALSE;
}

int disyuncion(int v1, int v2){

	if(v1 == FALSE && v2 == FALSE){
		return FALSE;
	}

	return TRUE;
}

int condicional(int v1, int v2){
	if(v1 == TRUE && v2 == FALSE){
		return FALSE;
	}

	return TRUE;
}

int bicondicional(int v1, int v2){
	if(v1 == v2){
		return TRUE;
	}

	return FALSE;
}

int main(int argc, char const *argv[])
{
	
	int datos[4][2] = { {TRUE, TRUE},
						  {TRUE, FALSE},
						  {FALSE, TRUE},
						  {FALSE, FALSE} };

	int datosusuario[4][2];					  

	printf("negacion\n");
	for (int i = 0; i < 4; i++)
	{
		printf("%i %i %i\n",datos[i][0],datos[i][1],negacion(datos[i][0],datos[i][1]));
	}
	printf("conjuncion\n");
	for (int i = 0; i < 4; i++)
	{
		printf("%i %i %i\n",datos[i][0],datos[i][1],conjuncion(datos[i][0],datos[i][1]));
	}
	printf("disyuncion\n");
	for (int i = 0; i < 4; i++)
	{
		printf("%i %i %i\n",datos[i][0],datos[i][1],disyuncion(datos[i][0],datos[i][1]));
	}
	printf("condicional\n");
	for (int i = 0; i < 4; i++)
	{
		printf("%i %i %i\n",datos[i][0],datos[i][1],condicional(datos[i][0],datos[i][1]));
	}
	printf("bicondicional\n");
	for (int i = 0; i < 4; i++)
	{
		printf("%i %i %i\n",datos[i][0],datos[i][1],bicondicional(datos[i][0],datos[i][1]));
	}

	for (int i = 0; i < 1; i++)
	{
		printf("Primer (0/FALSE) (1/TRUE)\n");
		scanf("%i",&datosusuario[i][0]);
		printf("segundo dato (0/FALSE) (1/TRUE)\n");
		scanf("%i",&datosusuario[i][1]);
		printf("\n");
	}

	printf("Listo...\n");

	printf("bicondicional\t== codicional(a->b)\t^\tcondicional(b->a)\tresultados\n");

	for (int i = 0; i < 1; ++i)
	{
		printf("%i   %i   %i\t\t%i   %i   %i\t\t%i   %i   %i\t\t %i\n",datosusuario[i][0],datosusuario[i][1],bicondicional(datosusuario[i][0],datosusuario[i][1]),
												datosusuario[i][0],datosusuario[i][1],condicional(datosusuario[i][0],datosusuario[i][1]),
												datosusuario[i][1],datosusuario[i][0],condicional(datosusuario[i][1],datosusuario[i][0]),
												bicondicional(condicional(datosusuario[i][0],datosusuario[i][1]), condicional(datosusuario[i][1],datosusuario[i][0])));
	}

	return 0;
}