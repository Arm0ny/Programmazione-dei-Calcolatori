#include <stdio.h>
#include <stdlib.h>

struct punto {
	char nome;
	float x;
	float y;
};
typedef struct punto punto;

struct rettangolo {
	char nome;
	punto nw, se;
};
typedef struct rettangolo rettangolo;

struct array_int {
	int dim_array;
	int *ptr;
};
typedef struct array_int array_int;


rettangolo crea_rettangolo(punto, punto);
array_int crea_array_int(int, int);


void main(){
	punto P[] = {
		'a', 0, 4,
		'b', 12, 3,
		'c', 3, -4,
		'd', 2, 8
	};
	punto p = P[1];
	punto *ptr = P+2;
	rettangolo rect;
	array_int A = crea_array_int(10, 4);
	int i;
	
	p.nome = 'e';
	
	printf("(%c, %f, %f)\n", p.nome, p.x, p.y);
	printf("(%c, %f, %f)\n", (*ptr).nome, ptr->x, ptr->y);
	printf("(%c, %f, %f)\n", P[1].nome, P[1].x, P[1].y);
	
	rect = crea_rettangolo(P[0], P[3]);
	
	printf("%c, %f\n", rect.nome, rect.se.x);
	
	for(i = 0; i < A.dim_array; i++){
		/*
		 * stampare tutti gli interi nell'array ptr di A
		 * */
		printf("%d\n", A.ptr[i]);
	}
}

array_int crea_array_int(int n, int def){
	int i;
	array_int a;
	a.dim_array = n;
	a.ptr = malloc(n*sizeof(int));
	for(i = 0; i < n; i++){
		a.ptr[i] = def;
	}
	return a;
}

rettangolo crea_rettangolo(punto p0, punto p1){
	rettangolo r = {'r', p0, p1};
	return r;
}
