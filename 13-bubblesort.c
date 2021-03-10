#include <stdio.h>

void BubbleSort(char*);
int Lunghezza(char*);

void main(){
	char a[] = "ffjdfbakjfbdkjfnqmebdkjsabjkasbfcdjafbsajbsahvfsajdcbshcdaabc";
	
	BubbleSort(a);
	
	printf("%s\n", a);
}


void BubbleSort(char *x){
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


int Lunghezza(char *x){
	int n = 0;
	
	while( x[n] != '\0' )
		n++;
		
	return n;
}
