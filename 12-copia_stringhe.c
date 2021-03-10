#include <stdio.h>

void CopiaStr(char*, char*);
int Lunghezza(char*);
void cpstr(char*, char*);


void main(){
	char a[] = "Stringa lunga";
	char b[] = "Stringa piu' lunga";
	
	CopiaStr(a,  b);
	
	printf("%s, %s\n", a, b);
}


int Lunghezza(char *x){
	int n = 0;
	
	while( x[n] != '\0' )
		n++;
		
	return n;
}

/*
 * Copia la prima stringa (x) nella seconda (y) 
 * 
 * Precondizione: lunghezza x <= lunghezza y
 * */
void cpstr(char *x, char *y){
	int i = 0;
	
	while( x[i] != '\0' ){
		y[i] = x[i];
		i++;
	}
	
	y[i] = x[i];
}


/*
 * Copia la stringa x in y se |x| < |y|; copia y in x altrimenti
 * 
 * */
void CopiaStr(char *x, char *y){
	int lx, ly;
	
	lx = Lunghezza(x);
	ly = Lunghezza(y);
	
	if ( lx < ly ){
		/*
		 * Copia x in y
		 * */
		 cpstr(x, y);
		 
	} else {
		/*
		 * Copia y in x
		 * */
		 cpstr(y, x);
	}
}





