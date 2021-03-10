#include <stdio.h>

void BubbleSort0(char*);
void BubbleSort1(char*);
void BubbleSort(char*);
int Lunghezza(char*);


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


void main(){
	char a[] = "aaaaaaabz";
	
	BubbleSort(a);
	
	printf("%s\n", a);
}

/*
 * Costo computazionale e' in ordine di grandezza n*n 
 * */
void BubbleSort0(char *x){
	int n = Lunghezza(x);
	int i, j;
	char t;
	
	for ( j = 0; j < n-1; j++){
		i = 0;
		while ( i < n-1 ){
			/*
			 * Eventualmente scambia x[i] con x[i+1]
			 * */
			if ( x[i] > x[i+1] ){
				t = x[i+1];
				x[i+1] = x[i];
				x[i] = t;
			}
			i++;
		}
	}
}

void BubbleSort1(char *x){
	int n = Lunghezza(x);
	int i, j;
	char t;
	
	for ( j = 0; j < n-1; j++){
		i = 0;
		while ( i < n-1-j ){
			/*
			 * Eventualmente scambia x[i] con x[i+1]
			 * */
			if ( x[i] > x[i+1] ){
				t = x[i+1];
				x[i+1] = x[i];
				x[i] = t;
			}
			i++;
		}
	}
}

int Lunghezza(char *x){
	int n = 0;
	
	while( x[n] != '\0' )
		n++;
		
	return n;
}
