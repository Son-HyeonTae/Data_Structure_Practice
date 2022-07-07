#include <stdio.h>

// It is faster than simple iteration because n of every recursion is minimized by half
double power(double x, int n) {
	if (n == 0) return 1;
	else if ((n % 2) == 0) {
		return power(x * x, n / 2);
	}
	else return x* power(x * x, (n-1) / 2);
}

void main(void) {
	double a = 2;
	int n = 10;

	double result = power(a, n);
	printf("%f", result);
}
// output : 1024