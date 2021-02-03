#include <stdio.h>

void gemelli( int , int  );
int prime( int  );


void main(){
	int n0 = 1000, n1 = 2000;
	
	gemelli(n0, n1);
}


/*
 * Generazione della sequenza di numeri primi gemelli compresa tra
 * n0 e n1
 * */
void gemelli( int n0, int n1 ){
	int a;
	
	for( a = n0; a < n1; a++){
		if( prime(a) == -1 && prime(a+2) == -1)
			printf("%d, %d\n", a, a+2);
	}
	
}

/*
 * Restituisce -1 se n e' primo, d se d divide n
 * 
 * */
int prime( int n ){
	int p; /* = 0 se n non primo, = 1 se n primo */
	int d = 5; /* nel caso p == 0  sara' un divisore di n */

	
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



