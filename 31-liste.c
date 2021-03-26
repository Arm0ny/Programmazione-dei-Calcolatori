#include <stdio.h>
#include <stdlib.h>

struct nodo {
	int chiave;
	struct nodo *succ, *prec;
};
typedef struct nodo nodo;

typedef nodo *lista;


lista lista_vuota();
lista lista_in0(lista, int);
lista lista_in1(lista, int);
lista lista_in(lista, int, int );
void lista_print(lista);
int lista_len(lista);
nodo *lista_search(lista, int);

/*
 * Creazione di una nuova lista
 * 
 * */
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
 * Restituisce il numero di nodi della lista
 * */
int lista_len(lista b){
	nodo *q = b;
	int c = 0;
	
	while( q != NULL ){
		c++;
		q = q->succ;
	}
	return c;
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
 * Inserisce nuovo nodo in posizione 1
 * */
lista lista_in1(lista b, int k){
	nodo *q;
	if (b == NULL)
		return b;
		
	q = malloc(sizeof(nodo));
	q->chiave = k;
	q->prec = b;
	q->succ = b->succ;
	if (b->succ != NULL)
		b->succ->prec = q;
	b->succ = q;
	
	return b;
}


/*
 * Inserimento in posizione pos
 * */
lista lista_in(lista b, int pos, int k){
	nodo *p = lista_search(b, pos-1);
	
	if( pos == 0 ){
		b = lista_in0(b, k);
		return b;
	}
	
	if (p == NULL)
		return b;
		
	p = lista_in1(p, k);
	
	return b;
}

void main(){
	lista a = lista_vuota();
	nodo *p;
	/* nodo *a = lista_vuota()  */
	int i;
	
	for ( i = 0; i < 10; i++)
		a = lista_in0(a, i);
		
	a = lista_in(a, lista_len(a), 100);
		
	lista_print( a );
	
	p = lista_search(a, 15);
	
	if (p != NULL)
		printf("%d\n", p->chiave);
}
