#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct chiave_valore {
	char *k;
	int v;
};
typedef struct chiave_valore chiave_valore;

struct nodo {
	chiave_valore coppia;
	struct nodo *succ, *prec;
};
typedef struct nodo nodo;

typedef nodo *lista;

struct dizionario {
	lista *a;
	int m;
};
typedef struct dizionario dizionario;

dizionario dizionario_new(int);
nodo *dizionario_in(dizionario, char*);
dizionario dizionario_set(dizionario, chiave_valore);
dizionario dizionario_del(dizionario, char*);
int dizionario_get(dizionario, char*);
int h(char*, int);
/**********/
lista lista_in0(lista, chiave_valore);
void lista_print(lista);
lista lista_out0(lista);
lista lista_out1(lista);


/*
 * La funzione hash restituisce il valore dello xor bit a bit dei byte
 * della chiave modulo m
 * */
int h(char *s, int m){
	int i, r = 0;
	
	i = 0;
	while( s[i] != '\0'){
		r = r^s[i];
		i += 1;
	}
	
	return r%m;
}

/*
 * Crea un dizionario vuoto composto da m liste di trabocco
 * */
dizionario dizionario_new(int m){
	dizionario d;
	
	d.a = malloc(m*sizeof(lista));
	d.m = m;
	
	return d;
}

/*
 * Verifica se nel dizionario è presente la chiave s.
 * 	Se presente restituisce il puntatore al nodo della lista
 * 	di trabocco contenente la coppia con la chiave specificata.
 * Altrimenti restituisce NULL. 
 * */
nodo *dizionario_in(dizionario d, char *s){
	int i = h(s, d.m);
	nodo *p;
	
	/* ricercare nodo con chiave s in d.a[i] */
	
	p = d.a[i];
	
	while (p != NULL && strcmp(p->coppia.k, s) != 0){
		p = p->succ;
	}
	
	return p;
}


/*
 * Aggiunge un nuovo elemento al dizionario o aggiorna quello relativo
 * se la chiave e' esistente
 * */
dizionario dizionario_set(dizionario d, chiave_valore elem){
	int i = h(elem.k, d.m);
	nodo *p = dizionario_in(d, elem.k);

	if ( p != NULL){
		p->coppia.v = elem.v;
	} else{
		d.a[i] = lista_in0(d.a[i], elem);
	}
	
	return d;
}

/*
 * Prerequisito: Assumiamo che ch è una chiave di d.
 * 
 * Restituisce il valore associato alla chiave
 * */
int dizionario_get(dizionario d, char *ch){
	nodo *p = dizionario_in(d, ch);
	
	return p->coppia.v;
}

/*
 * Elinina dal dizionario l'elemento con la chiave in input
 * */
dizionario dizionario_del(dizionario d, char *ch){
	nodo *q, *p = dizionario_in(d, ch);
	
	if (p == NULL)
		return d;
		
	if (p->prec == NULL){
		/*
		 * p e' il primo nodo della lista
		 * */
		 p = lista_out0(p);
		 d.a[h(ch, d.m)] = p;
	} else {
		q = p->prec;
		q = lista_out1(q);
	}
	
	return d;
}

/*
 * Stampo tutti gli elementi del dizionario
 * */
void dizionario_print(dizionario d){
	int i;
	
	printf("{\n");
	for(i = 0; i < d.m; i++){
		printf("\t%d - ", i);
		lista_print(d.a[i]);
	}
	printf("}\n");
}

/*
 *******************************************************
 *******************************************************
 *******************************************************
 * */


void main(int n, char *args[]){
	dizionario d = dizionario_new(2);
	int i;
	chiave_valore e;
	
	for (i = 1; i < n; i++){
		e.k = args[i];
		e.v = i;
		d = dizionario_set(d, e);
	}
	
	dizionario_print(d);
	
	printf("%d\n", dizionario_get(d, args[1]));
	
	d = dizionario_del(d, args[1]);
	
	dizionario_print(d);
}


/*
 * Inserimento in testa
 * 
 * */
lista lista_in0(lista b, chiave_valore e){
	nodo *p = malloc(sizeof(nodo));
	p->coppia.v = e.v;
	p->coppia.k = malloc((strlen(e.k)+1)*sizeof(char));
	strcpy(p->coppia.k, e.k);
	p->prec = NULL;
	p->succ = b;
	if ( b != NULL )
		b->prec = p;
	b = p;
	return b;
}

void lista_print(lista b){
	nodo *q = b;
	
	while( q != NULL ){
		printf("(%s, %d) ", q->coppia.k, q->coppia.v);
		q = q->succ;
	}
	printf("\n");
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
	
	free(t->coppia.k);
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
	
	free(p->coppia.k);
	free(p);
	
	return b;
}
