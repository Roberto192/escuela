#include "termwin.h"

#ifdef __unix__
void addTile(int c, int s){
	char* tiles[] = {"─", "│", "┌", "┐", "└", "┘", "├", "┤", "═", "║", "╔", "╗", "╚", "╝", "╠", "╣"};
	puts(tiles[c+(s*(sizeof tiles / sizeof (char*))/2)]);
}
#endif
#ifdef _WIN32
void addTile(int c, int s){
	int tiles[] = {196, 179, 218, 191, 192, 217, 195, 180, 205, 186, 201, 187, 200, 188, 204, 185};
	putchar(tiles[c+(s*(sizeof tiles / sizeof (int))/2)]);
}
#endif

void sleep(int r){
	int trash;
	for (int i = 0; i < 10000; i++)
		for (int j = 0; j < r*10000; j++)
				trash = 1;
}

void fixSep(int x, int y, int width, int style){
	gotoxy(x, y);
	addTile(6, style);
	gotoxy(width, y);
	addTile(7, style);
}

void addColor(int bg, int fg){
	#ifdef _WIN32
	DWORD dwMode = 0;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hOut != INVALID_HANDLE_VALUE) {
		if (GetConsoleMode(hOut, &dwMode)) {
			SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
		}
	}
	#endif
	switch (fg) {
		case 0: printf("\e[0;30m"); break;
		case 1: printf("\e[0;31m"); break;
		case 2: printf("\e[0;32m"); break;
		case 3: printf("\e[0;33m"); break;
		case 4: printf("\e[0;34m"); break;
		case 5: printf("\e[0;35m"); break;
		case 6: printf("\e[0;36m"); break;
		case 7: printf("\e[0;37m"); break;
	}
	switch (bg) {
		case 0: printf("\e[40m"); break;
		case 1: printf("\e[41m"); break;
		case 2: printf("\e[42m"); break;
		case 3: printf("\e[43m"); break;
		case 4: printf("\e[44m"); break;
		case 5: printf("\e[45m"); break;
		case 6: printf("\e[46m"); break;
		case 7: printf("\e[47m"); break;
	}
}

void clearColor(){
	printf("\033[0;0m");
}

void line(int x, int y, int len, int type, int style, int bg, int fg){
	addColor(bg, fg);
	for(int i = 0; i < len; i++){
		if (type == 0)
			gotoxy(x+i, y), addTile(0, style);
		else
			gotoxy(x, y+i), addTile(1, style);
	}
}

void box(int x, int y, int width, int height, int style, int bg, int fg){
	addColor(bg, fg);
	for (int xx = 1; xx < width-1; xx++)
		for (int yy = 1; yy < height-1; yy++)
			gotoxy((x+xx), (y+yy)), puts(" ");
	char* ch;
	//corner lup
	gotoxy(x, y);addTile(2, style);
	line(x+1, y, width-2, 0, style, bg, fg);//upper line
	//corner rup
	gotoxy(x+width-1, y);addTile(3, style);
	line(x, y+1, height-2, 1, style, bg, fg);//left line
	//corner ldown
	gotoxy(x, y+height-1);addTile(4, style);
	line(x+1, y+height-1, width-2, 0, style, bg, fg);// lower line
	//corner rdown
	gotoxy(x+width-1, y+height-1);addTile(5, style);
	line(x+width-1, y+1, height-2, 1, style, bg, fg);//right line
}

void text(int x, int y, char* msg, int type){
	if (type == 0)
		gotoxy(x, y), puts(msg);
	else
		gotoxy(x-((int)strlen(msg)/2), y), puts(msg);
}

void textbox(int x, int y, int width, int height, int style, char* msg, int bg, int fg){
	addColor(bg, fg);
	box(x, y, width, height, style, bg, fg);
	text((x+(width/2)), y, msg, 1);
	gotoxy(x+width, y+height);
}

void erase(int x, int y, int width, int height){
	for (int xx = 0; xx < width; xx++)
		for (int yy = 0; yy < height; yy++)
			gotoxy(x+xx, y+yy), puts(" ");
}
