#include <stdio.h>

void swap(int* px, int* py) {
	int tmp;
	tmp = *px;
	*px = *py;
	*py = tmp;
}

int main(void) {
	int a = 1, b = 2;

	printf("before : a = %d, b = %d\n", a, b);
	swap(&a, &b);
	printf("after : a = %d, b = %d\n", a, b);

	return 0;
}
// output
// before : a = 1, b = 2
// after : a = 2, b = 1