#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 8

/*

	( )
	^ r
	* /
	+ -

*/

struct BIN_TREE
{

	float number;
	char data;
	
};
//santuary RPG

struct BIN_TREE *newNodo(char c, float n){

	size_t buff = sizeof(struct BIN_TREE);
	struct BIN_TREE *bt = (struct BIN_TREE *) malloc(buff);

	if(c != NULL){
		bt->data = c;
	}else if (n != NULL){
		bt->number = n;
	}else{
		printf("\a\a\a\aError... ingrese un valor correcto");
	}
	bt->lt = bt->rt = NULL;


	return bt;
}

void addNumberTree(struct BIN_TREE *bt, float n){

	if (bt->lt == NULL){
		bt->lt = newNodo(NULL, n);
	}else{
		addNumberTree(bt->lt, n);
	}

}

void addDataTree(struct BIN_TREE *bt, char c){


	if(c == 'r' || c == '^' || c == '*' || c == '/' || c == '+' || c == '-'){
		if (bt->rt == NULL){
			bt->rt = newNodo(c);
		}else{
			addDataTree(bt->rt, c);
		}
	}else if(bt){
		if(bt->lt == NULL){
			bt->lt = newNodo(c);
		}else{
			addDataTree(bt->lt, c);
		}
	}else{
		printf("\a\a\a\a\a\aError...");
	}
	/*if(bt->rt == NULL){
		bt->rt = newNodo(c);
	}else if(bt->lt == NULL){
		bt->lt = newNodo(c);
	}else{
		addDataTree(bt->rt, c);
	}*/

}

void deleteLastNodo(struct BIN_TREE *bt){

	struct BIN_TREE *buff;

	buff = bt;

	while(buff != NULL){
		printf("%s\n",buff->data);
		buff = buff->rt;
	}

}

int main(int argc, char const *argv[])
{

	struct BIN_TREE *aritmetica;
	char c = '+';

	aritmetica = newNodo('*');
	addDataTree(aritmetica, '-');
	//addDataTree(aritmetica, '3');
	addDataTree(aritmetica, '+');
	addDataTree(aritmetica, '/');
	addDataTree(aritmetica, '+');

	printf("%s\n",aritmetica->lt->data);
	//printf("%i\n",strtol(c,NULL,10));

	printf("\n\n\n");

	deleteLastNodo(aritmetica);

	return 0;
}