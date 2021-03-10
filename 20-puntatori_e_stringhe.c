#include <stdio.h>

void main(){
	char x[] = "abcdefgh";
	char *y;
	char *z;
	
	y = &(x[2]); /* oppure: y = x+2*/
	z = x+2;
	
	
	printf("%s\n%s\n%s\n", x, y, z);
	
	y[1] = '0';
	z[3] = '1';

	printf("%s\n%s\n%s\n", x, y, z);
	
	y = x;
	
	while( *y != '\0' ){
		printf("%c\n", *y);
		y++;
	}
	
}
