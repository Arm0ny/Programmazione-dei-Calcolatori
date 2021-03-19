#include <stdio.h>
#include <stdlib.h>

struct nodo {
	int chiave;
	struct nodo *succ, *prec;
};
typedef struct nodo nodo;

typedef nodo *lista;

lista lista_vuota(){
	return NULL;
}


void main(){
	lista a = lista_vuota();
	/* nodo *a = lista_vuota()  */
	
	
}
