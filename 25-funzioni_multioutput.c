#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int f(float **b){
	int i, m = rand()%20;
	float *x = malloc(m*sizeof(float));
	
	for(i = 0; i < m; i++){
		x[i] = (float)rand()/RAND_MAX;
	}

	*b = x;
	
	return m;
}

void main(){
	float *a;
	int i,n;
	
	srand(time(NULL));
	
	n = f(&a);
	
	printf("%d\n", n);
	
	for(i = 0; i < n; i++){
		printf("%f\n", a[i]);
	}
}

