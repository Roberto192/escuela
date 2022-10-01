#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i;
	
	for(i = 30; i < 108; i++){
		printf("\33[%dm",i);
		printf("%i a\33[0m\n",i);
	}

	return 0;
}