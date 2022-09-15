#include <stdlib.h>
#include <stdio.h>
#include "mathio.h"

int main(int argc, char const *argv[])
{
	
	int p[MAXCANT] = {TRUE, TRUE, FALSE, FALSE};
	int q[MAXCANT] = {TRUE, FALSE, TRUE, FALSE};

	int _p = TRUE;
	int _q = FALSE;

	int len;
	
	//NEWTOKENS *tok, buffTok;

	char proposicion[MAX];
	char **proposicionDes;

	printf("    p\t  |\tq\n");
	for (int i = 0; i < MAXCANT; ++i){
		printf("%s | %s\n",convert(p[i]),convert(q[i]));
	}

	printf("\n\n\n\n");
	printf("Presione << ctrl + c >> para salir\n");
	printf("Ingresa tu axioma para resolver paso a paso\n");
	printf("p es Verdadero, q es Falso\n");
	printf("Ejemplo de entrada: p=p\n");//~p
	printf("Salida Verdadero\n");//falso

	printf("Negacion: ~\n");
	printf("Conjuncion: ^\n");
	printf("Disyuncion: _\n");
	printf("Condicional: >\n");
	printf("Bicondicional: =\n");
	printf("-> ");//p=q:(p>q)^(q>p)

	while(1){
		JUMPLINE;
		scanf(" %s",proposicion);

		if(strlen(proposicion) == 1){
			printf("%s",convert((proposicion[0] == 'p')? _p : _q));
		}else{
			if(strlen(proposicion) == 2){
				if(proposicion[0] == '~'){
					printf("%s",convert(negacionU((proposicion[1] == 'p')? _p : _q)));
				}
			}else{
				if (strlen(proposicion) >= 3){
					printf("%s",convert(solve(proposicion)));
				}
			}
		}
	}


	JUMPLINE;
	system("read -p ''");
	return 0;
}