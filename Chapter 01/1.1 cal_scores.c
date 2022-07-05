#include <stdio.h>

#define MAX_ELEMENTS 100
int scores[MAX_ELEMENTS];

// 배열에서 가장 큰 수 반환
int get_max_score(int n) {
	int i, largest;
	largest = scores[0];

	for (i = 1; i < n; i++) {
		if (scores[i] > largest) {
		largest = scores[i];
		}
	}
	
	return largest;
}

int main(void) {
	scores[0] = 60;
	scores[1] = 70;
	scores[2] = 80;
	scores[3] = 90;
	scores[4] = 100;

	printf("%d", get_max_score(scores[0]));
	return 0;
}

// output : 100