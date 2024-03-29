#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

#define MAXWIDHT 50

#ifdef __unix__

#define iraXY(x,y) printf("\033[%d;%dH", (y), (x));
#define MAIN_COLOR "\33[46m"
#define ERROR_COLOR "\33[41m"
#define MESAGE_COLOR "\33[44m"
#define RESET_COLOR "\33[0m"
#define PAUSE system("pause>>null")


void ponerColor(char *c){
	printf("%s",c);
}

void rellenarColorDeLaConsola(char *c){
	printf("%s",c);
	ponerCuadradoRelleno(MAXWIDHT - MAXWIDHT, MAXWIDHT - MAXWIDHT, MAXWIDHT * 2, MAXWIDHT * 2, ' ');
}

#endif

#ifdef _WIN32
#include <windows.h>

#define MAIN_COLOR BACKGROUND_RED | BACKGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN
#define ERROR_COLOR BACKGROUND_RED | BACKGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_RED
#define MESAGE_COLOR BACKGROUND_RED | BACKGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_GREEN
#define PAUSE system("pause>>null")

//con esta funcion el programador podra ir en X y Y posicion en la consola
void iraXY(short x, short y){
	COORD pos = {x,y};

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);//STD_OUTPUT_HANDLE es la terminal de mi salida de datos 
}



//Colores


void ponerColor(WORD color){
	HANDLE terminal = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(terminal, color);
}

void rellenarColorDeLaConsola(WORD color){
	HANDLE terminal = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screenInfo;
	COORD coordStart = { 0, 0 };
	DWORD nWritten = 0;
	DWORD sizeScreen;

	if (!GetConsoleScreenBufferInfo(terminal, &screenInfo))
	{
	    printf("Error!!!!!\a\a\a\a\a\a");
	    PAUSE;
	    system("exit");
	}

	sizeScreen = screenInfo.dwMaximumWindowSize.X * screenInfo.dwMaximumWindowSize.Y;
	FillConsoleOutputAttribute(terminal, color, sizeScreen, coordStart, &nWritten);
	SetConsoleTextAttribute(terminal, color);
}


#endif

void ponerTextoEnXY(short x, short y,const char *texto){

	iraXY(x,y);
	printf("%s",texto);

}

void ponerTextoCentradoY(short y,const char *texto){
	ponerTextoEnXY( MAXWIDHT - strlen(texto)/ 2, y, texto);
}


void ponerCaracterEnXY(short x, short y, char c){
	iraXY(x,y);
	printf("%c",c);
}

void ponerLineaEnHorizontal(short x, short startY,short limitY, short type){

	int y;
	char c = (char) 205;

	switch(type){
		case 2:
			c = '-';
		break;
		case 3:
			c = '*';
		break;
		default:
			c = (char)  205;
	}

	for (y = startY; y < limitY; y++)
	{
		ponerCaracterEnXY(y, x, c);
	}

}


void ponerLineaEnVertical(short y, short startX,short limitX, short type){

	int x;

	char c = (char) 186;

	switch(type){
		case 2:
			c = '|';
		break;
		case 3:
			c = '*';
		break;
		default:
			c = 186;
	}


	for (x = startX; x < limitX; x++)
	{
		ponerCaracterEnXY(y, x, c);
	}

}

void ponerEsquinas(short xTop, short yTop, short xBottom, short yBottom, short type){

	switch(type){
		case 0:

			ponerCaracterEnXY(xTop,yTop,201);
			ponerCaracterEnXY(xTop,yBottom,200);
			ponerCaracterEnXY(xBottom,yBottom,188);
			ponerCaracterEnXY(xBottom,yTop,187);

			break;
		case 3:

			ponerCaracterEnXY(xTop,yTop,'*');
			ponerCaracterEnXY(xTop,yBottom,'*');
			ponerCaracterEnXY(xBottom,yBottom,'*');
			ponerCaracterEnXY(xBottom,yTop,'*');

			break;
		case 10:

			ponerCaracterEnXY(xTop,yTop,' ');
			ponerCaracterEnXY(xTop,yBottom,' ');
			ponerCaracterEnXY(xBottom,yBottom,' ');
			ponerCaracterEnXY(xBottom,yTop,' ');

			break;
	}

}

void ponerCuadradoEnXY(short xTop, short yTop, short xBottom, short yBottom, short type){
	ponerLineaEnVertical(xTop, yTop, yBottom,type);
	ponerLineaEnVertical(xBottom, yTop, yBottom,type);
	ponerLineaEnHorizontal(yTop, xTop, xBottom, type);
	ponerLineaEnHorizontal(yBottom, xTop, xBottom, type);
	ponerEsquinas(xTop, yTop, xBottom, yBottom, type);

}

void ponerCuadradoConTextoCentradoEnXY(const char *texto, short xTop, short yTop, short xBottom, short yBottom, short type){

	ponerCuadradoEnXY(xTop, yTop, xBottom, yBottom, type);
	ponerTextoCentradoY(yTop, texto);

}

void ponerMenuEnXY(char *menu[], short y, short cantidad){

	system("cls");
	int i;
	int pos = (MAXWIDHT / 2) - strlen(menu[i]);

	for (i = 0; i < cantidad; i++){
		iraXY(pos,y);
		printf("%d %s", i+1,menu[i]);
		y++;
	}

}

void ponerCuadradoRelleno(short xTop, short yTop, short xBottom, short yBottom, char caracter){

	short x,y;

	for (x = xTop; x < xBottom + 1; x++)
	{
		for (y = yTop; y < yBottom + 1; y++)
		{
			ponerCaracterEnXY(x,y,caracter);
		}
	}
}
