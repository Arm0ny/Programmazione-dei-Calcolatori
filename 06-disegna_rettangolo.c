#include <stdio.h>

void DisegnaRettangolo(int, int);


void main(){
	int c = 0, r = 0;
	
	printf("Inserisci (num_righe,num_colonne)\n");
	if (scanf("%d,%d", &r, &c) == 2 )
		DisegnaRettangolo(r, c);
	else
		printf("Errore\n");
}

void DisegnaRettangolo(int r, int c){
	int i, j;
	
	for ( j = 0; j < r; j++){
		for( i = 0; i < c; i++){
			printf("*");
		}
		printf("\n");
	}
}


