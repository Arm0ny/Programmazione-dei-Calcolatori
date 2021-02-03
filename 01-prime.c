#include <stdio.h>


void main(){
	int n = 113217;
	int d = 2;
	
	while( n%d != 0 && d*d <= n) {
		d = d+1;
	}
	
	if ( n%d == 0 )
		printf("%d e' un divisore di %d\n", d, n);
	else
		printf("%d e' primo\n", n);
	
}
