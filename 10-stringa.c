#include <stdio.h>

void RendiMaiuscolo( char *a );


void main(){
	char x[] = "Programmazione C";
	
	RendiMaiuscolo(x);
	
	printf("%s\n", x);
}

void RendiMaiuscolo(char *a){
	int n = 0;
	
	while( a[n] != '\0'){
		/*
		 * Elabora il carattere in posizione n
		 * */
		if ( a[n] >= 'a' && a[n] <= 'z' ){
			/*rendere maiuscolo*/
			a[n] = a[n] + 'A' - 'a';
		}
		n++;
	}	
}
