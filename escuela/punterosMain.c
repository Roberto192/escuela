#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	
	int a;
	int *puntero;

	a = 7;
	puntero = &a;
	scanf(" %i",&*puntero);

	printf("La direccion de a es %p\nEl valor del puntero es %p\n",&a,puntero);
	printf("El valor de a es %d\nEl valor del apuntador es %d\n",a,*puntero);
	printf("Direccion de puntero: %p\n\n",&puntero);

	printf("Demostrando que * y & son complementarios entre si.\n&*puntero = %p\n*&puntero = %p\n",&*puntero,*&puntero);

	return 0;
}