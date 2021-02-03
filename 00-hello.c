#include <stdio.h>

void main(){
	int x = 2;
	float y = 10;
	float a = x+y;
	int n = 123;
	
	if ( x > 0 ){
		printf("x e' maggiore di 0\n");
		

	} else {
		printf("x e' minore-uguale a 0\n");
	}


	while ( x >= 0 && x < 10 ){
		printf("Il contenuto di x\n e' %d\n\til contenuto di x+1 e' %d\n-------%d\n \n", x, x+1, n);
		x = x+1;
	}
	
}
