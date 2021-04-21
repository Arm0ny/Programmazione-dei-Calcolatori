#include <string.h>

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

dizionario dizionaro_new(int);
nodo *dizionario_in(dizionario, char*);
int h(char*, int);

int h(char *s, int m){
	/*
	 * TODO
	 * */
	return 0
}


dizionario dizionaro_new(int m){
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

dizionario dizionario_add(dizionario d, chiave_valore elem){
	int i = h(elem.k, d.m);
	nodo *p = dizionario_in(d, elem.k);

	if ( p != NULL){
		p->coppia.v = elem.v;
	} else{
		d.a[i] = lista_in0(d.a[i], elem);
	}
	
	return d;
}



