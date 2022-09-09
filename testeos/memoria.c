#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	/*
	int arreglo[10] = {1,2,3,4,5,6,7,8,9,10};

	for(int i = 0; i < (int) sizeof(arreglo)/sizeof(int); i++){
		printf("%i\n",*arreglo);
		(*arreglo)++;
	}

	for(int i = 0; i < (int) sizeof(arreglo)/sizeof(int); i++){
		printf("%p\n",&arreglo[i]);
	}*/

	int *i,a;

	i = (int *) malloc(sizeof(int));

	i = &a;

	printf("%p\n",&a);
	printf("%p\n",&i);
	printf("%p\n",&(*i));
	printf("%p\n",&a);

	return 0;
}