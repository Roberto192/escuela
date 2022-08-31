#include "ventanas.h"

void menu();
void seleccionaUnaOpcion(int opcion);
void ventanasPrincipales();
void ponerAhorcado(int error);
void limpiarVentanaPrincipal();
char *eligirPalabra(int tipo);
int existeLetraEnLaPalabra(char *palabra, char letra);
int game(int tipo);

int main(int argc, char const *argv[])
{
	int opcion;
	//rellenarColorDeLaConsola(MESAGE_COLOR);

	ponerCuadradoRelleno(0,0,119,39, ' ');

	while(TRUE){
		ventanasPrincipales();
		menu();
		iraXY(70, 17);
		scanf(" %c",&opcion);
		limpiarVentanaPrincipal();
		seleccionaUnaOpcion(opcion);
	}

	return 0;
}

void ventanasPrincipales(){

	ponerCuadradoEnXY(0, 0, 119, 29, 2);
	ponerCuadradoConTextoCentradoEnXY(" CATEGORIAS ", 40, 7, 80, 20, 2);
	//ponerColor(ERROR_COLOR);
	ponerCuadradoConTextoCentradoEnXY(" MENSAJES ", 1, 24, 118, 28, 2);
	
}

void menu(){
	char *menu[] = {
		"FRUTAS--------------[1]",
		"PAISES--------------[2]",
		"DEPORTES------------[3]",
		"SALIR---------------[4]",
		"",
		"",
		"",
		"",
		"",
		"SELECCIONA LA OPCION[ ]"

	};

	//ponerColor(MESAGE_COLOR);
	ponerMenuEnXY(menu, 8, 10);

}

void seleccionaUnaOpcion(int opcion){
	
	ponerCuadradoRelleno(2, 26, 118, 27, ' ');

	if (opcion > 48 && opcion < 53 ){

		if(opcion == 49){
			ponerTextoCentradoY(26, "Seleccionaste opcion 1");
			ponerCuadradoRelleno(2, 26, 118, 27, ' ');
			//Sleep(800);
			game(1);
		}

		if(opcion == 50){
			ponerTextoCentradoY(26, "Seleccionaste opcion 2");
			ponerCuadradoRelleno(2, 26, 118, 27, ' ');
			//Sleep(800);
			game(2);
		}

		if (opcion == 51){
			ponerTextoCentradoY(26, "Seleccionaste opcion 3");
			ponerCuadradoRelleno(2, 26, 118, 27, ' ');
			//Sleep(800);
			game(3);
		}

		if (opcion == 52){

			ponerTextoCentradoY(26, "Hasta la proxima");
			//Sleep(1200);
			exit(0);
		}
	}else{
		ponerTextoCentradoY(26, "Ta mal");
	}

}

void ponerAhorcado(int error){

	if (error == 1)
	{
		ponerCaracterEnXY(10, 6, 'O');
	}
	if (error == 2)
	{
		ponerCaracterEnXY(10, 7, '|');
	}
	if (error == 3)
	{
		ponerCaracterEnXY(10, 8, '|');
	}
	if (error == 4)
	{
		ponerCaracterEnXY(10, 9, '|');
	}
	if (error == 5)
	{
		ponerCaracterEnXY(9, 7, '/');
	}
	if (error == 6)
	{
		ponerCaracterEnXY(11, 7, '\\');
	}
	if (error == 7)
	{
		ponerCaracterEnXY(9, 10, '/');
	}
	if (error == 8)
	{
		ponerCaracterEnXY(11, 10, '\\');
	}
	ponerLineaEnVertical(5, 6, 22, 2);
	ponerLineaEnHorizontal(6, 5, 10, 2);
	ponerLineaEnHorizontal(22, 5, 10, 2);
	
}

void limpiarVentanaPrincipal(){
	ponerCuadradoRelleno(1, 1, 118, 22, ' ');
}

char *eligirPalabra(int tipo){

	char *frutas[] = {
		"manzana",
		"pera",
		"platano",
		"melon",
		"sandia"
	};

	char *paises[] = {
		"mexico",
		"argentina",
		"japon",
		"canada",
		"china"
	};

	char *deportes[] = {
		"fuchibol",
		"basketball",
		"voliball",
		"natacion",
		"ciclismo"
	};

	srand(time(NULL));

	if (tipo == 1)
	{
		return frutas[rand() % 5];
	}

	if (tipo == 2)
	{
		return paises[rand() % 5];
	}

	if (tipo == 3)
	{
		return deportes[rand() % 5];
	}

	return "error";
}

int existeLetraEnLaPalabra(char *palabra, char letra){

	for (int i = 0; i < strlen(palabra); i++)
	{
		if (palabra[i] == letra)
		{
			return TRUE;
		}
	}

	return FALSE;

}

