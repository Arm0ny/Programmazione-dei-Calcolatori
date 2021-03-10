#include <stdio.h>

int StrCmp(char*, char*);

void main(){
	char a[] = "aaaaaa";
	char b[] = "aaaaab";
	
	printf("%d\n", StrCmp(a, b) );
}

/*
 * Confronta le stringhe lessicograficamente e restituisce
 * 
 *  0 se x ed y sono uguali;
 * -1 se x precede y
 * +1 se y precede x
 * 
 * */
int StrCmp(char *x, char *y){
	int i = 0;
	int risultato;
	
	while ( x[i] == y[i] && y[i] != '\0' ){
		i++;
	}
	
	if (x[i] == y[i]){
		risultato = 0;
	} else {
		if ( x[i] < y[i] || x[i] == '\0'  ){
			risultato = -1;
		} else if ( x[i] > y[i] || y[i] == '\0' ) {
			risultato = 1;
		}
	}
	
	return risultato;	
}

/*
 *  
 * Con utilizzo del return nelle condizioni
 * 
 * */
int StrCmp0(char *x, char *y){
	int i = 0;
	
	while ( x[i] == y[i] && y[i] != '\0' ){
		i++;
	}
	
	if (x[i] == y[i]){
		return 0;
	}
	
	if ( x[i] < y[i] || x[i] == '\0'  ){
		return -1;
	}
	
	return 1;
}
