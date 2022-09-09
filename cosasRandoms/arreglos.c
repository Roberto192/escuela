#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void addValor(int *&, int);

int main(int argc, char const *argv[])
{
	
	const char* title = argv[1];
	char* systemTitle;
	if (title == 0)
	{
		title = "Hola Mundo";
	}

	sprintf(systemTitle, "title %s", title);
	system(systemTitle);

	int A[10],*B,*C;
	int i;


	for (i = 0; i < 10; i++)
	{
		scanf("%i",&A[i]);
		printf("Numero digitado %d\n",A[i] );
	}

	system("cls");

	for (i = 0; i < 10; i++)
	{
		if (A[i] % 2 == 0)
		{
			addValor(B, A[i]);
		}
	}

	getch();

	return 0;
}

void addValor(int *&point, int valor){
	
	printf("Hola");
	size_t n = sizeof(point)/sizeof(point[0]);
	point[n+1] = valor;
	printf("%d\n",point[n+1]);
}