#include <stdio.h>

// calculation by recursion
int factorial(int n) {
	printf("factorial(%d)\n", n);
	if (n <= 1) return (1);
	else return (n * factorial(n - 1));
}

int main(void) {
	int a = 5;
	int result = factorial(a);
	return 0;
}
/* output : factorial(5)
			   factorial(4)
			   factorial(3)
			   factorial(2)
			   factorial(1)
*/