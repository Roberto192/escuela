#include <stdio.h>

void myFunction(int p){

	printf("Hello world %d\n",p);

}

void run(void fun(), int p){
	fun(p);
}

int main(int argc, char const *argv[])
{

	run(myFunction, 10);

	return 0;
}