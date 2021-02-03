#include <stdio.h>


void main(){
	int a = 11;
	float x = 3.14;
	int n = 0;
	
	printf("Inserisci (intero,float) ");
	n = scanf("(%d,%f)", &a, &x);
	if ( n == 2)
		printf("a = %d, x = %f, n = %d\n", a, x, n);
}
