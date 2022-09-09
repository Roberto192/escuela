#include <stdio.h>
#include <string.h>


struct tipo
{

	char *__type;
	char *question;
	char *response;
	
}dato1;//Datos que tendra necesitara el juego

dato1->__type = "nombre";
dato1->question = "Su nombre hace referencia a un caballo";
dato1->response = "juan";

int main(int argc, char const *argv[])
{

	printf("%s\n", dato1.__type);
	return 0;
}
