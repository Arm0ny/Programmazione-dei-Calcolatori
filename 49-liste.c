#include "49-liste.h"

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
lista lista_in0(lista b, char k){
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
 * Inserisce nuovo nodo in posizione 1
 * */
lista lista_in1(lista b, char k){
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
lista lista_in(lista b, int pos, char k){
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


/*
 * Cancellazione primo nodo della lista
 * */
lista lista_out0(lista b){
	nodo *t = b;
	
	if (b == NULL)
		return b;
		
	b = b->succ;
	
	/*potrebbe succedere b == NULL*/
	if ( b != NULL )
		b->prec = NULL;
	
	free(t);
	
	return b;
}


/*
 * Cancellazione del nodo in posizione 1
 * */
lista lista_out1(lista b){
	nodo *p;
	
	if ( b == NULL || b->succ == NULL )
		return b;
	
	p = b->succ;
	b->succ = p->succ;
	if ( p->succ != NULL )
		p->succ->prec = b;
	
	free(p);
	
	return b;
}

/*
 * Cancellazione di un nodo in posizione pos della lista
 * */
lista lista_out(lista b, int pos){
	nodo *p;
	
	if (pos < 0)
		return b;
	
	if (pos == 0){
		b = lista_out0(b);
		return b;
	}
	
	p = lista_search(b, pos-1);
	p = lista_out1(p);
	
	return b;
} 

/*
 * Stampa degli elementi della lista
 * */
void lista_print(lista b){
	nodo *q = b;
	
	while( q != NULL ){
		printf("%c, ", q->chiave);
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


