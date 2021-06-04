#include "49-liste.h"
#include <string.h>
#include <stdio.h>

nodo **multi_find(lista, char, int*);

void main(){
	char b[] = "avvcfdffresasdsrgdahsy";
	lista a = lista_vuota();
	int i = strlen(b)-1;
	nodo **pos;
	int n;
	
	for(; i >= 0; i--){
		a = lista_in0(a, b[i]);
	}
	
	lista_print(a);
	
	pos = multi_find(a, 'z', &n);
	
	for(i = 0; i < n; i++){
		printf("%c\n", pos[i]->chiave);
	}
}

nodo **multi_find(lista a, char c, int *n){
	nodo *p = a;
	nodo **pos = NULL;
	int i;
	
	*n = 0;
	while( p != NULL ){
		if ( p->chiave == c )
			(*n)++;
		p = p->succ;
	}
	
	if ( *n > 0 ){
		pos = malloc((*n)*sizeof(nodo*));
	
		p = a;
		i = 0;
		while( p != NULL ){
			if ( p->chiave == c ){
				pos[i] = p;
				i++;
			}
			p = p->succ;
		}
	}
	
	
	return pos;
}
