#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 3

typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

// return TRUE || FALSE
int is_empty() {
	return (top == -1);
}

int is_full() {
	return (top == MAX_STACK_SIZE-1);
}

void push(element item) {
	if (is_full()) {
		fprintf(stderr, "Stack Overflow Error\n");
		return;
	}
	else {
		stack[++top] = item;
	}
}

element pop() {
	if (is_empty()) {
		fprintf(stderr, "Stack Underflow Error\n");
		exit(1);
	}
	else return stack[top--];
}

// just return the top data, without delete
element peek() {
	if (is_empty()) {
		fprintf(stderr, "Stack Empty Error\n");
		exit(1);
	}
	else return stack[top];
}

int main(void) {
	int p;
	push(1);
	push(2);
	p = peek();
	printf("%d\n", p);
	push(3);
	push(4);
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());

	return 0;
}
// output
// 2
// Stack Overflow Error
// 3
// 2
// 1
// Stack Underflow Error