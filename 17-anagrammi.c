#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void BubbleSort(char*);
int Lunghezza(char*);
char *StrClone(char*);

int Anagrammi(char*, char*);

/*
 * Restituisce 1 se x ed y sono anagrammi; 0 altrimenti
 * */
int Anagrammi(char *x, char *y){
	char *xx, *yy;
	
	if( Lunghezza(x) != Lunghezza(y) )
		return 0;

	xx = StrClone(x);
	yy = StrClone(y);

	BubbleSort(xx);
	BubbleSort(yy);
	
	/*confronta se x e' uguale a y*/
	if ( strcmp(xx, yy) == 0 )
		return 1;
	else
		return 0;
} 

void main(){
	char a[] = "bianca";
	char b[] = "cabina";
	
	if( Anagrammi(a, b) == 1 )
		printf("Le stringhe %s e %s sono anagrammi\n", a, b);
	else
		printf("Le stringhe %s e %s NON sono anagrammi\n", a, b);
}


void BubbleSort(char *x){
	int n = Lunghezza(x);
	int i, j = 0;
	char t;
	int scambi = 1;
	
	while( scambi > 0 ) {
		i = 0;
		scambi = 0;
		while ( i < n-1-j ){
			/*
			 * Eventualmente scambia x[i] con x[i+1]
			 * */
			if ( x[i] > x[i+1] ){
				t = x[i+1];
				x[i+1] = x[i];
				x[i] = t;
				scambi++;
			}
			i++;
		}
		j++;
	}
}

char *StrClone(char *x){
	int n = strlen(x); /*costo n*/
	char *y = (char*)malloc( (n+1)*sizeof(char)); /*costante o lineare*/
	int i;
	
	if (y == NULL)
		return NULL;
		
	for( i = 0; i < n; i++){   /*costo n */
		y[i] = x[i];
	}
	
	y[i] = '\0';
	
	return y;
}


int Lunghezza(char *x){
	int n = 0;
	
	while( x[n] != '\0' )
		n++;
		
	return n;
}
