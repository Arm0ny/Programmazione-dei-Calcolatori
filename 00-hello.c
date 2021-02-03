#include <stdio.h>

void main(){
	int x = -12;
	float y = 10;
	float a = x+y;
	
	if ( x > 0 ){
		printf("x e' maggiore di 0\n");
		

	} else {
		printf("x e' minore-uguale a 0\n");
	}


	while ( x >= 0 && x < 10 ){
		printf("%d\n", x);
		x = x+1;
	}
	
}
