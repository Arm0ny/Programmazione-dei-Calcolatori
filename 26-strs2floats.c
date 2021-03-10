#include <stdio.h>
#include <stdlib.h>

int Strs2Floats0(char**, int, float**);
int Strs2Floats(char**, int, float**);

/*
 * Costo tempo lineare in n
 * 
 * Costo spazio (a meno di quello utilizzato per input/output) costante
 * 
 * */
int Strs2Floats(char *a[], int n, float **f){
	int i, k ;
	float x;
	float *out_arr = (float*)malloc(n*sizeof(float));

	k = 0;
	/* costo lineare in n*/
	for(i = 0; i < n; i++){
		if (sscanf(a[i], "%f", &x) == 1){
			out_arr[k] = x;
			k++;
		}
	}
	
	out_arr = realloc(out_arr, k*sizeof(float));
	
	*f = out_arr;
	
	return k;
}

void main(int nargs, char *args[]){
	float *f;
	int i, n = Strs2Floats( args+1, nargs-1, &f);

	for(i = 0; i< n; i++){
		printf("%f\n", f[i]);
	}
}


/*
 * Costo tempo lineare in n
 * 
 * Costo spazio (a meno di quello utilizzato per input/output) lineare in n
 * 
 * */
int Strs2Floats0(char *a[], int n, float **f){
	int i, k ;
	float *out_arr;
	float x;
	float *temp_arr = (float*)malloc(n*sizeof(float));

	k = 0;
	/* costo lineare in n*/
	for(i = 0; i < n; i++){
		if (sscanf(a[i], "%f", &x) == 1){
			temp_arr[k] = x;
			k++;
		}
	}
	
	out_arr = (float*)malloc(k*sizeof(float));

	/* costo lineare in n*/
	for(i = 0; i < k; i++){
		out_arr[i] = temp_arr[i]; 
	}
	
	*f = out_arr;
	
	free(temp_arr);
	
	return k;
}
