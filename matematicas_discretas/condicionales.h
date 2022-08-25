
#define TRUE 1
#define FALSE 0

int negacionU(int v1){
	if (v1)  return FALSE;
	return TRUE;
}

int negacion(int v1, int v2){
	if (v1 == TRUE && v2 == TRUE){
		return FALSE;
	}

	if (v1 == FALSE && v2 == TRUE){
		return FALSE;
	}

	return TRUE;
}

int conjuncion(int v1, int v2){
	if(v1 == TRUE && v2 == TRUE){
		return TRUE;
	}

	return FALSE;
}

int disyuncion(int v1, int v2){

	if(v1 == FALSE && v2 == FALSE){
		return FALSE;
	}

	return TRUE;
}

int condicional(int v1, int v2){
	if(v1 == TRUE && v2 == FALSE){
		return FALSE;
	}

	return TRUE;
}

int bicondicional(int v1, int v2){
	if(v1 == v2){
		return TRUE;
	}

	return FALSE;
}