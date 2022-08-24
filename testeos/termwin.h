#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))
void putText();
#ifdef __unix__
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))
#endif
#ifdef _WIN32
#include <windows.h>
void gotoxy(short x, short y){
	COORD pos={x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
#endif

void sleep(int r);
void fixSep(int x,int y, int width, int style);
void addColor(int bg, int fg);
void clearColor();
void line(int x, int y, int len, int type, int style, int bg, int fg);
void box(int x, int y, int width, int height, int style, int bg, int fg);
void text(int x, int y, char* msg, int type);
void textbox(int x, int y, int width, int height, int style, char* msg, int bg, int fg);
void erase(int x, int y, int width, int height);
