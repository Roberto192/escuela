#include "mathio.h"

int main(int argc, char const *argv[])
{

	char proposicion[MAX];
	int p[MAXCANT] = {TRUE, TRUE, FALSE, FALSE};
	int q[MAXCANT] = {TRUE, FALSE, TRUE, FALSE};
	int _p = TRUE;
	int _q = FALSE;
	int x[2];
	int pseudopila[2];
	int siuuuuu = 0;//es un contador

	TOKENS *tok;

	printf("    p\t  |\tq\n");
	for (int i = 0; i < MAXCANT; ++i)
	{
		printf("%s | %s\n",convert(p[i]),convert(q[i]));
	}

	printf("\n\n\n\n");
	printf("p es Verdadero y q es Falso\n");
	printf("No poner axiomas compuestas como p=q>(q_~p)\n");
	printf("Usar el ~ entre parentesis\n");
	printf("Ejemplo 1:\n");
	printf("-> (~p)^(~q)=q\n");
	printf("Salida: ");
	printf("Verdadero\n");
	printf("Esto indica que la igualdad se cumple\n");
	printf("Ejemplo 2:\n");
	printf("-> (~p)^q\n");
	printf("Salida: ");
	printf("Falso\n");
	printf("Esto indica que el axioma de falso ^ falso es falso\n");

	printf("Ingresa tu proposicion\n");
	printf("Negacion: ~\n");
	printf("Conjuncion: ^\n");
	printf("Disyuncion: _\n");
	printf("Condicional: >\n");
	printf("Bicondicional: =\n");
	printf("-> ");
	scanf(" %s",proposicion);

	if(strlen(proposicion) > 1){
		tok = getTokens(proposicion);

		for (int i = 0; i < tok[i].size; i++){
			if(notToken(proposicion[tok[i].L]) == notToken(proposicion[tok[i].R])){
				x[0] = (tok[i].Lchar == 'p')? _p : _q;
				x[1] = (tok[i].Rchar == 'p')? _p : _q;
					
				switch(tok[i].type){
					case '~':
						siuuuuu = (siuuuuu)? 0 : 1;
						pseudopila[siuuuuu] = negacionU(x[1]);
						break;
					case '^':
						pseudopila[siuuuuu] = conjuncion(x[0],x[1]);
						siuuuuu = (siuuuuu)? 0 : 1;
						break;
					case '_':
						pseudopila[siuuuuu] = disyuncion(x[0],x[1]);
						siuuuuu = (siuuuuu)? 0 : 1;
						break;
					case '>':
						pseudopila[siuuuuu] = condicional(x[0],x[1]);
						siuuuuu = (siuuuuu)? 0 : 1;
						break;
					case '<':
						pseudopila[siuuuuu] = condicional(x[1],x[0]);
						siuuuuu = (siuuuuu)? 0 : 1;
						break;
					case '=':
						pseudopila[siuuuuu] = bicondicional((siuuuuu)? pseudopila[siuuuuu] : x[0],x[1]);
						siuuuuu = (siuuuuu)? 0 : 1;
						break;
					case ':':
						if(siuuuuu){
							siuuuuu = 0;
							pseudopila[siuuuuu] = bicondicional(pseudopila[siuuuuu], x[1]);
						}else{
							pseudopila[siuuuuu] = bicondicional(x[0],x[1]);
								siuuuuu = (siuuuuu)? 0 : 1;
						}
						break;
				}
			}else{
				perror("Syntax Error!!!\n");
			}
		}

		printf("%s\n",convert(pseudopila[0]));
	}else{
		printf("%s",convert((proposicion[0] == 'p')? _p: _q ));
	}
	//for (int i = 0; i < tam; i++){
	//	printf("%c ",tok[i].type);
	//	printf("%i ",tok[i].pos);
	//	printf("%i ",tok[i].L);
	//	printf("%i ",tok[i].R);
	//	printf("\n");
	//}

	printf("\n");
	system("read -p ''");
	system("pause");
	return 0;
}