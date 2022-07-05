#define MAX_ELEMENTS 100
#include <stdio.h>

int list[MAX_ELEMENTS];

/* 배열과 key값을 받아 key값과 일치하는 값의 인덱스 반환
   없다면 -1 반환 */
int seq_search(int list[], int key)
{
	for (int i = 0; i < MAX_ELEMENTS; i++) {
		if (list[i] == key) {
			return i;
		}
	}
	return -1;
}

int main(void) {
	list[0] = 60;
	list[1] = 70;
	list[2] = 80;
	list[3] = 90;
	list[4] = 100;

	printf("%d", seq_search(list, 80));
}
// output : 2