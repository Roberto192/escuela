#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	char *miString = "Hola mundo";

	for (int i = 0; miString[i] != '\0'; i++){
		putc(miString[i], stdout);
	}

	return 0;
}