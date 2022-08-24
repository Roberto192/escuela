#include "termwin.c"

const int WIDTH = 90, HEIGHT = 24, BG = 7, FG = 2, EXT = 1, INTER = 1;
char* popup = "";
void events(){
	int ans;
	scanf("%i", &ans);
	switch ((int)ans) {
		case(1): popup = " FRUTAS"; break;
		case(2): popup = "  PAISES"; break;
		case(3): popup = " DEPORTES"; break;
		case(4):
			popup = "PROGRAMA FUERA"; 
			erase((WIDTH/2)-(46/2), 10, 46, 8), text(WIDTH/2, HEIGHT-1, popup, 1);
			box((WIDTH/2)-((int)strlen(popup)/2)-2, (HEIGHT/2)-1, (int)strlen(popup)+4, 3, 1, BG, FG);
			addColor(BG, 1);
			text(WIDTH/2, HEIGHT/2, popup, 1);
			sleep(2);clearColor();erase(1, 1, WIDTH, HEIGHT);
			gotoxy(0, 0);
			exit(0);
		break;
		default:
			popup = "";
			text(WIDTH/2, HEIGHT-1, "OPCION FUERA DE RANGO", 1);
		break;
	}
}

void drawMenu(){
	textbox((WIDTH/2)-(46/2), 10, 46, 8, INTER, " CATEGORIAS ", BG, FG);
	text((WIDTH+1)/2, 11, "Frutas              [1]", 1);
	text((WIDTH+1)/2, 12, " Paises              [2]", 1);
	text((WIDTH+1)/2, 13, "Deportes            [3]", 1);
	text((WIDTH+1)/2, 14, "Salir               [4]", 1);
	text((WIDTH+1)/2, 16, " Seleccionar Opcion  [ ]", 1);
	gotoxy((WIDTH/2)+10, 16);
}

void prepare(){
	box(1, 1, WIDTH, 24, EXT, BG, FG);
	box(1, 1, WIDTH, 3, EXT, BG, FG);
	fixSep(1, 3, WIDTH, EXT);
	textbox(1, 22, WIDTH, 3, EXT, " MENSAJES ", BG, FG);
	fixSep(1, 22, WIDTH, EXT);
	text((WIDTH+4)/2, 2, "JUEGO DEL AHORCADO", 1);
}

int main(){
	while(1){
		prepare();
		drawMenu();
		events();
		if ((int)strlen(popup) != 0){
			erase((WIDTH/2)-(46/2), 10, 46, 8);
			box((WIDTH/2)-((int)strlen(popup)/2)-1, (HEIGHT/2)-1, (int)strlen(popup)+3, 3, 1, BG, FG);
			addColor(BG, 7);
			text(WIDTH/2, HEIGHT-1, popup, 1);
		}
		text(WIDTH/2, HEIGHT/2, popup, 1);
		text(2, HEIGHT-1, " ", 1);
		sleep(2);
		erase(2, HEIGHT-1, WIDTH-2, 1);
	}
	return 0;
}
