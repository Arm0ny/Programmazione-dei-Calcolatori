#include <stdio.h>
#include <stdlib.h>

struct nodo {
	char *chiave;
	struct nodo *succ, *prec;
};
typedef struct nodo nodo;

typedef nodo *lista;


lista lista_vuota();
lista lista_in0(lista, char*);
lista lista_in1(lista, char*);
lista lista_in(lista, int, char* );
lista lista_out0(lista);
lista lista_out(lista, int);
void lista_print(lista);
int lista_len(lista);
nodo *lista_search(lista, int);
