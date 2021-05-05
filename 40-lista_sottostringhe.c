#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "40-liste_stringhe.h"

lista sottostringhe(char*);
lista genera_sottostringhe(char*, int, int, int*, lista);

lista genera_sottostringhe(char *a, int n, int k, int *b, lista lista_ret){
	int i, j;
	char *sotto_a = malloc((n+1)*sizeof(char));
	if (k == n){
		j = 0;
		for(i = 0; i < n; i++){
			if ( b[i] == 1) {
				/*
				 * Costruire la sotto stringa corrispondente a b
				 * */
				 sotto_a[j] = a[i];
				 j++;
			}
		}
		sotto_a[j] = '\0';
		lista_ret = lista_in0(lista_ret, sotto_a);
		/*
		 * printf("%s\n", sotto_a);
		 */
	} else {
		b[k] = 0;
		lista_ret = genera_sottostringhe(a, n, k+1, b, lista_ret);
		b[k] = 1;
		lista_ret = genera_sottostringhe(a, n, k+1, b, lista_ret);
	}
	free(sotto_a);
	return lista_ret;
}

lista sottostringhe(char *a){
	int n = strlen(a);
	int *b = malloc(n*sizeof(int));
	lista lista_ret = lista_vuota();
	lista_ret = genera_sottostringhe(a, n, 0, b, lista_ret);
	free(b);
	return lista_ret;
}

void main(){
	lista a = sottostringhe("uno");
	lista_print(a);
}
