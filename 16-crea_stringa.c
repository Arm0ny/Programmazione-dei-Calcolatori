#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *StrNstars(int);
char *StrClone(char*);


void main(){
	char *a = StrNstars(10);
	char b[] = "Programmazione dei calcolatori";
	char *c;
	
	if (a != NULL)
		printf("%s\n", a);
		
	c = StrClone(b);
	
	b[0] = 'p';
	
	if( c != NULL ){
		printf("%s\n", b);
		printf("%s\n", c);
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


/*
 * INEFFICIENTE
 * */
char *StrClone0(char *x){
	char *y = (char*)malloc( (strlen(x)+1)*sizeof(char)); /*costo n*/
	int i;
	
	if (y == NULL)
		return NULL;
		
	for( i = 0; i < strlen(x); i++){   /*costo n*n*/
		y[i] = x[i];
	}
	
	y[i] = '\0';
	
	return y;
}

char *StrNstars(int n){
	char *t = (char*)malloc((n+1)*sizeof(char));
	int i;
	
	if (t == NULL)
		return NULL;
	
	for(i = 0; i < n; i++){
		t[i] = '*';
	}
	t[n] = '\0';
	
	return t;
}
