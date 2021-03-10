#include <stdio.h>

/*
 * Restituisce la posizione del massimo elemento di un array
 * 
 * */
int MaxFloatArray(float *x, int n){
	int i;
	float m; /* massimo provvisorio*/
	int pos_m; /*posizione massimo provvisorio*/
	
	m = x[0]; pos_m = 0;
	
	for(i = 1; i < n; i++){
		if( x[i] > m ){
			m = x[i];
			pos_m = i;
		}
	}
	
	return pos_m;
}


void main(){
	float x[] = {0.1, 21.12, 90, 3.14, 2.71};
	int n = 5;

	
	printf("Il massimo si trova in posizione %d\n", MaxFloatArray(x, n));
}
