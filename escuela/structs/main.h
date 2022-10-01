#include "ventanas.h"

void menu(){
	ponerCuadradoConTextoCentradoEnXY("MenuUwU", 4, 2, 50, 50, 3);
	ponerTextoCentradoY(5, "[1]      Crear");
	ponerTextoCentradoY(6, "[2]     Buscar");
	ponerTextoCentradoY(7, "[3]    Mostrar");
	ponerTextoCentradoY(8, "[4]  Modificar");
	ponerTextoCentradoY(9, "[5]   Eliminar");
	ponerTextoCentradoY(10,"[6]    Guardar");
	ponerTextoCentradoY(11,"[7]      Salir");
	ponerTextoCentradoY(13,"Ingrese el dato -> [ ]");
	iraXY(34, 13);

}