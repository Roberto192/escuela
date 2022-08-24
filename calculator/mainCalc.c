#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headerCalc.h"

int main(int argc, char const *argv[])
{

	PILA *pila = createNewPila(9.2);

	pila = pushPila(pila, 2.1);
	pila = pushPila(pila, 3.1);
	pila = pushPila(pila, 4.1);
	pila = pushPila(pila, 5.1);
	pila = pushPila(pila, 6.1);
	pila = popPila(pila);


	printf("%.2f\n",pila->number);

	return 0;
}