#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *StrCat(char*, char*);


void main(){
	char a[] = "Programmazione";
	char b[] = " dei calcolatori";
	char *c = StrCat(a, b);
	
	if (c != NULL)
		printf("%s\n", c);
}


char *StrCat(char *x, char *y){
	int lx = strlen(x); /* costo lx */
	int ly = strlen(y); /* costo ly */
	char *outstr = (char*)malloc( (lx+ly+1)*sizeof(char) );
	int i;
	
	if (outstr == NULL)
		return NULL;
	
	i = 0;	/*costo lx */
	while( x[i] != '\0'){
			outstr[i] = x[i];
			i++;
	}
	/* i = lx */
	i = 0; /*costo ly */
	while( y[i] != '\0'){
			outstr[lx+i] = y[i];
			i++;
	}
	outstr[lx+i] = '\0'; /* i == ly*/
	
	return outstr;
	
	/*
	 * Costo complessivo, in ordine di grandezza, lx+ly. Ovvero
	 * lineare nella dimensione dell'input.
	 * 
	 * */
}

