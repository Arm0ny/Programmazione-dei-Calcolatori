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

/*
 * Inserimento in testa
 * 
 * */
lista lista_in0(lista b, int k){
	nodo *p = malloc(sizeof(nodo));
	p->chiave = k;
	p->prec = NULL;
	p->succ = b;
	if ( b != NULL )
		b->prec = p;
	b = p;
	return b;
}

/*
 * Stampa degli elementi della lista
 * */
void lista_print(lista b){
	nodo *q = b;
	
	while( q != NULL ){
		printf("%d, ", q->chiave);
		q = q->succ;
	}
	printf("\n");
}

/*
 * Restituisce l'indirizzo del nodo in posizione pos della lista b;
 * NULL se tale posizione non esiste.
 * */
nodo *lista_search(lista b, int pos){
	nodo *q = b;
	int c = 0;
	
	if ( pos < 0 )
		return NULL;
	
	while( q != NULL && c < pos ){
		q = q->succ;
		c++;
	}
	
	return q;
}

/*
 * Inserimento in posizione pos
 * */
lista lista_in(lista b, int pos, int k){
	// TODO
}

void main(){
	lista a = lista_vuota();
	nodo *p;
	/* nodo *a = lista_vuota()  */
	int i;
	
	for ( i = 0; i < 10; i++)
		a = lista_in0(a, i);
		
	lista_print( a );
	
	p = lista_search(a, 15);
	
	if (p != NULL)
		printf("%d\n", p->chiave);
}
