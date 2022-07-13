#include <stdio.h>

typedef struct studentTag {
	char name[10];
	int age;
	double gpa;
} student;
// student : Declare a struct as a new type

int main(void) {
	student a = { "kim", 24, 3.9 };
	student b = { "park", 24, 4.1 };

	printf("%f\t", a.gpa);
	printf("%d", b.age);

	return 0;
}
// output : 3.900000		24