#include <stdio.h>

void somma1( int x[][3], int rows, int cols ){
	int i, j;
	for(i = 0; i < rows; i++){
		for(j = 0; j < cols; j++)
			x[i][j]++;
	}
}

void somma2( int x[], int rows, int cols ){
	int i, j;
	for(i = 0; i < rows; i++){
		for(j = 0; j < cols; j++)
			x[i*cols + j] += 2;
	}
}


void main(){
	int a[2][3] = { {0,1,2}, {3,4,5} };
	int b[2][3] = { 9, 1, 12, 2 };
	int c[2][3] = { {0,1,2}, {3,4,5}, {6,7,8} };
	int x[] = {0,1,2,3};
	int d[][3] = { 0,1,2, 3,4,5, 6,7,8 };
	int e[][3] = { 0,1,2, 3,4,5, 6,7,8,9};
	int f[2][3] = { {0,1,2, 10}, {3,4,5} };
	int g[][3] = { 0,1,2, 3,4,5, 6,7,8 };
	int h[] = { 0,1,2, 3,4,5, 6,7,8 };
	int i, j;
	
	for(i = 0; i < 2; i++){
		for(j = 0; j < 3; j++)
			printf("%d, ", a[i][j]);
		printf("\n");
	}
	printf("----------------------\n");
	for(i = 0; i < 2; i++){
		for(j = 0; j < 3; j++)
			printf("%d, ", b[i][j]);
		printf("\n");
	}
	printf("----------------------\n");
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++)
			printf("%d, ", c[i][j]);
		printf("\n");
	}
	printf("----------------------\n");
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++)
			printf("%d, ", d[i][j]);
		printf("\n");
	}
	printf("----------------------\n");
	for(i = 0; i < 4; i++){
		for(j = 0; j < 3; j++)
			printf("%d, ", e[i][j]);
		printf("\n");
	}
	printf("----------------------\n");
	for(i = 0; i < 2; i++){
		for(j = 0; j < 4; j++)
			printf("%d, ", f[i][j]);
		printf("\n");
	}
	
	int R = 4, C = 3;
	somma1(e, R, C);
	printf("----------------------\n");
	for(i = 0; i < R; i++){
		for(j = 0; j < C; j++)
			printf("%d, ", e[i][j]);
		printf("\n");
	}
	
	somma2(h, 3, 3);
	printf("----------------------\n");
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++)
			printf("%d, ", h[i*3+j]);
		printf("\n");
	}
}
