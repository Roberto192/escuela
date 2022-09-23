#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

	int cantidadIngresar;
	float i;

	printf("int: %lu\n",sizeof(int));
	printf("float: %lu\n",sizeof(float));
	printf("char: %lu\n",sizeof(char));
	printf("double: %lu\n",sizeof(double));

	printf("Ingresar datos a ingresar\n");
	printf("->");
	scanf(" %i",&cantidadIngresar);

	for (i = 0; i < cantidadIngresar; i += 0.00002)
	{
		printf("%f\n",i);
	}

	printf("%i", (1 % 2));

	system("read -p ''");
	return 0;
}
