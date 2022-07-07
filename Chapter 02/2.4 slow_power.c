#include <stdio.h>

double slow_power(double x, int n) {
	int i;
	double result = 1.0;

	for (i = 0; i < n; i++) {
		result = result * x;
	}
	 
	return (result);
}

void main(void) {
	double a = 2;
	int n = 5;
	double result;

	result = slow_power(a, n);
	printf("%f", result);
}
// output = 32.000000;