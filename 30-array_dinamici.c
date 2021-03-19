#include <stdio.h>
#include <stdlib.h>

struct dynarray {
	int *a;
	int n;
	int c;
};
typedef struct dynarray dynarray;

dynarray in_array( dynarray, int );
dynarray new_array();

dynarray new_array(){
	dynarray A = {NULL, 0, 0};
	return A;
}

dynarray in_array( dynarray A, int k){
	if (A.n == A.c) {
		A.c = 2*A.c + 1;
		A.a = realloc( A.a, A.c*sizeof(int) ); 
	}
	A.a[A.n] = k;
	A.n += 1;
	return A;
}

dynarray out_array( dynarray A ){
	A.n -= 1;
	
	if ( A.n < A.c/4 ){
		A.c = A.c/2;
		A.a = realloc(A.a, sizeof(int)*A.c);
	}
	
	return A;
}

void main(){
	dynarray A = new_array();
	int i;
	for( i = 0; i < 16; i++){
		A = in_array(A, i);
		printf("c = %d; n = %d\n", A.c, A.n);
	}
	
	for(i = 0; i < A.n; i++){
		printf("%d, ", A.a[i]);
	}
	printf("\n");
	
	while( A.n > 0 ){
		A = out_array(A);
		printf("c = %d; n = %d\n", A.c, A.n);
	}
}
