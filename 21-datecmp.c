#include <stdio.h>
#include <string.h>

int DateCmp(char*, char*);

void main(){
	char a[1024];
	char b[1024];

	
	printf("Inserisci prima data (ggmmaaaa): ");
	scanf("%s", a);
	printf("Inserisci seconda data (ggmmaaaa): ");
	scanf("%s", b);
	
	printf("%d\n", DateCmp(a,b));
}

/*
 * x ed y sono date della forma ggmmaaaa
 * 
 * return -1 se x precede y;  0 se x ed y uguali; +1 se y precede x
 * 
 * pre-condizione: x ed y rispettano il formato
 * 
 * */
int DateCmp(char *x, char *y){
	int r, i;
	for(i = 4; i>=0; i=i-2){
		r = strcmp(x+i, y+i);
		if ( r < 0 )
			return -1;
		if ( r > 0 )
			return 1;
	}
	return 0;
}