int esIgual(char *palabra, char *comparacion){

	int eS = TRUE;

	for (int i = 0; i < strlen(palabra); i++){
		if(palabra[i] != comparacion[i]){
			return FALSE;
		}
	}

	return eS;
}

int game(int tipo){

	char letra;
	char *palabra;
	char *buff;
	short error = 0;
	palabra = eligirPalabra(tipo);
	size_t szt = sizeof(palabra);
	buff = (char *) malloc(szt);

	int ciclo = TRUE;

	while(error <= 8){
		ponerAhorcado(error);
		ponerTextoEnXY(12, 22, " ingrese el caracter --------> [ ] ");
		iraXY(44, 22);
		scanf(" %c",&letra);

		if (esIgual(palabra, buff)){
			limpiarVentanaPrincipal();
			ponerCuadradoEnXY(51, 14, 68, 16, 0);
			ponerTextoCentradoY(15, "Ganaste prro :v");
			//Sleep(1000);
			ponerCuadradoRelleno(2, 26, 118, 27, ' ');
			ponerCuadradoRelleno(51, 14, 68, 16, ' ');
			free(buff);
			return 0;
		}

		if(existeLetraEnLaPalabra(palabra, letra)){
			for (int i = 0; i < strlen(palabra); ++i)
			{
				if(palabra[i] == letra){
					buff[i] = letra;
					ponerCaracterEnXY((60 - strlen(palabra) / 2) + i, 26, buff[i]);
				}
			}
		}else{
			error++;
		}

		if(letra == '9'){
			limpiarVentanaPrincipal();
			free(buff);
			return 0;
		}
	}
	//Sleep(1000);
	limpiarVentanaPrincipal();
	ponerCuadradoEnXY(51, 14, 68, 16, 0);
	ponerTextoCentradoY(15, "Perdiste por nuv");
	ponerTextoCentradoY(26, palabra);
	//Sleep(1000);
	ponerCuadradoRelleno(2, 26, 118, 27, ' ');
	ponerCuadradoRelleno(51, 14, 68, 16, ' ');
	free(buff);

	return 1001;
}

