#include <stdio.h>

float Mediano(float*, int);

void main(){
	float a[] = {50, 0, -532, 1079, -1200, 3.14, 7};
	int n = sizeof(a)/sizeof(float);
	
	float *c;
	
	float b[] = {1,2};
	
	c = b;	
	
	/*printf("%d, %d\n", n, sizeof(float));*/
	
	printf("%f\n", Mediano(a, n) );
}


float Mediano(float *x, int n){
	int i, j;
	int minore_di;
	
	printf( "%d\n", sizeof(x) );
	
	for(i = 0; i < n; i++){
		/*
		 * Contiamo quanti elementi minori di x[i]
		 * */
		minore_di = 0;
		for( j = 0; j < n; j++ ){
			if( x[j] < x[i] )
				minore_di++;
		}
		if (minore_di == n/2)
			return x[i];
	}
}
