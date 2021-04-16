#include <stdio.h>
#include <stdlib.h>

union union_numero {
	char c;
	int i;
	float f;
};
typedef union union_numero union_numero;


struct numero {
	union_numero v;
	char t; /* indica il tipo in v, puo' essere 'c', 'i', 'f'  */
};
typedef struct numero numero;

struct array_gen {
	numero *a; /* va corretta*/
	int n;
};
typedef struct array_gen array_gen;

/*
 * Crea un nuovo array_gen di dimensione n inizializzando tutti gli
 * elementi con l'intero 0
 * */
array_gen array_gen_new(int n){
	array_gen a_gen;
	int i;
	
	a_gen.a = malloc( n*sizeof(numero) );
	
	for(i = 0; i < n; i++){
		a_gen.a[i].v.i = 0;
		a_gen.a[i].t = 'i';
	}
	
	a_gen.n = n;
	
	return a_gen;
}

void array_gen_print(array_gen a_gen){
	int i;
	
	for( i = 0; i < a_gen.n; i++){
		if ( a_gen.a[i].t == 'c' )
			printf("%c\n", a_gen.a[i].v.c);
		else if (a_gen.a[i].t == 'i')
			printf("%d\n", a_gen.a[i].v.i);
		else
			printf("%f\n", a_gen.a[i].v.f);
	}
	
}

void main(){
	array_gen a_gen = array_gen_new(10);
	
	a_gen.a[3].v.f = 3.14;
	a_gen.a[3].t = 'f';
	
	a_gen.a[7].v.i = 17;
	a_gen.a[7].t = 'i';

	a_gen.a[8].v.c = 'a';
	a_gen.a[8].t = 'c';
	
	array_gen_print(a_gen);
}
