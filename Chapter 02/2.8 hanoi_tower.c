#include <stdio.h>

void hanoi_tower(int n, char from, char tmp, char to) {
	if (n == 1) printf("원판 1을 %c에서 %c로 옮긴다.\n", from, to);
	else {
		printf("     %d\n", n);
		hanoi_tower(n - 1, from, to, tmp);
		printf("원판 %d를 %c에서 %c로 옮긴다.\n", n, from, to);
		hanoi_tower(n - 1,  tmp, from, to);
	}
}

int main(void) {
	hanoi_tower(3, 'A', 'B', 'C');
	return 0;
}

// output
//                              hanoi_tower(3, 'A', 'B', 'C')
//
// h_t(2, 'A', 'C', 'B')                                       h_t(2, 'B', 'A', 'C')
//  
//    h_t(1, 'A', 'B', 'C')                                       h_t(1, 'B', 'C', 'A')
//       printf("move 'A' to 'C'")                                printf("move 'B' to 'A'")
// 
// printf("move 'A' to 'B'")                                printf("move 'B' to 'c'")
// 
//    h_t(1, 'C', 'A', 'B')                                       h_t(1, 'A', 'B', 'C')
//       printf("move 'C' to 'B'")                                printf("move 'A' to 'C'")
// 
//                                 printf("move 'A' to 'C'")