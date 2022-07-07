#include <stdio.h>

int factorial_iter(int n) {
	int i, result = 1;
	
	for (i = 1; i <= n; i++) {
		result *= i;
	}

	return (result);
}

int main(void) {
	int a = 6;
	int result = factorial_iter(a);
	printf("%d", result);

	return 0;
}
// output : 720