/*
void ponerAhorcado(int Error){

	ponerLineaEnVertical(5, 6, 22, 2);
	ponerLineaEnHorizontal(6, 5, 10, 2);
	ponerLineaEnHorizontal(22, 5, 10, 2);
	
}


char *eligirPalabra(char *palabras[]){

	char *palabra;

	srand(time(NULL));

	palabra = palabras[rand() % 5];

	return palabra;
}

void principal(){
	char *menu[] = {
		"FRUTAS--------------[1]",
		"PAISES--------------[2]",
		"DEPORTES------------[3]",
		"SALIR---------------[4]",
		"",
		"",
		"",
		"",
		"",
		"SELECCIONA LA OPCION[ ]"

	};


	rellenarColorDeLaConsola(BACKGROUND_RED | BACKGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
	
	ponerCuadradoEnXY(0, 0, 119, 29, 0);
		
	ponerCuadradoConTextoCentradoEnXY(" CATEGORIAS ", 40, 7, 80, 20, 0);
	ponerMenuEnXY(menu, 8, 10);

	ponerColor(BACKGROUND_RED | BACKGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_RED);
	ponerCuadradoConTextoCentradoEnXY(" MENSAJES ", 1, 24, 118, 28, 0);
		
	iraXY(70,17);
}

int existeCaracter(char *texto, char caracter, int lenght){

	int i;
	int existe = 0;

	for(i = 0; i < lenght; i++){
		if(texto[i] == caracter){
			existe = 1;
		}
	}

	return 0;
}

void frutasFuncion(){

	char *frutas[] = {
		"manzana",
		"pera",
		"platano",
		"melon",
		"sandia"
	};

	char *palabra, *buff;
	char letra = '\0';
	int i , lenght,errores = 0, time = 0;

	palabra = eligirPalabra(frutas);
	lenght = strlen(palabra);

	size_t sizebuff = sizeof(char [lenght]);
	buff = (char *) malloc(sizebuff);

	for(i = 0; i < lenght + 1; i++){
		buff[i] = '\0';
	}

	do{

		iraXY(5, 3);
		printf("intentos: %i",time);
		ponerAhorcado(errores);
		iraXY(11, 22);

		ponerTextoEnXY(30, 22, "Digite el caracter -> [ ]");
		iraXY(53, 22);
		letra = getchar();

		ponerTextoEnXY(60,22, palabra);

		if(strcmp(palabra, buff) == 0){
			ponerTextoCentradoY(15, "Ganaste!!!");
			time = 22;
			//Sleep(1000);
			ponerCuadradoRelleno(2, 2, 100, 22, ' ');

		}else{
			time++;

			for (i = 0; i < lenght; i++)
			{
				if(palabra[i] == letra){
					ponerCaracterEnXY(11 + i, 22, letra);
					buff[i] = letra;
				}
			}
		}

		//Sleep(300);

	}while(time != 20 && time <= 20);

	free(buff);
	time = 0;

}

void paisesFuncion(){

	char *paises[] = {
		"mexico",
		"argentina",
		"japon",
		"canada",
		"china"
	};

	char *palabra, *buff;
	char letra = '\0';
	int i , lenght,errores = 0, time = 0;

	palabra = eligirPalabra(paises);
	lenght = strlen(palabra);

	size_t sizebuff = sizeof(char [lenght]);
	buff = (char *) malloc(sizebuff);

	for(i = 0; i < lenght + 1; i++){
		buff[i] = '\0';
	}

	do{

		iraXY(5, 3);
		printf("intentos: %i",time);
		ponerAhorcado(errores);
		iraXY(11, 22);

		ponerTextoEnXY(30, 22, "Digite el caracter -> [ ]");
		iraXY(53, 22);
		letra = getchar();

		ponerTextoEnXY(60,22, palabra);

		for (i = 0; i < lenght; i++)
		{
			if(palabra[i] == letra){
				ponerCaracterEnXY(11 + i, 22, letra);
				buff[i] = letra;
			}
		}


		if(strcmp(palabra, buff) == 0){
			ponerTextoCentradoY(15, "Ganaste!!!");
			time = 21;
			//Sleep(1000);
			ponerCuadradoRelleno(2, 2, 100, 22, ' ');

		}else{
			time++;
		}

		//Sleep(300);

	}while(time != 20 && time <= 20);

	free(buff);
	time = 0;

}

void deportesFuncion(){

	char *deportes[] = {
		"fuchibol",
		"basketball",
		"voliball",
		"natacion",
		"ciclismo"
	};
	char *palabra, *buff;
	char letra = '\0';
	int i , lenght,errores = 0, time = 0;

	palabra = eligirPalabra(deportes);
	lenght = strlen(palabra);

	size_t sizebuff = sizeof(char [lenght]);
	buff = (char *) malloc(sizebuff);

	for(i = 0; i < lenght + 1; i++){
		buff[i] = '\0';
	}

	while(time <= 20){

		iraXY(5, 3);
		printf("intentos: %i",time);
		ponerAhorcado(errores);
		iraXY(11, 22);

		ponerTextoEnXY(30, 22, "Digite el caracter -> [ ]");
		iraXY(53, 22);
		letra = getchar();

		ponerTextoEnXY(60,22, palabra);

		for (i = 0; i < lenght; i++)
		{
			if(palabra[i] == letra){
				ponerCaracterEnXY(11 + i, 22, letra);
				buff[i] = letra;
			}
		}


		if(strcmp(palabra, buff) == 0){
			ponerTextoCentradoY(15, "Ganaste!!!");
			time = 21;
			//Sleep(1000);
			ponerCuadradoRelleno(2, 2, 100, 22, ' ');

		}else{
			time++;
		}

		//Sleep(300);

	}

	free(buff);
	time = 0;

}

int main()//int argc, char const *argv[])
{
	
	int ciclos = 0;
	char opcion;

	principal();

	do{

		ciclos = 1;

		scanf("%c",&opcion);


		switch(opcion){
			case '1':
				ponerCuadradoRelleno(2, 25, 117, 27, ' ');
				ponerCuadradoRelleno(40, 7, 80, 20, ' ');
				ponerColor(BACKGROUND_RED | BACKGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
				frutasFuncion();
			break;
			case '2':
				ponerCuadradoRelleno(2, 25, 117, 27, ' ');
				ponerCuadradoRelleno(40, 7, 80, 20, ' ');
				ponerColor(BACKGROUND_RED | BACKGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
				paisesFuncion();
			break;
			case '3':
				//cheat sheet
				ponerCuadradoRelleno(2, 25, 117, 27, ' ');
				ponerCuadradoRelleno(40, 7, 80, 20, ' ');
				ponerColor(BACKGROUND_RED | BACKGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
				deportesFuncion();
			break;
			case '4':
				ciclos = 0;
			break;
			default:

				ponerCuadradoRelleno(2, 2, 100, 22, ' ');
				principal();
				ponerColor(BACKGROUND_RED | BACKGROUND_BLUE | FOREGROUND_RED);
				ponerTextoCentradoY(26, "Opcion fuera de rango digite otra opcion");

				iraXY(70,17);
		}

	}while(ciclos != 0);

	return 0;
}*/