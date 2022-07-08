#include <stdio.h>

// very inefficient
int fib(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	printf("%d", n);
	return (fib(n - 1) + fib(n - 2));
}

int main(void) {
	int n = 6;
	fib(n);
}
// output : 654322324322
// recursion tree
//                                                       6
//                             5                                               4
//                4                        3                     3                    2
//         3            2           2         (1)         2         (1)       (1)      (0)
//     2    (1)    (1)   (0)  (1)   (0)             (1)   (0)
//  (1)  (0)