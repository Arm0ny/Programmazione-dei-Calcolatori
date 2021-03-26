#include <stdio.h>
#include <stdlib.h>

struct dynarray {
	int *a;
	int n;
	int c;
};
typedef struct dynarray dynarray;

dynarray array_push( dynarray, int );
dynarray array_pop( dynarray );
dynarray array_in( dynarray, int, int );
dynarray array_del( dynarray, int );
dynarray array_new();

dynarray array_new(){
	dynarray A = {NULL, 0, 0};
	return A;
}

dynarray array_push( dynarray A, int k){
	if (A.n == A.c) {
		A.c = 2*A.c + 1;
		A.a = realloc( A.a, A.c*sizeof(int) ); 
	}
	A.a[A.n] = k;
	A.n += 1;
	return A;
}

dynarray array_in( dynarray A, int pos, int k){
	int i;
	
	if ( pos < 0 || pos > A.n )
		return A;
		
	A = array_push(A, k);
	i = A.n-1;
	
	while( i > pos) {
		/* scambiare A.a[i-1] con A.a[i] */
		A.a[i] = A.a[i-1];
		i--;
	}
	A.a[pos] = k;
	return A;
}

dynarray array_pop( dynarray A ){
	A.n -= 1;
	
	if ( A.n < A.c/4 ){
		A.c = A.c/2;
		A.a = realloc(A.a, sizeof(int)*A.c);
	}
	
	return A;
}

dynarray array_del(dynarray A, int pos){
	int i;
	
	if ( pos < 0 || pos >= A.n )
		return A;
	
	i = pos;
	while( i < A.n-1 ){
		A.a[i] = A.a[i+1]; /* l'ultimo 'giro' A.a[n-2] = A.a[n-1] */
		i++;
	}
	
	A = array_pop(A);
	
	return A;
}

void main(){
	dynarray A = array_new();
	int i;
	for( i = 0; i < 16; i++){
		A = array_push(A, i);
		printf("c = %d; n = %d\n", A.c, A.n);
	}
	
	for(i = 0; i < A.n; i++){
		printf("%d, ", A.a[i]);
	}
	printf("\n");
	
	A = array_in(A, 5, 500);
	A = array_in(A, 0, 100);
	A = array_in(A, A.n, 1000);
	
	for(i = 0; i < A.n; i++){
		printf("%d, ", A.a[i]);
	}
	printf("\n");
	
	A = array_del(A, A.n-1);
	A = array_del(A, 0);
	A = array_del(A, 5);
	

	for(i = 0; i < A.n; i++){
		printf("%d, ", A.a[i]);
	}
	printf("\n");

	
	while( A.n > 0 ){
		A = array_pop(A);
		printf("c = %d; n = %d\n", A.c, A.n);
	}
}
