#include <stdio.h>

// Start with 0 and 1 and go up gradually.
int fib_iter(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;

	int pp = 0;
	int p = 1;
	int result = 0;

	for (int i = 2; i <= n; i++) {
		result = p + pp;
		pp = p;
		p = result;
		printf("%d\n", p);
	}

	return result;
}

int main(void) {
	int n = 10;
	int result = fib_iter(n);

	printf("result : %d", result);
}
// output
// 1
// 2
// 3
// 5
// 8
// 13
// 21
// 34
// 55
// result : 55