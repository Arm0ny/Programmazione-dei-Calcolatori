#include "31-liste.h"

lista lista_da_array(int*, int);
lista lista_clona(lista);

lista lista_da_array(int *x, int n){
	int i;
	lista a = lista_vuota();
	
	for(i = n-1; i >= 0; i--)
		a = lista_in0(a, x[i]);
		
	return a;
}

lista lista_clona(lista a){
	lista b = lista_vuota();
	nodo *ultimo, *p = a;
	
	while( p != NULL) {
		if (b == NULL){
			b = lista_in0(b, p->chiave);
			ultimo = b;
		} else {
			ultimo = lista_in1(ultimo, p->chiave);
			ultimo = ultimo->succ;
		}
		p = p->succ;
	}
	
	return b;
}


void main(){
	int x[] = {3,1,8,5,4,3,0,1,2,3,8,6,8,2};
	int n = sizeof(x)/sizeof(int);
	lista a = lista_da_array(x, n);
	lista b = lista_clona(a);
	lista_print(b);
}
