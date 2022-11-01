typedef struct _nodo{
  int dato;
  struct _nodo *izq;
  struct _nodo *der;
} nodo;

typedef nodo *nodoptr;