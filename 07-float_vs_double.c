#include <stdio.h>

void main(){
	float x = 0.000000000100000000010000000001;
	double y = 0.000000000100000000010000000001;
	
	int b = 3;
	float a = b/2;
	
	printf("a = %f\n", a);
	
	printf("%.50lf\n", x);
	printf("%.50lf\n", y);
	
	printf("********\n");
	scanf("%lf", &x);
	
	printf("%.20f\n", x);
	
}
