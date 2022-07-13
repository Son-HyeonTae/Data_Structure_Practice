#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define SIZE 10

// store integer "10", using m(emory)alloc(ation).
// And then, return memory to OS, using free().
int main(void) {
	int* p;
	p = (int*)malloc(SIZE * sizeof(int));

	if (p == NULL) {
		fprintf(stderr, "Not enough memory.");
		exit(1);
	}

	for (int i = 0; i < SIZE; i++)
		p[i] = i;

	for (int i = 0; i < SIZE; i++)
		printf("%d ", p[i]);

	free(p);

	return 0;
}
// output
// 0 1 2 3 4 5 6 7 8 9