#include <stdio.h>

/*
 * Incrementa di 1 il valore puntato dalla variabile p
 * */
void f(int *p ){
	*p = *p+1;
}

void main(){
	int a = 10;

	f(&a);
	
	printf("%d\n", a);
}
