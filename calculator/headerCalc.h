
//estructura principal de la pila
typedef struct p{
	
	float number;

	struct p *lt;

}PILA;//PILA tipo de dato pila

struct pila{
	char dato;
	struct pila *p;
}

PILA *createNewPila(float number){

	size_t buff = sizeof(PILA);
	PILA *pila = (PILA *) malloc(buff);

	pila->number = number;
	pila->lt = NULL;

	return pila;

}


PILA *pushPila(PILA *pila, float number){

	PILA *buff;

	buff = createNewPila(number);
	buff->lt = pila;
	pila = buff;

	return pila;

}


PILA *popPila(PILA *pila){
	PILA *buff;
	float numberBuff;

	buff = pila;

	if(!buff){
		return 0;
	}

	pila = buff->lt;
	numberBuff = buff->number;

	free(buff);

	printf("%.2f",numberBuff);
	return pila;

}

/*
//Crea una nuevo espacio en la pila
PILA *CreateNewPila(float n){

	size_t buff = sizeof(PILA);
	PILA *pila = (PILA *) malloc(buff);

	pila->number = n;

	pila->lt = NULL;

	return pila;

}

PILA *addNodoExistent(PILA *pila){

	size_t buff = sizeof(PILA);
	PILA *_pila = (PILA *) malloc(buff);

	_pila->number = pila->number;
	_pila->lt = pila->lt;

	return _pila;
}

void AddElementPila(PILA *pila, float n){

	if (pila == NULL){
		printf("HOLA\n");
		pila = CreateNewPila(n);
	}else{
		if(pila->lt == NULL){
			pila->lt = CreateNewPila(n);
		}else{
			AddElementPila(pila->lt, n);
		}

	}

}

void ReadPila(PILA *pila){

	if(pila == NULL){
		printf("No more data to read\n");
	}else{
		printf("%.2f -> ",pila->number);
	}

	if(pila->lt != NULL){
		ReadPila(pila->lt);
	}else{
		printf("No more data to read\n");
	}

}

PILA *GetLastElementPila(PILA *pila){

	PILA *buff;

	buff = pila;

	if(pila->lt != NULL){
		buff = GetLastElementPila(pila->lt);
	}

	return buff;

}

void DeleteLastElementPila(PILA *pila){

	PILA *buff, *eBuff;

	pila

}*/