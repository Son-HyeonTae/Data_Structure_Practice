#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 수행시간 측정
int main(void)
{
	// typedef long clock_t  *clock() 함수 내부
	clock_t start, stop;
	double duration;

	start = clock(); 
	for (int i = 0; i < 1000000; i++);
	stop = clock();
	
	// 우선순위 : (double) > /
	duration = (double) (stop - start) / CLOCKS_PER_SEC;
	printf("수행시간은 %f초입니다.\n", duration);
	return 0;
}
// output : 수행시간은 0.003000초입니다.