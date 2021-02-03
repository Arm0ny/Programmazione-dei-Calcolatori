#include <stdio.h>

void main(){
	char a[] = "Programmazione C";
	int n = 0;
	
	printf("%s\n", a);
	printf("%c\n", a[0]);
	printf("%d\n", a[0]);
	a[0] = 'p';
	printf("%s\n", a);
	/*
	 * a[5] = '\0';
		printf("%s\n", a);
		*
	*/
	
	while( a[n] != '\0')
		n++;
		
	printf("%d\n", n);
	
	a[5] = a[5] + 1;
	
	printf("%s\n", a);
}
