#include <stdio.h>

void main(int npars, char *pars[]){
	int i, j;
	int w = 3, h = 3, wt;
	
	if( npars >= 2){
		sscanf(pars[1], "%d", &wt);
		if( wt > 0)
			w = wt;
	}
	if ( npars >= 3 )
		sscanf(pars[2], "%d", &h);
	
	for( i = 0; i < h; i++){
		for( j = 0; j < w; j++)
			printf("*");
		printf("\n");
	}

}
