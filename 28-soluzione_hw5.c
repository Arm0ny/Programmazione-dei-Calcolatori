#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct array_int {
	int *a;
	int n;
};
typedef struct array_int array_int;

int vocale(char c){
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
		c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' )
		return 1;
	return 0;
}

array_int posizione_vocali(char *s){
	array_int x;
	int i;
	
	x.a = malloc( strlen(s)*sizeof(int) );
	x.n = 0;
	
	i = 0;
	while ( s[i] != '\0' ){
		if (vocale( s[i] ) == 1 ) {
			x.a[ x.n ] = i;
			x.n = x.n+1;
		}
		i++;
	}
	
	x.a = realloc(x.a, (x.n)*sizeof(int));
	
	return x;
}

void main(int n, char *args[]) {
	array_int pos_vocali;
	int i;
	if (n > 1){
		pos_vocali = posizione_vocali( args[1] );
		for(i = 0; i < pos_vocali.n; i++){
			printf("%d, %c\n", pos_vocali.a[i], args[1][pos_vocali.a[i]] );
		}
	}
}

