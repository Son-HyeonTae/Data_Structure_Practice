#include <stdio.h>

// calculation by recursion
int factorial(int n) {
	if (n <= 1) return (1);
	else return (n * factorial(n - 1));
}

int main(void) {
	int a = 5;
	int result = factorial(a);
	printf("%d", result);
	return 0;
}
// output : 120