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

dizionario dizionaro_new(int);
nodo *dizionario_in(dizionario, char*);
int h(char*);

int h(char *s){
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

nodo *dizionario_in(dizionario d, char *s){
	int i = h(s);
	nodo *p;
	
	/* ricercare nodo con chiave s in d.a[i] */
	
	p = d.a[i];
	
	while (p != NULL && strcmp(p->coppia.k, s) != 0){
		p = p->succ;
	}
	
	return p;
}



