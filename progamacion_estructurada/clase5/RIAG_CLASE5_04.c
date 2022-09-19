#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int n1, n2, n3;

	printf("Dame tres numero\n");
	printf("Primer numero\n");
	scanf(" %i",&n1);
	printf("Segundo numero\n");
	scanf(" %i",&n2);
	printf("Tercero numero\n");
	scanf(" %i",&n3);
	
	if(n1 > n2 && n1 > n3)
	{
		printf("Numero 1 es mayor");
	}

	if (n2 > n1 && n2 > n3)
	{
		printf("Numero 2 es mayor");
	}

	if (n3 > n1 && n3 > n2)
	{
		printf("Numero 3 es mayor");
	}

	printf("\n");

	system("read -p ''");

	return 0;
}