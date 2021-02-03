#include <stdio.h>

/*
 * Restituisce -1 se n e' primo, d se d divide n
 * 
 * */
int prime( int n ){
	int d = 5;
	int p; /* = 0 se n non primo, = 1 se n primo */
	
	if (n == 2 || n == 3)
		p = 1;
	else if ( n%2 == 0 ) {
		p = 0;
		d = 2;
	} else if ( n%3 == 0) {
		p = 0;
		d = 3;
	}
	else{		
		while( n%d != 0 && n%(d+2) != 0 && d*d <= n) {
			d = d+6;
		}

		if ( n%d == 0 )
			p = 0;
		else if ( n%(d+2) == 0 ) {
			p = 0;
			d = d+2;
		} else {
			p = 1;
		}		
	}
	
	if ( p == 1 )
		return -1;
	else
		return d;
}

void main(){
	int a;
	
	/*
	 * Generazione della sequenza di numeri primi gemelli compresa tra
	 * 1000 e 2000
	 * */
	
	for(a = 1001; a < 2000; a++){
		if( prime(a) == -1 && prime(a+2) == -1)
			printf("%d, %d\n", a, a+2);
	}
}
