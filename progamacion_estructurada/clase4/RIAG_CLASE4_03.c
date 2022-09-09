//		clase4_03
/*		3.- Programa en C que lea 6 números, desplegar el valor del número mayor.*/		
//		Nombre: Roberto Isaac Arias Guerrero Matricula: 1292118
//		2022/08/31

#include <stdio.h>
#include <stdlib.h>
/*
int main(int argc, char const *argv[])
{


	int n1, n2, n3, n4, n5, n6, numeroMayor;

	printf("Programa que lee 6 numeros\n");
	printf("Ingrese el numero 1: ");
	scanf(" %i",&n1);
	printf("Ingrese el numero 2: ");
	scanf(" %i",&n2);
	printf("Ingrese el numero 3: ");
	scanf(" %i",&n3);
	printf("Ingrese el numero 4: ");
	scanf(" %i",&n4);
	printf("Ingrese el numero 5: ");
	scanf(" %i",&n5);
	printf("Ingrese el numero 6: ");
	scanf(" %i",&n6);

	numeroMayor = n1;

	if (n2 > numeroMayor)
	{
		numeroMayor = n2;
	}

	if (n3 > numeroMayor)
	{
		numeroMayor = n3;
	}

	if (n4 > numeroMayor)
	{
		numeroMayor = n4;
	}

	if(n5 > numeroMayor)
	{
		numeroMayor = n5;
	}

	if (n6 > numeroMayor)
	{
		numeroMayor = n6;
	}

	printf("Numero mayor es el %i\n",numeroMayor);

	system("read -p ''");

	return 0;
}
*/
int main(int argc, char const *argv[])
{
	

	int n1, n2, n3, n4, n5, n6, numeroMayor;

	printf("Programa que lee 6 numeros\n");
	printf("Ingrese el numero 1: ");
	scanf(" %i",&n1);
	printf("Ingrese el numero 2: ");
	scanf(" %i",&n2);
	printf("Ingrese el numero 3: ");
	scanf(" %i",&n3);
	printf("Ingrese el numero 4: ");
	scanf(" %i",&n4);
	printf("Ingrese el numero 5: ");
	scanf(" %i",&n5);
	printf("Ingrese el numero 6: ");
	scanf(" %i",&n6);
	// 30 10 12 13 40 50
	if(n1 > n2){
		if(n1 > n3){
			if(n1 > n4){
				if(n1 > n5){
					if(n1 > n6){
						printf("Numero 1 es el mayor\n");
					}else{
						printf("Numero 6 es el mayor\n");
					}
				}else{
					if(n5 > n6){
						printf("Numero 5 es el mayor\n");
					}else{
						printf("Numero 6 es el mayor\n");
					}
				}
			}else{
				if(n4 > n5){
					if(n4 > n6){
						printf("Numero 4 es el mayor\n");
					}else{
						printf("Numero 6 es el mayor\n");
					}
				}else{
					if(n5 > n6){
						printf("Numero 5 es el mayor\n");
					}else{
						printf("Numero 6 es el mayor\n");
					}
				}
			}
		}else{
			if(n3 > n4){
				if(n3 > n5){
					if(n3 > n6){
						printf("Numero 3 es el mayor\n");
					}else{
						printf("Numero 6 es el mayor\n");
					}
				}else{
					if(n5 > n6){
						printf("Numero 5 es el mayor\n");
					}else{
						printf("Numero 6 es el mayor\n");
					}
				}
			}else{
				if(n4 > n5){
					if(n4 > n6){
						printf("Numero 4 es el mayor\n");
					}else{
						printf("Numero 6 es el mayor\n");
					}
				}else{
					if(n5 > n6){
						printf("Numero 5 es el mayor\n");
					}else{
						printf("Numero 6 es el mayor\n");
					}
				}
			}
		}
	}else{
		if(n2 > n3){
			if(n2 > n4){
				if(n2 > n5){
					if(n2 > n6){
						printf("Numero 2 es el mayor\n");
					}else{
						printf("Numero 6 es el mayor\n");
					}
				}else{
					if(n5 > n6){
						printf("Numero 5 es el mayor\n");
					}else{
						printf("Numero 6 es el mayor\n");
					}
				}
			}else{
				if(n4 > n5){
					if(n4 > n6){
						printf("Numero 4 es el mayor\n");
					}else{
						printf("Numero 6 es el mayor\n");
					}
				}else{
					if(n5 > n6){
						printf("Numero 5 es el mayor\n");
					}else{
						printf("Numero 6 es el mayor\n");
					}
				}
			}
		}else{
			if(n3 > n4){
				if(n3 > n5){
					if(n3 > n6){
						printf("Numero 3 es el mayor\n");
					}else{
						printf("Numero 6 es el mayor\n");
					}
				}else{
					if(n5 > n6){
						printf("Numero 5 es el mayor\n");
					}else{
						printf("Numero 6 es el mayor\n");
					}
				}
			}else{
				if(n4 > n5){
					if(n4 > n6){
						printf("Numero 4 es el mayor\n");
					}else{
						printf("Numero 6 es el mayor\n");
					}
				}else{
					if(n5 > n6){
						printf("Numero 5 es el mayor\n");
					}else{
						printf("Numero 6 es el mayor\n");
					}
				}
			}
		}
	}

	system("read -p ''");

	return 0;
}