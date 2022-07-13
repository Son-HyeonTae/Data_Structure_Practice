#include <stdio.h>
#define SIZE 6

void get_integers(int list[]) {
	printf("Input 6 integers : ");

	for (int i = 0; i < SIZE; ++i) {
		scanf_s("%d", &list[i]);
	}
}

int cal_sum(int list[]) {
	int sum = 0;
	
	for (int i = 0; i < SIZE; ++i) {
		sum += *(list + i);
	}

	return sum;
}

int main(void) {
	int list[SIZE];

	get_integers(list);
	printf("sum = %d\n", cal_sum(list));

	return 0;
}
// output
// Input 6 integers : 0 1 2 3 4 5
// sum = 15